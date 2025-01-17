#include "minitalk_bonus.h"

void	recieve_sig(int sig, struct __siginfo *info, void *context)
{
	static int	bit;
	static int	c;

	(void)context;
	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if ((c < 32 || c == 127) || (c >= 0x80 && c <= 0x9F) || (c >= 0xA0 && c <= 0xBF))
    		c = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
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
