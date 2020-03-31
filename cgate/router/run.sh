docker run -it --net=host --name cgate-router-yard \
            -v "$(pwd)/cgate/ini":/cgate/ini -v "$(pwd)/cgate/log":/cgate/log \
            --rm cgate-router-yard:2.0