/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 23:20:48 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 21:06:31 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_list *lst, void *s)
{
	char	c;

	lst->nsymb = 1;
	c = (char)s;
	while (lst->width > lst->nsymb && lst->nul == 0 && lst->min != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	while ((lst->width > lst->nsymb) && lst->nul == 1 && lst->min != 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	ft_putchar(c);
	while (lst->width > lst->nsymb && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	print_p_m_symb(t_list *lst, uintmax_t i)
{
	int	b;

	b = lst->width - lst->nsymb - (lst->p_n - (lst->nsymb - 1));
	ft_putchar('+');
	while (lst->p_n-- > lst->nsymb - 1)
		ft_putchar('0');
	ft_putnbr(i);
	while (b-- > 0)
		ft_putchar(' ');
}

void	print_d_i_null_p_n(t_list *lst)
{
	while (lst->width-- > 0)
		ft_putchar(' ');
}
