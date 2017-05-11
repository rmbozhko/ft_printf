/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:02:00 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 16:11:15 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_alter_instruct_width(t_instruction *instruction)
{
	int		diff;

	if (instruction->width > 0)
	{
		diff = 0;
		(instruction->plus && (!ft_strchr(instruction->str, '-'))) ? ft_alter_instruct_plus(instruction) : 0;
		(instruction->ltz) ? ft_alter_instruct_minus(instruction) : 0;
		if (instruction->width > (int)ft_strlen(instruction->str))
		{
			diff = instruction->width - ft_strlen(instruction->str) - (((instruction->type == 'd' || instruction->type == 'i' || instruction->type == 'D')) ? instruction->space : 0);
			if (instruction->type == 'd' || instruction->type == 'i' || instruction->type == 'u' || instruction->type == 'U')
				diff -= instruction->ltz;
		}
		(diff > 0) ? instruction->str = ft_strcat(ft_mutiply_str(" ", diff), instruction->str) : 0;
	}
}

void				ft_alter_instruct_zero_padding(t_instruction *instruction)
{
	int		diff;
	int		p_alter_form;

	if (instruction->precision > -1 && instruction->zero_padding && (!instruction->minus_flag)
		&& typecast_flags_int(instruction->type) && instruction->width > 0)
		ft_alter_instruct_width(instruction);
	else if ((!instruction->minus_flag) && instruction->width > 0 && instruction->zero_padding &&
			(typecast_flags_char(instruction->type) || typecast_flags_int(instruction->type) || instruction->type == 'p'))
	{
		diff = 0;
		if (instruction->width > (int)ft_strlen(instruction->str))
		{
			if (instruction->type == 'p')
			{
				p_alter_form = instruction->alternative_form;
				instruction->alternative_form = 1;
			}
			diff = instruction->width - ft_strlen(instruction->str);
			if (instruction->type != 'c')
				diff -= (((instruction->type == 'x' || instruction->type == 'X' || instruction->type == 'p') ? 2 : 1) * instruction->alternative_form);
			diff -= ((instruction->space && (instruction->type != 'X' && instruction->type != 'x')) || instruction->plus || instruction->ltz) ? 1 : 0;
			(instruction->type == 'p') ? instruction->alternative_form = p_alter_form : 0;
		}
		(diff > 0) ? instruction->str = ft_strcat(ft_mutiply_str("0", diff), instruction->str) : 0;
	}
}

void				ft_alter_instruct_precision(t_instruction *instruction)
{
	int		diff;

	if ((instruction->type == 's' || instruction->type == 'S') && instruction->precision >= 0)
		(instruction->precision >= ft_strlen(instruction->str)) ? 0 : ft_strncpy_mod(instruction->str, instruction->str, instruction->precision);
	else if ((typecast_flags_int(instruction->type) || instruction->type == 'p') && instruction->precision > 0)
	{
		if (instruction->type != 'X' && instruction->type != 'x' && instruction->type != 'p')
		{
			diff = ((instruction->precision > (int)ft_strlen(instruction->str)) ? instruction->precision - ft_strlen(instruction->str) : 0);
			diff -= ((instruction->type == 'o' || instruction->type == 'O') ? 1 : 2) * instruction->alternative_form;
		}
		else
			diff = (instruction->precision > (int)ft_strlen(instruction->str)) ? instruction->precision - ft_strlen(instruction->str) : 0;
		(diff > 0) ? instruction->str = ft_strcat(ft_mutiply_str("0", diff), instruction->str) : 0;
	}
}

ft_chng_instrc		*ft_set_function_arr(void)
{
	ft_chng_instrc		*func_arr;

	func_arr = (ft_chng_instrc*)malloc(sizeof(ft_chng_instrc*) * 8 + 1);
	func_arr[0] = ft_alter_instruct_precision;
	func_arr[1] = ft_alter_instruct_zero_padding;
	func_arr[2] = ft_alter_instruct_space;
	func_arr[3] = ft_alter_instruct_plus;
	func_arr[4] = ft_alter_instruct_minus;
	func_arr[5] = ft_alter_instruct_alternative_form;
	func_arr[6] = ft_alter_instruct_minus_flag;
	func_arr[7] = ft_alter_instruct_width;
	func_arr[8] = NULL;
	return (func_arr);
}

void				ft_apply_instruct_flags(t_instruction *instruction)
{
	ft_chng_instrc	*type_funcs;
	int				counter;

	type_funcs = ft_set_function_arr();
	counter = -1;
	while (type_funcs[++counter] != NULL)
		type_funcs[counter](instruction);
}
