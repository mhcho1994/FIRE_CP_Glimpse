FROM continuumio/miniconda3:latest


RUN apt update && \
    apt install -y ca-certificates curl gnupg git
RUN curl -fsSL http://build.openmodelica.org/apt/openmodelica.asc |  gpg --dearmor -o /usr/share/keyrings/openmodelica-keyring.gpg && \ 
    echo "deb [arch=amd64 signed-by=/usr/share/keyrings/openmodelica-keyring.gpg] https://build.openmodelica.org/apt $(cat /etc/os-release | grep "\(UBUNTU\\|DEBIAN\\|VERSION\)_CODENAME" | sort | cut -d= -f 2 | head -1) stable" |  tee /etc/apt/sources.list.d/openmodelica.list && \ 
    apt update && \ 
    apt install -y openmodelica

RUN conda install -c conda-forge pyfmi 
RUN pip3 install pandas OMPython 


RUN useradd -m -s /bin/bash model
RUN chmod 777 /tmp && \ 
    chown -R model:model /tmp 
USER model 

WORKDIR /app
COPY ./*.py ./
COPY ./*.mo ./ 


CMD python3 example.py 
