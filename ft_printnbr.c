/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:06:50 by abouleau          #+#    #+#             */
/*   Updated: 2021/12/21 14:14:40 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_itoa(int n)
{
	unsigned int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_build_itoa(char *res, unsigned int len, int n)
{
	unsigned int	i;
	int				negativ;

	negativ = 0;
	if (n < 0)
		negativ = 1;
	if (n == 0)
		res[0] = '0';
	i = 0;
	while (n != 0)
	{
		if (negativ)
			res[len - i - 1] = '0' - (n % 10);
		else
			res[len - i - 1] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	if (negativ)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{	
	char			*res;
	unsigned int	len;

	len = count_itoa(n);
	if (n < 0)
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (ft_build_itoa(res, len, n));
}

void	ft_putnbr(int n)
{
	int	nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		nbr = (nbr * -1);
		ft_putchar('-');
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else
		ft_putchar(nbr + '0');
}

int	ft_printnbr(int n)
{
	int		count;
	char	*buffer;

	buffer = ft_itoa(n);
	count = ft_strlen(buffer);
	free(buffer);
	ft_putnbr(n);
	return (count);
}
