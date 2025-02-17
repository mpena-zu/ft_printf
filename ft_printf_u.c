#include "ft_printf.h"

static int	ft_len_unsigned_int(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_printf_u(unsigned int n)
{
	char	a;
	int		len;

	len = ft_len_unsigned_int(n);
	if (n >= 10)
		ft_printf_u(n / 10);
	a = (n % 10) + '0';
	write(1, &a, 1);
	return (len);
}