/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 22:13:28 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 22:42:58 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_fix_minus_d(t_list *lst, uintmax_t i)
{
	while (lst->width - lst->minus > lst->nsymb && lst->nul != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	if (lst->minus == 1)
		ft_putchar('-');
	while (lst->width - lst->minus > lst->nsymb && lst->nul == 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	ft_putnbr(i);
	return ;
}

void	ft_octal_null(char *str, t_list *lst)
{
	if (!str)
		return ;
	if (lst->hash == 0)
	{
		while (lst->width-- > 0)
			ft_putchar(' ');
	}
	lst->hash ? ft_putchar('0') : 0;
}

void	print_xstr_add(char *s, t_list *lst)
{
	while (lst->width - 2 > lst->nsymb && lst->nul == 0 && lst->min != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	if ((lst->conv == 11 || lst->conv == 12) && lst->hash == 1)
	{
		printfix(s, lst);
		return ;
	}
	while ((lst->width - 2 > lst->nsymb) && lst->nul == 1 && lst->min != 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	ft_putstr(s);
	while (lst->width - 2 > lst->nsymb && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	printi_add_1(t_list *lst, long i)
{
	if (lst->minus == 1 && lst->width >= lst->nsymb && lst->min != 1)
	{
		print_fix_minus_d(lst, i);
		return ;
	}
	if (lst->conv != 9 && lst->conv != 10 && lst->minus != 1 && lst->plus != 1
		&& lst->space == 1 && (lst->width == 0 || (lst->width > 0
		&& lst->min == 1)))
	{
		ft_putchar(' ');
		lst->width--;
	}
	(lst->plus == 1 && lst->minus == 0
	&& (lst->nsymb - 1 > lst->p_n)) ? (lst->nsymb--) : 0;
	while ((lst->width - lst->plus - lst->minus > lst->nsymb) && (lst->nul == 0
			|| (lst->p_n <= lst->nsymb && lst->p_n != -1)) && lst->min != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	printi_add_2(lst, i);
}

void	printi_add_2(t_list *lst, long i)
{
	if (lst->minus == 1 && ((lst->width > lst->nsymb) || lst->width == 0))
	{
		ft_putchar('-');
		lst->minus = 0;
		lst->plus = 0;
	}
	if (lst->plus == 1 && lst->nul == 1 && lst->minus != 1)
		ft_putchar('+');
	if (lst->plus == 1 && lst->nul != 1 && lst->minus != 1)
		ft_putchar('+');
	(lst->plus == 1 && lst->minus == 0
	&& (lst->nsymb - 1 > lst->p_n)) ? (lst->nsymb++) : 0;
	while ((lst->width > lst->nsymb)
			&& (lst->nul == 1 || lst->plus == 1) && lst->min != 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	printi_add_3(lst, i);
}
