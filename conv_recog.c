/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_recog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:22:08 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/28 23:28:30 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		nullst(t_list *lst)
{
	lst->min = 0;
	lst->nul = 0;
	lst->plus = 0;
	lst->space = 0;
	lst->hash = 0;
	lst->width = 0;
	lst->p_n = 0;
	lst->smodif = 0;
	lst->conv = 0;
	lst->nsymb = 0;
	lst->minus = 0;
	lst->next = NULL;
}

void		conversionletter(const char *str, int *i, t_list *lst)
{
	lst->ch = str[(*i)];
	if (str[*i] == 's')
		lst->conv = 1;
	if (str[*i] == 'S')
		lst->conv = 2;
	if (str[*i] == 'p')
		lst->conv = 3;
	if (str[*i] == 'd')
		lst->conv = 4;
	if (str[*i] == 'D')
		lst->conv = 5;
	if (str[*i] == 'i')
		lst->conv = 6;
	if (str[*i] == 'o')
		lst->conv = 7;
	if (str[*i] == 'O')
		lst->conv = 8;
	if (str[*i] == 'u')
		lst->conv = 9;
	if (str[*i] == 'U')
		lst->conv = 10;
	conversionletter2(str, i, lst);
}

void		conversionletter2(const char *str, int *i, t_list *lst)
{
	if (str[*i] == 'x')
		lst->conv = 11;
	if (str[*i] == 'X')
		lst->conv = 12;
	if (str[*i] == 'c')
		lst->conv = 13;
	if (str[*i] == 'C')
		lst->conv = 14;
	if (str[*i] == '%')
		lst->conv = 15;
}

t_list		*recognition_flags(const char *str, int *i, t_list *lst)
{
	int		ivid;
	int		iconv;

	ivid = *i;
	(*i)++;
	while ((str[*i] == ' ' || str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'j'
			|| str[*i] == 'z' || str[*i] == '-' || str[*i] == '#' ||
			str[*i] == '+' || str[*i] == '.' ||
			(str[*i] >= 48 && str[*i] <= 57)) && str[*i] != '\0')
	{
		(*i)++;
	}
	iconv = *i;
	countp(str, ivid, iconv, lst);
	countflags(str, ivid, iconv, lst);
	countwidth(str, ivid, iconv, lst);
	countsizemodifier(str, ivid, iconv, lst);
	conversionletter(str, i, lst);
	if (lst->conv == 1)
		conv_p_s(lst, str, ivid, iconv);
	return (lst);
}

void		countnumsymb(t_list *lst, uintmax_t i)
{
	if (i == 0)
		lst->nsymb++;
	while (i > 0)
	{
		i = i / 10;
		lst->nsymb++;
	}
	if (lst->plus && lst->minus != 1)
		lst->nsymb++;
	if (lst->conv == 9 || lst->conv == 10)
		lst->plus = 0;
}
