#include "minitalk.h"

int	write_utf8(unsigned char *c, int count)
{
	int	i;

	i = 0;
	while (i < count)
		write(1, &c[i++], 1);
	return (1);
}

int	unicode_handler(unsigned char c, int reset)
{
	static unsigned char	buf[4];
	static int				count;

	if (reset)
		return (count = 0, 0);
	if (c <= 127)
		return (write(1, &c, 1), count = 0, 1);
	buf[count++] = c;
	if ((buf[0] & 0b11100000) == 0b11000000 && count == 2)
		return (write_utf8(buf, count), count = 0, 1);
	if ((buf[0] & 0b11110000) == 0b11100000 && count == 3)
		return (write_utf8(buf, count), count = 0, 1);
	if ((buf[0] & 0b11111000) == 0b11110000 && count == 4)
		return (write_utf8(buf, count), count = 0, 1);
	return (0);
}

void	action(int c, int *tmp, int si_pid, int reset)
{
	if (reset)
	{
		unicode_handler(0, 1);
		return ;
	}
	if (c == '\0')
	{
		write(1, "\n", 1);
		kill(si_pid, SIGUSR1);
		*tmp = 0;
	}
	else
		unicode_handler(c, 0);
}

void	recieve_sig(int sig, struct __siginfo *info, void *context)
{
	static int	bit;
	static int	c;
	static int	tmp;

	(void)context;
	if (tmp != info->si_pid)
	{
		c = 0;
		bit = 0;
		tmp = info->si_pid;
		action(0, &tmp, 0, 1);
	}
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		action(c, &tmp, info->si_pid, 0);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.__sigaction_u.__sa_sigaction = recieve_sig;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
