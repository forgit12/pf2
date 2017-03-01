/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 22:07:04 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 21:22:58 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nul_x(char *str, t_list *lst)
{
	int	n;
	int k;

	k = lst->p_n;
	n = len_n(str);
	if (str[n - 1] == '0' && str[n] == '\0' && n <= 3
		&& (lst->p_n != -1 || lst->hash == 1))
	{
		if (lst->width != 0 && lst->p_n != -1)
		{
			ft_hash_p_n(lst);
			return ;
		}
		if ((lst->conv == 7 || lst->conv == 8) && lst->p_n == 0)
		{
			ft_octal_null(str, lst);
			return ;
		}
		(lst->width != 0 && lst->hash == 0) ? (ft_nul_width(lst)) : 0;
		nul_x_add(str, lst, k, n);
	}
	else
		null_to_print(str, lst);
}

void	nul_x_add(char *str, t_list *lst, int k, int n)
{
	if (lst->width != 0 && lst->hash == 1)
		ft_nul_min(str, lst);
	if (lst->hash == 1 && lst->p_n == 0)
	{
		str[n - 1] = '\0';
		while (lst->p_n-- > 0 && lst->conv != 7 && lst->conv != 8)
			ft_putchar('0');
		if (lst->width == 0 && lst->hash == 1 && lst->p_n == 0)
			return ;
	}
	if (lst->width == 0 && lst->hash == 1 && lst->p_n > 0)
	{
		while (lst->p_n-- > 0)
			ft_putchar('0');
	}
	if (lst->width == 0 && lst->hash == 1 && lst->p_n == -1 && k != 0)
		ft_putchar('0');
	if (lst->width == 0 && lst->hash == 1 && k == 0)
		return ;
}

void	ft_hash_p_n(t_list *lst)
{
	while (lst->width > 0 && lst->p_n == 0 && lst->conv != 7 && lst->conv != 8)
	{
		ft_putchar(' ');
		lst->width--;
	}
	if (lst->width > 0 && lst->p_n == 0 && (lst->conv == 7 || lst->conv == 8))
	{
		while (lst->width - 1 > 0)
		{
			ft_putchar(' ');
			lst->width--;
		}
		lst->hash ? ft_putchar('0') : ft_putchar(' ');
	}
	if (lst->width > 0 && lst->p_n > 0)
	{
		while (lst->width-- > lst->p_n)
			ft_putchar(' ');
		while (lst->p_n-- > 0)
			ft_putchar('0');
	}
}

void	ft_nul_width(t_list *lst)
{
	while (lst->width-- > 0)
		ft_putchar(' ');
}

void	ft_nul_min(char *str, t_list *lst)
{
	if (lst->width != 0 && lst->hash != 0 && lst->min == 0 && lst->p_n == -1)
	{
		while (--lst->width > 0)
			ft_putchar(' ');
		ft_putstr(str);
	}
	if (lst->width != 0 && lst->hash != 0 && lst->min == 1 && lst->p_n == -1)
	{
		ft_putstr(str);
		while (--lst->width > 0)
			ft_putchar(' ');
	}
	if (lst->width != 0 && lst->hash != 0 && lst->min == 1 && lst->p_n != -1)
	{
		while (lst->p_n-- > 0)
			ft_putchar('0');
		ft_putchar(' ');
	}
	if (lst->width != 0 && lst->hash != 0 && lst->min != 1 && lst->p_n != -1)
	{
		ft_putchar(' ');
		while (lst->p_n-- > 0)
			ft_putchar('0');
	}
}
