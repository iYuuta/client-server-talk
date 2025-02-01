#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
char	*ft_itoa(long long n);
int		ft_putstr(char *str);
int		ft_putnbr(long long nb, char c);
int		ft_putnbr_base(long long nb, char format);
int		base_hex(unsigned long nb, char *base);
int		ft_putptr(void *ptr);
int		base_dec(unsigned int nb, char *base);

#endif
