/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:15:57 by oborysen          #+#    #+#             */
/*   Updated: 2017/03/01 18:05:41 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_list *lst, void *str)
{
	char	*s;

	s = (char*)str;
	(s == 0) ? (s = s_null()) : 0;
	lst->nsymb = ft_strlen(s);
	if (lst->p_n != -1)
	{
		print_s_p(lst, s);
		return ;
	}
	while ((lst->width > lst->nsymb) && lst->min != 1 && lst->nul != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	while ((lst->width > lst->nsymb) && lst->min != 1 && lst->nul == 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	ft_putstr(s);
	while ((lst->width-- > lst->nsymb) && lst->min == 1)
		ft_putchar(' ');
}

char	*s_null(void)
{
	char	*s1;

	s1 = (char*)malloc(7);
	s1[0] = '(';
	s1[1] = 'n';
	s1[2] = 'u';
	s1[3] = 'l';
	s1[4] = 'l';
	s1[5] = ')';
	s1[6] = '\0';
	return (s1);
}

void	print_s_p(t_list *lst, char *s)
{
	char *s1;

	s1 = ft_strsub(s, 0, lst->p_n);
	lst->nsymb = ft_strlen(s1);
	while ((lst->width > lst->nsymb) && lst->min != 1 && lst->nul != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	while ((lst->width > lst->nsymb) && lst->min != 1 && lst->nul == 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	if (lst->p_n != 0)
		ft_putstr(s1);
	while ((lst->width > lst->nsymb) && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	conv_p_s(t_list *lst, const char *str, int ivid, int iconv)
{
	int j;

	lst->p_n = -1;
	j = iconv;
	while (ivid < j)
	{
		if (str[j] == '.')
		{
			lst->p_n = 0;
			j++;
			while (str[j] == '0')
				j++;
			if (str[j] < 48 || str[j] > 57)
				break ;
			while ((str[j] >= 48) && (str[j] <= 57))
			{
				lst->p_n = lst->p_n * 10 + (str[j] - '0');
				j++;
			}
		}
		if (lst->p_n != -1)
			break ;
		j--;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
