/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:58:52 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 17:05:21 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printprecision_x(t_list *lst, char *s)
{
	int	r;
	int	t;

	r = lst->p_n - lst->nsymb;
	t = lst->nsymb + r;
	if (lst->hash == 1 && (lst->conv == 11 || lst->conv == 12))
		(lst->conv == 11) ? ft_putstr("0x") : ft_putstr("0X");
	while (lst->width > t && lst->min != 1 && r > 0)
	{
		ft_putchar(' ');
		lst->width--;
	}
	while ((r--) > 0)
		ft_putchar('0');
	ft_putstr(s);
	while (lst->min == 1 && lst->width > t)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	print_xstr(char *s, t_list *lst)
{
	while (s[lst->nsymb])
		lst->nsymb++;
	if (lst->hash == 1 && (lst->conv == 11 || lst->conv == 12)
		&& (lst->width > 0 && lst->p_n > 0))
	{
		print_xstr_hash(s, lst);
		return ;
	}
	if (lst->p_n > 0 && (lst->p_n - lst->nsymb > 0))
	{
		printprecision_x(lst, s);
		return ;
	}
	if (lst->conv == 7 || lst->conv == 8)
		lst->width += 2;
	if (lst->hash == 0 && (lst->conv == 11 || lst->conv == 12) && lst->min == 1)
	{
		pint_fix_min(s, lst);
		return ;
	}
	if (lst->hash == 0 && (lst->conv == 11 || lst->conv == 12) && lst->min != 1)
		lst->width += 2;
	print_xstr_add(s, lst);
}

void	printfix(char *s, t_list *lst)
{
	(lst->conv == 11) ? ft_putstr("0x") : ft_putstr("0X");
	while (lst->width - 2 > lst->nsymb && lst->nul == 0 && lst->min != 1)
	{
		ft_putchar(' ');
		lst->width--;
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

void	print_xstr_hash(char *s, t_list *lst)
{
	if (lst->p_n > 0 && (lst->p_n > lst->nsymb))
	{
		print_xstr_hash_p(s, lst);
		return ;
	}
	while ((lst->width - 2 - lst->nsymb > 0) && lst->min != 1 && lst->nul != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	(lst->conv == 11) ? ft_putstr("0x") : ft_putstr("0X");
	while (lst->nul == 1 && lst->min != 1 && (lst->width - 2 - lst->nsymb > 0))
	{
		lst->width--;
		ft_putchar('0');
	}
	ft_putstr(s);
	while ((lst->width - 2 - lst->nsymb > 0) && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	print_xstr_hash_p(char *s, t_list *lst)
{
	int	k;
	int	t;

	k = lst->p_n - lst->nsymb;
	t = lst->width - 2 - lst->nsymb - k;
	while (t > 0 && lst->min != 1)
	{
		ft_putchar(' ');
		t--;
	}
	(lst->conv == 11) ? ft_putstr("0x") : ft_putstr("0X");
	while (k > 0)
	{
		ft_putchar('0');
		k--;
	}
	ft_putstr(s);
	while ((t > 0) && lst->min == 1)
	{
		ft_putchar(' ');
		t--;
	}
}
