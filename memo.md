# get rumoca as submodule
anaconda
python -m pip install -e submodules/rumoca/bindings/python
poetry
[tool.poetry.dependencies]
rumoca = { path = "submodules/rumoca", develop = true }


need to build rumoca for exporting to casadi format