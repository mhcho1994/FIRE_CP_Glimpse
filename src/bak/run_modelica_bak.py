import os
import pandas as pd
from OMPython import OMCSessionZMQ

def simulate_pendulum(model_file="pendulumPID.mo",
                      model_name="pendulumPID",
                      stop_time=10.0,
                      step_size=0.001,
                      out_csv="sim.csv"):
    omc = OMCSessionZMQ()

    # (선택) 표준 라이브러리 로드
    # omc.sendExpression("loadModel(Modelica)")

    model_file_abs = os.path.abspath(model_file)

    # 핵심: OMEdit로 "열기" 말고, OMC API loadFile()로 로드
    ok = omc.sendExpression(f'loadFile("{model_file_abs}")')
    if not ok:
        raise RuntimeError("loadFile failed: " + str(omc.sendExpression("getErrorString()")))

    # 모델 체크
    check = omc.sendExpression(f"checkModel({model_name})")
    err = omc.sendExpression("getErrorString()")
    if err.strip():
        print("OMC messages:\n", err)

    # 시뮬레이션 옵션
    # - OMC는 입력을 '시간함수'로 줄 수 있음: variableFilter, stepSize 등
    sim_cmd = (
        f'simulate({model_name}, '
        f'stopTime={stop_time}, '
        f'method="dassl", '
        f'stepSize={step_size}, '
        f'outputFormat="csv")'
    )
    res = omc.sendExpression(sim_cmd)
    err = omc.sendExpression("getErrorString()")
    if err.strip():
        print("OMC messages:\n", err)

    # res에는 resultFile 등이 들어있음
    result_file = res.get("resultFile", None) if isinstance(res, dict) else None
    if not result_file or not os.path.exists(result_file):
        raise RuntimeError(f"Simulation did not produce result CSV. res={res}")

    # 결과를 원하는 이름으로 복사/저장
    df = pd.read_csv(result_file)
    df.to_csv(out_csv, index=False)
    print(f"Saved: {out_csv}")
    return df

if __name__ == "__main__":
    df = simulate_pendulum(
        model_file="examples/pendulum/pendulumPID.mo",
        model_name="pendulumPID",
        stop_time=10.0,
        step_size=0.01,
        out_csv="pendulumPID_result.csv",
    )
    print(df.columns)
    print(df.head())