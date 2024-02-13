#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/event.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENT 10
#define CHATDATA 1024

#define INVALID_SOCK -1

int list_c[MAX_CLIENT];

char escape[] = "exit";
char greeting[] = "Welcome to chatting room\n";
char CODE200[] = "Sorry No More Connection\n";

int pushClient(int c_sock);
int popClient(int s);

void error_handling(char *s)
{
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int main(int ac, char **av)
{
    int c_sock, s_sock;
    struct sockaddr_in s_addr, c_addr;
    socklen_t len;
    char chatData[CHATDATA];
    int res;

    if (ac < 2)
    {
        error_handling("./p <port>");
    }

    s_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(atoi(av[1]));

    if (bind(s_sock, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1)
    {
        error_handling("bind err");
    }

    if (listen(s_sock, MAX_CLIENT) == -1)
    {
        error_handling("listen err");
    }

    fcntl(s_sock, F_SETFL, O_NONBLOCK);

    for (int i = 0; i < MAX_CLIENT; i++)
    {
        list_c[i] = INVALID_SOCK;
    }

    int kq, nev;
    struct kevent changelist[MAX_CLIENT + 1];
    struct kevent eventlist[MAX_CLIENT + 1];
    struct timespec timeout = {0, 0};

    if ((kq = kqueue()) == -1)
    {
        error_handling("kqueue err");
    }

    EV_SET(&changelist[0], s_sock, EVFILT_READ, EV_ADD, 0, 0, NULL);

    while (1)
    {
        nev = kevent(kq, changelist, 1, eventlist, MAX_CLIENT + 1, &timeout);
        if (nev == -1)
        {
            error_handling("kevent err");
        }

        for (int i = 0; i < nev; i++)
        {
            if (eventlist[i].ident == s_sock)
            {
                len = sizeof(c_addr);
                c_sock = accept(s_sock, (struct sockaddr *)&c_addr, &len);
                if (c_sock > 0)
                {
                    res = pushClient(c_sock);
                    if (res < 0)
                    {
                        write(c_sock, CODE200, strlen(CODE200));
                        close(c_sock);
                    }
                    else
                    {
                        write(c_sock, greeting, strlen(greeting));

                        EV_SET(&changelist[res + 1], c_sock, EVFILT_READ, EV_ADD, 0, 0, NULL);
                    }
                }
            }
            else
            {
                int client_index = -1;
                for (int j = 0; j < MAX_CLIENT; j++)
                {
                    if (list_c[j] == eventlist[i].ident)
                    {
                        client_index = j;
                        break;
                    }
                }

                if (client_index != -1)
                {
                    memset(chatData, 0, sizeof(chatData));
                    int n = read(list_c[client_index], chatData, sizeof(chatData));
                    if (n > 0)
                    {
                        for (int j = 0; j < MAX_CLIENT; j++)
                        {
                            if (list_c[j] != INVALID_SOCK)
                            {
                                write(list_c[j], chatData, n);
                            }
                        }

                        if (strstr(chatData, escape) != NULL)
                        {
                            EV_SET(&changelist[client_index + 1], list_c[client_index], EVFILT_READ, EV_DELETE, 0, 0,
                                   NULL);
                            popClient(list_c[client_index]);
                            break;
                        }
                    }
                }
            }
        }
    }
    close(kq);
}

int pushClient(int c_sock)
{
    int i;

    for (i = 0; i < MAX_CLIENT; i++)
    {
        if (list_c[i] == INVALID_SOCK)
        {
            list_c[i] = c_sock;
            return i;
        }
    }

    return -1;
}

int popClient(int s)
{
    int i;

    close(s);

    for (i = 0; i < MAX_CLIENT; i++)
    {
        if (s == list_c[i])
        {
            list_c[i] = INVALID_SOCK;
            break;
        }
    }

    return 0;
}
