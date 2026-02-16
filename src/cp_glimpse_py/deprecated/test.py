from .fmu_runner import FMI2CSRunner
from fmpy.fmi2 import fmi2Discard

with FMI2CSRunner(fmu_path=art_rover.fmu_path, instance_name="rover",
                  start_time=0.0, stop_time=sim.get("tf"), debug_logging=True) as rover:

    t = 0.0
    dt = sim["dt"]

    # 입력 이름 확인 가능
    print([v.name for v in rover.io["inputs"]])
    print([v.name for v in rover.io["outputs"]])

    for k in range(int(sim["tf"]/dt)):
        # rover.set_real("thr", thr_cmd) 같은 식으로 input set
        status = rover.step(t, dt)
        if status == fmi2Discard:
            # 보통 step을 더 줄여보거나, 이벤트 관련 설정을 바꿔야 함
            raise RuntimeError(f"FMU discarded step at t={t}; try smaller dt or check events.")
        t += dt