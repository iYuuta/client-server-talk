#include "ft_printf.h"

int	ft_putnbr_base(long long nb, char format)
{
	int	count;

	count = 0;
	if (!format)
		return (0);
	if (nb == 0)
		return (write(1, "0", 1));
	if (format == 'X')
		count += base_hex(nb, "0123456789ABCDEF");
	else if (format == 'x')
		count += base_hex(nb, "0123456789abcdef");
	else if (format == 'i')
		count += base_dec(nb, "0123456789");
	return (count);
}
