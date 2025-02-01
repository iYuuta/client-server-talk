#include "minitalk.h"

int	g_server_pid;

static int	check(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (result > (9223372036854775807 - (str[i] - 48)) / 10)
			return (check(sign));
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	recieve_confirmation(int sig, struct __siginfo *info, void *context)
{
	if (sig == SIGUSR1 && info->si_pid == g_server_pid)
	{
		ft_printf("Message received\n");
		exit(0);
	}
	(void)context;
}

void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int					i;
	struct sigaction	info;

	i = -1;
	if (ac != 3)
		return (0);
	info.__sigaction_u.__sa_sigaction = recieve_confirmation;
	sigemptyset(&info.sa_mask);
	info.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &info, NULL);
	g_server_pid = ft_atoi(av[1]);
	while (av[2][++i])
		send_char(g_server_pid, av[2][i]);
	send_char(ft_atoi(av[1]), '\0');
	while (1)
		pause();
	return (0);
}
