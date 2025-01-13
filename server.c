#include "minitalk.h"

void	recieve_sig(int sig)
{
	static int	bit;
	static int	c;

	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, recieve_sig);
	signal(SIGUSR2, recieve_sig);
	while (1)
	{
		pause();
	}
	return (0);
}
