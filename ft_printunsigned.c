/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:01:44 by abouleau          #+#    #+#             */
/*   Updated: 2021/12/21 14:10:16 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_uitoa(unsigned int n)
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

char	*ft_build_uitoa(char *res, unsigned int len, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		res[0] = '0';
	i = 0;
	while (n != 0)
	{
		res[len - i - 1] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_uitoa(unsigned int n)
{
	char			*res;
	unsigned int	len;

	len = count_uitoa(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (ft_build_uitoa(res, len, n));
}

void	ft_putunsignednbr(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putunsignednbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else
		ft_putchar(nbr + '0');
}

int	ft_printunsigned(unsigned int n)
{
	int		count;
	char	*buffer;

	buffer = ft_uitoa(n);
	count = ft_strlen(buffer);
	free(buffer);
	ft_putunsignednbr(n);
	return (count);
}
