/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:42:01 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/18 16:52:43 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zero_padding(t_instr *instr)
{
	int		i;

	i = -1;
	while (instr->str[++i])
	{
		if ((instr->str[i] == '0') && !(ft_isdigit(instr->str[i - 1]))
				&& (instr->str[i - 1] != '.'))
		{
			instr->padding = 1;
			break ;
		}
		else
			instr->padding = 0;
	}
}

void		sign_flag(t_instr *instr)
{
	if (ft_strchr(instr->str, '-') != NULL)
	{
		ft_del_chars(instr, "-");
		instr->minus_flag = 1;
	}
	else
		instr->minus_flag = 0;
	if (ft_strchr(instr->str, '+') != NULL
		&& (INT_TYPE(instr->type) || instr->type == 'D'))
	{
		ft_del_chars(instr, "+");
		instr->plus = 1;
	}
	else
		instr->plus = 0;
}

void		get_alterform(t_instr *instr)
{
	instr->alter_form = (DIFF_BASE(instr->type)
		&& ft_strchr(instr->str, '#')) ? 1 : 0;
	ft_del_chars(instr, "#");
}

char		*get_number(t_instr *instr, int i)
{
	int		k;
	char	*num;

	k = 0;
	num = (char*)malloc(ft_char_numlen(instr->str) + 1);
	while (ft_isdigit(instr->str[i]))
	{
		num[k++] = instr->str[i++];
	}
	num[k] = '\0';
	return (num);
}

void		get_width_contoller(t_instr *instr)
{
	int				i;
	intmax_t		width;
	int				flag;

	i = -1;
	instr->width = 0;
	while (instr->str[++i] && !(flag = 0))
	{
		if (instr->str[i] >= 49 && instr->str[i] <= 57
			&& ft_omit_zeros_neg(instr, i))
		{
			width = ft_atoi_base(get_number(instr, i), 10);
			i += ft_char_numlen(ft_itoa_base_usig(width, 10)) - 1;
			instr->width = (instr->str[i -
				ft_char_numlen(ft_itoa_base_usig(width, 10))] == '.')
				? instr->width : width;
		}
	}
	instr->str = rev_wstr(instr->str);
	ft_del_num(instr, rev_wstr(ft_itoa_base_usig(instr->width, 10)));
	instr->str = rev_wstr(instr->str);
	instr->width = (instr->width > 2147483647) ? 0 : instr->width;
}
