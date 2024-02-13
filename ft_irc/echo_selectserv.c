#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 100

#define WELCOME ":irc.local 001 hj :Welcome to the Localnet IRC Network hj!root@127.0.0.1\n\
:irc.local 002 hj :Your host is irc.local, running version InspIRCd-3\n\
:irc.local 003 hj :This server was created 00:34:38 Feb 13 2024\n\
:irc.local 004 hj irc.local InspIRCd-3 iosw biklmnopstv :bklov\n\
:irc.local 005 hj AWAYLEN=200 CASEMAPPING=rfc1459 CHANLIMIT=#:20 CHANMODES=b,k,l,imnpst CHANNELLEN=64 CHANTYPES=# ELIST=CMNTU HOSTLEN=64 KEYLEN=32 KICKLEN=255 LINELEN=512 MAXLIST=b:100 :are supported by this server\n\
:irc.local 005 hj MAXTARGETS=20 MODES=20 NETWORK=Localnet NICKLEN=30 PREFIX=(ov)@+ SAFELIST STATUSMSG=@+ TOPICLEN=307 USERLEN=10 WHOX :are supported by this server\n\
:irc.local 251 hj :There are 0 users and 0 invisible on 1 servers\n\
:irc.local 253 hj 1 :unknown connections\n\
:irc.local 254 hj 0 :channels formed\n\
:irc.local 255 hj :I have 0 clients and 0 servers\n\
:irc.local 265 hj :Current local users: 0  Max: 0\n\
:irc.local 266 hj :Current global users: 0  Max: 0\n\
:irc.local 375 hj :irc.local message of the day\n\
:irc.local 372 hj :- **************************************************\n\
:irc.local 372 hj :- *             H    E    L    L    O              *\n\
:irc.local 372 hj :- *  This is a private irc server. Please contact  *\n\
:irc.local 372 hj :- *  the admin of the server for any questions or  *\n\
:irc.local 372 hj :- *  issues.                                       *\n\
:irc.local 372 hj :- **************************************************\n\
:irc.local 372 hj :- *  The software was provided as a package of     *\n\
:irc.local 372 hj :- *  Debian GNU/Linux <https://www.debian.org/>.   *\n\
:irc.local 372 hj :- *  However, Debian has no control over this      *\n\
:irc.local 372 hj :- *  server.                                       *\n\
:irc.local 372 hj :- **************************************************\n\
:irc.local 372 hj :- (The sysadmin possibly wants to edit </etc/inspircd/inspircd.motd>)\n\
:irc.local 376 hj :End of message of the day.\n\
:irc.local PRIVMSG hi :*** Raw I/O logging is enabled on this server. All messages, passwords, and commands are being recorded."

#define MODE ":hi!root@127.0.0.1 MODE hi :+i"
#define PONG ":irc.local PONG irc.local :irc.local"


void error_handling(char *message) {
    fputs(message, stderr);
    fputs("\n", stderr);
    exit(1);
}

int main(int ac, char **av) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    struct timeval timeout;
    fd_set reads, cpy_reads;

    socklen_t adr_sz;
    int fd_max, str_len, fd_num, i;
    char buf[BUF_SIZE];
    
    if (ac != 2) {
        error_handling("./p <port>");
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(av[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1) {
        error_handling("bind err");
    }

    if (listen(serv_sock, 5) == -1) {
        error_handling("listen err");
    }


    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);
    fd_max = serv_sock;

    int flag = 0;

    while (1) {
        cpy_reads = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 5000;

        if ((fd_num = select(fd_max + 1, &cpy_reads, 0, 0, &timeout)) == -1) {
            break;
        }
        if (fd_num == 0) {
            continue;
        }

        for (i = 0; i < fd_max + 1; i++) {
            if (FD_ISSET(i, &cpy_reads)) {
                if (i == serv_sock) {
                    adr_sz = sizeof(clnt_adr);
                    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
                    FD_SET(clnt_sock, &reads);

                    if (fd_max < clnt_sock) {
                        fd_max = clnt_sock;
                    }
                    printf("connected client: %d\n", clnt_sock);
                } else {
                    str_len = read(i, buf, BUF_SIZE);
                    if (str_len == 0) {
                        FD_CLR(i, &reads);
                        close(i);
                        printf("closed client: %d\n", i);
                    } else {
                        write(1, buf, str_len);
                        if (!flag) {
                            write(i, WELCOME, strlen(WELCOME));
                            flag = 1;
                        }
                        if (!strcmp(buf, "MODE hi +i")) {
                            write(i, MODE, strlen(MODE));
                        } else if (!strcmp(buf, "PING irc.local")) {
                            write(i, PONG, strlen(PONG));
                        }

                        // write(i, buf, str_len);
                    }
                }
            }
        }
    }
    close(serv_sock);
    return 0;
}
