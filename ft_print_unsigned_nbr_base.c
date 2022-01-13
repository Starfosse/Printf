/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:51:36 by abouleau          #+#    #+#             */
/*   Updated: 2021/12/21 14:51:38 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr_base(unsigned long int nb, char *base)
{
	if (nb >= 16)
	{
		ft_put_unsigned_nbr_base(nb / 16, base);
		ft_put_unsigned_nbr_base(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_count_ubase(unsigned long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		count++;
		nb = nb / 16;
	}
	return (count);
}

int	ft_print_unsignbr_base(unsigned long int nb)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	count = ft_count_ubase(nb);
	ft_put_unsigned_nbr_base(nb, base);
	return (count);
}
