#include "minitalk_bonus.h"
void	action(int c, int si_pid, int *tmp)
{
	if (c == '\0')
		{
			write(1, "\n", 1);
			kill(si_pid, SIGUSR1);
			*tmp = 0;
		}
	else
		write(1, &c, 1);
}

void	recieve_sig(int sig, struct __siginfo *info, void *context)
{
	static int	bit;
	static int	c;
	static int	tmp;

	if (tmp != info->si_pid && tmp != 0)
	{
		c = 0;
		tmp = 0;
		bit = 0;
	}
	(void)context;
	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		action(c, info->si_pid, &tmp);
		tmp = info->si_pid;
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	action.__sigaction_u.__sa_sigaction = recieve_sig;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
