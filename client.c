#include "minitalk.h"

void    send_char(pid_t server_pid, char c)
{
    char    *binary;
    int     i;

    binary = ft_bin(c);
    i = ft_strlen(binary);
    if (!binary)
        return ;
    while (i >= 0)
    {
        if (binary[i--] == '0')
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        usleep(100);
    }
    free(binary);
}

int main(int ac, char **av)
{
    int i;

    i = -1;
    if (ac != 3)
        return (0);
    while (av[2][++i])
        send_char(ft_atoi(av[1]), av[2][i]);
}
