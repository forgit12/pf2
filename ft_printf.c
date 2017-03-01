/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:03:03 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/28 23:16:17 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	t_list		*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	g_symb = 0;
	i = 0;
	va_start(ap, str);
	print_symb(str, &i, ap, lst);
	va_end(ap);
	return (g_symb);
}

/*
** Function that recognition parameter in string (*str)
*/

void	printconvlet(t_list *lst, va_list ap)
{
	if (lst->conv == 1 || lst->conv == 2)
		print_s(lst, va_arg(ap, void*));
	if (lst->conv == 3)
		print_p(lst, va_arg(ap, void*), 16);
	if (lst->conv == 4 || lst->conv == 5 || lst->conv == 6)
		printi(lst, va_arg(ap, void*));
	if (lst->conv == 7 || lst->conv == 8)
		print_x(lst, va_arg(ap, void*), 8, 0);
	if (lst->conv == 9 || lst->conv == 10)
		printi(lst, va_arg(ap, void*));
	if (lst->conv == 11 || lst->conv == 12)
		print_x(lst, va_arg(ap, void*), 16, 0);
	if (lst->conv == 13 || lst->conv == 14)
		print_c(lst, va_arg(ap, void*));
	if (lst->conv == 15)
		print_vids(lst);
	if (lst->conv == 0)
		print_ch(lst);
}

int		*print_symb(const char *str, int *i, va_list ap, t_list *lst)
{
	nullst(lst);
	while (str[*i])
	{
		if (str[*i] != '%')
			ft_putchar(str[*i]);
		if (str[*i] == '%')
		{
			if (str[(*i) + 1] == '%')
				ft_putpercent(i);
			else
			{
				recognition_flags(str, i, lst);
				printconvlet(lst, ap);
			}
		}
		str[*i] ? (*i)++ : 0;
	}
	return (i);
}
