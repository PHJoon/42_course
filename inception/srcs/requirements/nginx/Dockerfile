FROM debian:bullseye

RUN apt-get update -y && apt-get install -y nginx openssl dumb-init \
    && apt-get clean && rm -rf /var/lib/apt/lists/*
COPY ./conf/server.conf /etc/nginx/sites-available/default

COPY ./tools/start_nginx.sh /home/

RUN chmod -R 644 /etc/nginx/sites-available/default

RUN chmod +x /home/start_nginx.sh

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "/home/start_nginx.sh"]
