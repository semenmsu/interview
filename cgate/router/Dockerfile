FROM cgate-yard:3.0
MAINTAINER Semen Koretskiy <semenmsu@gmail.com>

ADD entrypoint.sh /
RUN chmod +x /entrypoint.sh
RUN chmod -R 777 /cgate
#VOLUME ["/cgate/ini"]
EXPOSE 4001
WORKDIR /
ENTRYPOINT ["/entrypoint.sh"]