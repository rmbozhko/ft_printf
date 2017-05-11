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

void		get_instruct_type(t_instruction *instruction)
{
	instruction->type = instruction->str[ft_strlen(instruction->str) - 1];
	ft_del_chars(instruction, &instruction->str[ft_strlen(instruction->str) - 1]);
}

void		get_spaces_instruction(t_instruction *instruction)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(ft_strlen(instruction->str) + 1);
	(ft_strchr(instruction->str, 32) ? tmp[j++] = ' ' : 0);
	while (instruction->str[++i])
		(instruction->str[i] != 32) ? tmp[j++] = instruction->str[i] : 0;
	tmp[j] = '\0';
	instruction->str = tmp;
	instruction->space = ((ft_strchr(instruction->str, 32) && conversion_flags(instruction->type)) ? 1 : 0);
}

void		get_precision_sign(t_instruction *instruction)
{
	int		counter;
	int		flag;

	counter = 0;
	flag = (ft_strchr(instruction->str, '.') ? 1 : 0);
	while (instruction->str[counter] && flag)
	{
		if (instruction->str[counter] == '.')
		{
			flag = 1;
			counter += (instruction->str[counter + 1] == '0') ? ft_omit_zeros(instruction->str, counter) - 1 : 0;
			if (instruction->str[counter + 1] >= 49 && instruction->str[counter + 1] <= 57)
			{
				flag = ft_atoi(get_width_perfomer(instruction, counter + 1)) + 1;
				counter += ft_char_numlen(ft_itoa(flag));
			}
		}
		counter++;
	}
	instruction->precision = flag;
	instruction->precision -= 1;
	instruction->str = rev_wstr(instruction->str);
	(instruction->precision > 0) ? ft_del_num(instruction, ft_itoa(instruction->precision)) : 0;
	instruction->str = rev_wstr(instruction->str);
}

void		get_typecast_ltrs(t_instruction *instruction)
{
	if (ft_strchr(instruction->str, 'h') || ft_strstr(instruction->str, "hh"))
	{
		instruction->types = ((ft_count_alpha(instruction->str, 'h') == 2) ? hh : h);
		ft_del_chars(instruction, ft_mutiply_str("h", (ft_count_alpha(instruction->str, 'h'))));
	}
	if (ft_strchr(instruction->str, 'l') || ft_strstr(instruction->str, "ll"))
	{
		instruction->types = ((ft_count_alpha(instruction->str, 'l') == 2) ? ll : l);
		ft_del_chars(instruction, ft_mutiply_str("l", (ft_count_alpha(instruction->str, 'l'))));
	}
	if (ft_strchr(instruction->str, 'z'))
	{
		instruction->types = z;
		ft_del_chars(instruction, "z");
	}
	if (ft_strchr(instruction->str, 'j'))
	{
		instruction->types = j;
		ft_del_chars(instruction, "j");
	}
	if (ft_strchr(instruction->str, 't'))
	{
		instruction->types = t;
		ft_del_chars(instruction, "t");
	}
}
