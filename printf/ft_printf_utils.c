#include "ft_printf.h"

int	size(long n)
{
	size_t	s;

	s = 0;
	if (n < 0)
	{
		n = -n;
		s++;
	}
	if (n == 0)
		s++;
	while (n > 0)
	{
		n = n / 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(long long nb)
{
	int		i;
	int		s;
	char	*str;

	i = 0;
	s = size(nb);
	str = (char *)malloc((s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[s--] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		str[i++] = '-';
	}
	while (s >= i)
	{
		str[s] = (nb % 10) + 48;
		nb /= 10;
		s--;
	}
	return (str);
}

int	base_hex(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += base_hex((nb / 16), base);
	}
	count += write(1, &base[nb % 16], 1);
	return (count);
}

int	base_dec(unsigned int nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		count += base_dec((nb / 10), base);
	}
	count += write(1, &base[nb % 10], 1);
	return (count);
}
