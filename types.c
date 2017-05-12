/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:08:29 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 14:34:47 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_instruct_type(t_instr *instr)
{
	instr->type = instr->str[ft_strlen(instr->str) - 1];
	ft_del_chars(instr, &instr->str[ft_strlen(instr->str) - 1]);
}

void		get_spaces_instruction(t_instr *instr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(ft_strlen(instr->str) + 1);
	(ft_strchr(instr->str, 32) ? tmp[j++] = ' ' : 0);
	while (instr->str[++i])
		(instr->str[i] != 32) ? tmp[j++] = instr->str[i] : 0;
	tmp[j] = '\0';
	instr->str = tmp;
	instr->space = ((ft_strchr(instr->str, 32) && conversion_flags(instr->type)) ? 1 : 0);
}

void		get_precision_sign(t_instr *instr)
{
	int		counter;
	int		flag;

	counter = 0;
	flag = (ft_strchr(instr->str, '.') ? 1 : 0);
	while (instr->str[counter] && flag)
	{
		if (instr->str[counter] == '.')
		{
			flag = 1;
			counter += (instr->str[counter + 1] == '0') ? ft_omit_zeros(instr->str, counter) - 1 : 0;
			if (instr->str[counter + 1] >= 49 && instr->str[counter + 1] <= 57)
			{
				flag = ft_atoi(get_width_perfomer(instr, counter + 1)) + 1;
				counter += ft_char_numlen(ft_itoa(flag));
			}
		}
		counter++;
	}
	instr->precision = flag;
	instr->precision -= 1;
	instr->str = rev_wstr(instr->str);
	(instr->precision > 0) ? ft_del_num(instr, ft_itoa(instr->precision)) : 0;
	instr->str = rev_wstr(instr->str);
}

void		get_typecast_ltrs(t_instr *instr)
{
	if (ft_strchr(instr->str, 'h') || ft_strstr(instr->str, "hh"))
	{
		instr->types = ((ft_count_alpha(instr->str, 'h') == 2) ? hh : h);
		ft_del_chars(instr, ft_mutiply_str("h", (ft_count_alpha(instr->str, 'h'))));
	}
	if (ft_strchr(instr->str, 'l') || ft_strstr(instr->str, "ll"))
	{
		instr->types = ((ft_count_alpha(instr->str, 'l') == 2) ? ll : l);
		ft_del_chars(instr, ft_mutiply_str("l", (ft_count_alpha(instr->str, 'l'))));
	}
	if (ft_strchr(instr->str, 'z'))
	{
		instr->types = z;
		ft_del_chars(instr, "z");
	}
	if (ft_strchr(instr->str, 'j'))
	{
		instr->types = j;
		ft_del_chars(instr, "j");
	}
	if (ft_strchr(instr->str, 't'))
	{
		instr->types = t;
		ft_del_chars(instr, "t");
	}
}
