#include "ft_printf.h"

int	ft_putnbr(long long nb, char c)
{
	int		byteswritten;
	char	*str;

	byteswritten = 0;
	if (c == 'u')
	{
		byteswritten += ft_putnbr_base(nb, 'i');
		return (byteswritten);
	}
	if (c == 'd' || c == 'i')
	{
		str = ft_itoa(nb);
		if (str == NULL)
			return (-1);
		byteswritten = ft_putstr(str);
		free(str);
		return (byteswritten);
	}
	return (0);
}
