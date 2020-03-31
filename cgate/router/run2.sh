docker run -it -p 4001:4001 --name cgate-router-yard \
            -v "$(pwd)/cgate/ini":/cgate/ini -v "$(pwd)/cgate/log":/cgate/log \
            --rm cgate-router-yard:1.0