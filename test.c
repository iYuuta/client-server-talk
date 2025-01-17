#include "minitalk.h"

int main()
{
	int a = 5;

	write(1, &a, 1);
	write(1, "\n", 1);
}