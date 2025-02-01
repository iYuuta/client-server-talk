#include "ft_printf.h"

int	print(va_list args, char format)
{
	int	chars_written;

	chars_written = 0;
	if (format == 'c')
		chars_written += ft_putchar(va_arg(args, int));
	else if (format == 's')
		chars_written += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		chars_written += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'u' || format == 'i')
		chars_written += ft_putnbr(va_arg(args, int), format);
	else if (format == 'x' || format == 'X')
		chars_written += ft_putnbr_base(va_arg(args, unsigned int), format);
	else
		chars_written += write(1, &format, 1);
	return (chars_written);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_written;
	int		count;

	va_start(args, format);
	chars_written = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(++format))
			count = print(args, *format);
		else
			count = write(1, format, 1);
		if (count == -1)
			return (-1);
		chars_written += count;
		format++;
	}
	va_end(args);
	return (chars_written);
}
