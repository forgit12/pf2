/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:04:59 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 18:27:20 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_sm(t_list *lst, long *i, void *nt)
{
	if (lst->smodif == 1 && (lst->conv == 4 || lst->conv == 6))
		*i = (char)nt;
	if (lst->smodif == 2 && (lst->conv == 4 || lst->conv == 6))
		*i = (short)nt;
	if (lst->smodif == 0 && (lst->conv == 4 || lst->conv == 6))
		*i = (int)nt;
	if (lst->conv == 5)
		*i = (long)nt;
	if (lst->smodif > 2 && (lst->conv == 4 || lst->conv == 6))
		*i = (long)nt;
	if (lst->smodif == 1 && lst->conv == 9)
		*i = (unsigned char)nt;
	if (lst->smodif == 2 && lst->conv == 9)
		*i = (unsigned short)nt;
	if (lst->smodif == 0 && lst->conv == 9)
		*i = (unsigned int)nt;
	if (lst->smodif > 2 && lst->conv == 9)
		*i = (unsigned long)nt;
	if (lst->conv == 10)
		*i = (unsigned long)nt;
	(*i < 0 && lst->conv != 9 && lst->conv != 10)
	? (lst->minus++ && lst->nsymb++) : 0;
	(lst->minus == 1) ? (*i = *i * -1) : 0;
}

void	conv_sm_x_o(t_list *lst, unsigned long *value, void *nt)
{
	if (lst->smodif == 1 && (lst->conv == 7
		|| lst->conv == 11 || lst->conv == 12))
		*value = (unsigned char)nt;
	if (lst->smodif == 2 && (lst->conv == 7
		|| lst->conv == 11 || lst->conv == 12))
		*value = (unsigned short)nt;
	if (lst->smodif == 0 && (lst->conv == 7
		|| lst->conv == 11 || lst->conv == 12))
		*value = (unsigned int)nt;
	if (lst->smodif > 2 && (lst->conv == 7
		|| lst->conv == 11 || lst->conv == 12))
		*value = (unsigned long)nt;
	if (lst->conv == 8 || lst->conv == 3)
		*value = (unsigned long)nt;
}

void	print_vids(t_list *lst)
{
	lst->nsymb = 1;
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
	ft_putchar('%');
	while (lst->width > lst->nsymb && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	pint_fix_min(char *s, t_list *lst)
{
	ft_putstr(s);
	while (lst->width > lst->nsymb && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}
