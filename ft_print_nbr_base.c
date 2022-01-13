/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:52:07 by abouleau          #+#    #+#             */
/*   Updated: 2021/12/21 14:54:18 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nb, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_count_base(unsigned int nb)
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

int	ft_print_nbr_base(unsigned int nb, char *base)
{
	int	count;

	count = ft_count_base(nb);
	ft_putnbr_base(nb, base);
	return (count);
}
