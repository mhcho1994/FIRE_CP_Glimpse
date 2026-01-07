from pathlib import Path
import os
from src.translator.casadi_translator import make_default_translator, CasadiTranslateRequest, generate_c_code_from_generated_model

repo_root = Path(os.getcwd()).resolve()
tr = make_default_translator(repo_root)

res = tr.translate(CasadiTranslateRequest(
    model_path=repo_root/"examples"/"bouncingball"/"bouncingball.mo",
    run_name="bouncingball",
))

# CasADi -> C
c_path = generate_c_code_from_generated_model(
    res.casadi_py_path,
    res.out_dir/"c_codegen",
    integrator=None,  # or "cvodes"
)
print("C generated:", c_path)