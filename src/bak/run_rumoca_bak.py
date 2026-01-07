import rumoca
from pathlib import Path
import os

repo_root = Path(os.getcwd()).resolve()
model_path=repo_root / "examples" / "bouncingball" / "bouncingball.mo"

result = rumoca.compile(str(model_path))
model_dict = result.to_base_modelica_dict()
a = result.export(str(repo_root / "submodules" / "rumoca" / "examples" / "templates" / "casadi.jinja"))
print(a)