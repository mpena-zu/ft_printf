/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:48 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/14 17:34:15 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	//else if (c == 'p')
	else if (c == 'd')
	{
		ft_putnbr(va_arg(args, int));
		return (ft_len_int(va_arg(args, int)));
	}
	//else if (c == 'i')
	//else if (c == 'u')
	//else if (c == 'x')
	//else if (c == 'X')
	else if (c == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	va_list	args;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len = len + conversion(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int res_printf;
	int res_ft_printf;
	
	res_printf = printf("%d\n", -1);
	res_ft_printf = ft_printf("%d\n", -1);
	printf("printf = %i\n", res_printf);
	printf("ft_printf = %i\n", res_ft_printf);
	return (0);
}
