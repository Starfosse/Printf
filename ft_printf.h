/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:54:28 by abouleau          #+#    #+#             */
/*   Updated: 2021/12/21 14:55:52 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <assert.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		count_itoa(int n);
void	ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_build_itoa(char *res, unsigned int len, int n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);
int		ft_printnbr(int n);
int		ft_printf(char const *str, ...);
int		count_uitoa(unsigned int n);
char	*ft_build_uitoa(char *res, unsigned int len, unsigned int n);
char	*ft_uitoa(unsigned int n);
void	ft_putunsignednbr(unsigned int nbr);
int		ft_printunsigned(unsigned int n);
int		ft_print_nbr_base(unsigned int nb, char *base);
int		ft_count_base(unsigned int nb);
void	ft_putnbr_base(unsigned int nb, char *base);
void	ft_put_unsigned_nbr_base(unsigned long int nb, char *base);
int		ft_count_ubase(unsigned long int nb);
int		ft_print_unsignbr_base(unsigned long int nb);
int		ft_select_format(va_list variable, char c);

#endif
