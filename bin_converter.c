#include "minitalk.h"

char	*binary_converter(char *bin, unsigned int nb, char *base, int i)
{
	if (nb >= 2)
		binary_converter(bin, (nb / 2), base, i - 1);
	bin[i] = base[nb % 2];
	return (bin);
}
char	*ft_bin(char c)
{
	char	*buffer;
	int		i;

	buffer = malloc(9);
	i = -1;
    while (i++ < 9)
        buffer[i] = '0';
    buffer[9] = '\0';
    buffer = binary_converter(buffer, c, "01", 9);
    return (buffer);
}