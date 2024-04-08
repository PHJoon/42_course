#!/bin/bash

if [ ! -f wp-cli.phar ]; then
    wget --no-verbose https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
fi

if [ ! -f /usr/local/bin/wp ]; then
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

if [ ! wp core is-installed ]; then
    wp --allow-root core download --locale=ko_KR
    wp --allow-root config create --dbname=$MARIADB_DATABASE --dbuser=$MARIADB_USER --dbpass=$MARIADB_USER_PASSWORD --dbhost=$MARIADB_HOST 
    wp --allow-root core install --url=$WORDPRESS_URL --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL
    wp --allow-root user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=author --user_pass=$WORDPRESS_USER_PASSWORD
fi

service php7.4-fpm start

service php7.4-fpm stop

exec php-fpm7.4 -F