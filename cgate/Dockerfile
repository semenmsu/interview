FROM cgate-yard:3.0
MAINTAINER Semen Koretskiy <semenmsu@gmail.com>

RUN apt-get install -y vim
ADD .  /gateways
ADD entrypoint.sh /entrypoint.sh 
RUN /bin/bash -c "cd /cgate && source ./var_exports.sh && cd /gateways && make"
WORKDIR /
RUN chmod +x entrypoint.sh
RUN chmod -R 777 /gateways && chmod -R 777 entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["common"]
