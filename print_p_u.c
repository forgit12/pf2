/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:01:03 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 18:19:37 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_p(unsigned long value, int base1, char *str, int *i)
{
	char			*tmpl;
	unsigned long	base;

	base = (unsigned long)base1;
	tmpl = (char*)malloc(17);
	tmpl = "0123456789abcdef";
	if (value >= base)
		f_p(value / base, base, str, i);
	str[(*i)++] = tmpl[(value % base)];
}

void	print_p(t_list *lst, void *nt, unsigned long base)
{
	int				i;
	char			*str;

	i = 0;
	lst->hash = 1;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return ;
	if (lst->hash == 1 && lst->conv == 11 && lst->p_n == 0 && lst->nul == 0)
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	f_p((unsigned long)nt, base, str, &i);
	str[i] = '\0';
	if (lst->p_n == 0)
		lst->nul = 0;
	print_p_str(str, lst);
}

void	print_p_str(char *s, t_list *lst)
{
	while (s[lst->nsymb])
		lst->nsymb++;
	if (lst->hash == 1 && (lst->width > 0 && lst->p_n > 0))
	{
		print_p_hash(s, lst);
		return ;
	}
	if (lst->p_n > 0 && (lst->p_n - lst->nsymb > 0))
	{
		print_p_precision(s, lst);
		return ;
	}
	while (lst->width - 2 > lst->nsymb && lst->nul == 0 && lst->min != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	print_p_str_add(s, lst);
}

void	print_p_hash(char *s, t_list *lst)
{
	if (lst->p_n > 0 && (lst->p_n > lst->nsymb))
	{
		print_p_precision(s, lst);
		return ;
	}
	ft_putstr("0x");
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

void	print_p_precision(char *s, t_list *lst)
{
	int				k;
	int				t;

	k = lst->p_n - lst->nsymb;
	t = lst->width - 2 - lst->nsymb - k;
	while (t > 0 && lst->min != 1)
	{
		ft_putchar(' ');
		t--;
	}
	ft_putstr("0x");
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
