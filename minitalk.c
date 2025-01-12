#include "minitalk.h"

int bit_count = 0;
void recieve_sig(int sig)
{
	static char c;

	if (sig == SIGUSR1)
		printf("0");
	else if (sig == SIGUSR2)
		printf("1");
	bit_count++;
	if (bit_count == 8)
    {
       	printf("a");
    	bit_count = 0;
    }
}
int main()
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