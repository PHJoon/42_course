FROM debian:bullseye

RUN apt-get update -y && apt-get install -y php7.4-fpm php-mysql php-mbstring wget sendmail curl dumb-init \ 
    && apt-get clean && rm -rf /var/lib/apt/lists/*

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./tools/set_wordpress.sh /home/

RUN chmod +x /home/set_wordpress.sh

RUN mkdir -p /var/www/html/ && chown -R www-data:www-data /var/www/html/ 

WORKDIR /var/www/html/

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "/home/set_wordpress.sh" ]
