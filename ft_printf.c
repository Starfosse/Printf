/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:35:27 by abouleau          #+#    #+#             */
/*   Updated: 2021/12/21 14:49:11 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		count = 6;
		return (count);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	ft_select_format(va_list variable, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		ft_putchar(va_arg(variable, int));
	if (c == 's')
		count += ft_putstr(va_arg(variable, char *));
	if (c == 'd' || c == 'i')
		count += ft_printnbr(va_arg(variable, int));
	if (c == 'u')
		count += ft_printunsigned(va_arg(variable, int));
	if (c == 'x')
		count += ft_print_nbr_base(va_arg(variable, int), "0123456789abcdef");
	if (c == 'X')
		count += ft_print_nbr_base(va_arg(variable, int), "0123456789ABCDEF");
	if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_print_unsignbr_base(va_arg(variable, unsigned long int));
	}
	if (c == '%')
		ft_putchar('%');
	if (c == '%' || c == 'c')
		count = 1;
	return (count);
}

int	ft_printf(char const *str, ...)
{	
	va_list	variable;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(variable, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_select_format(variable, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(variable);
	return (count);
}
