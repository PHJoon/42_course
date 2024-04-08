FROM debian:bullseye

RUN apt-get update -y && apt-get install -y nginx openssl

COPY ./conf/server.conf /etc/nginx/sites-available/default

RUN chmod -R 644 /etc/nginx/sites-available/default

RUN openssl req -newkey rsa:4096 -nodes -x509 -days 365 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=KR/ST=Seoul/L=Soeul/O=42/OU=hyungjpa/CN=localhost" 

RUN chmod 600 /etc/ssl/certs/nginx-selfsigned.crt /etc/ssl/private/nginx-selfsigned.key

ENTRYPOINT [ "nginx", "-g", "daemon off;"]
