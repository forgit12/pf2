/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:38:08 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 19:22:48 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ch(t_list *lst)
{
	if (lst->ch == '\0' || lst->ch == 88 || lst->ch == 95 || lst->ch == 97 ||
		lst->ch == 99 || lst->ch == 100 || lst->ch == 101 || lst->ch == 102
		|| lst->ch == 103 || lst->ch == 104 || lst->ch == 105 || lst->ch == 106
		|| lst->ch == 108 || lst->ch == 110 || lst->ch == 111 || lst->ch == 112
		|| lst->ch == 113 || lst->ch == 115 || lst->ch == 116 || lst->ch == 117
		|| lst->ch == 118 || lst->ch == 120 || lst->ch == 122)
		return ;
	while (--lst->width > 0 && lst->min != 1 && lst->nul != 1)
		ft_putchar(' ');
	while (lst->width-- > 0 && lst->min != 1 && lst->nul == 1)
		ft_putchar('0');
	ft_putchar(lst->ch);
	while (lst->width-- + 1 > 0 && lst->min == 1 && lst->nul != 1)
		ft_putchar(' ');
}
