#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	p;

	count = 0;
	p = (unsigned long)ptr;
	count += write(1, "0x", 2);
	if (p != 0)
		count += base_hex(p, "0123456789abcdef");
	else
		count += write(1, "0", 1);
	return (count);
}
