/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:02:00 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/18 16:04:01 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_alter_instruct_width(t_instr *instr)
{
	int		diff;

	if (instr->width > 0)
	{
		diff = 0;
		(instr->plus && (!ft_strchr(instr->str, '-')))
			? ft_alter_instruct_plus(instr) : 0;
		(instr->ltz) ? ft_alter_instruct_minus(instr) : 0;
		if (instr->width > (int)ft_strlen(instr->str))
		{
			diff = instr->width -
				ft_strlen(instr->str) - ((INT_TYPE(instr->type)
				|| instr->type == 'D') ? instr->space : 0);
			(INT_TYPE(instr->type)) ? diff -= instr->ltz : 0;
		}
		(diff > 0) ? instr->str =
			ft_strcat(ft_mutiply_str(" ", diff), instr->str) : 0;
	}
}

void				ft_alter_instruct_zero_padding(t_instr *instr)
{
	int		diff;

	if (instr->precision > -1 && TPCST_INT(instr->type) && FLAGS_COND)
	{
		ft_alter_instruct_alternative_form(instr);
		ft_alter_instruct_width(instr);
	}
	else if (FLAGS_COND && (TPCST_INT_CHAR || instr->type == 'p'))
	{
		diff = 0;
		if (instr->width > (int)ft_strlen(instr->str))
		{
			diff = instr->width - ft_strlen(instr->str);
			diff -= ((HEX_TYPE(instr->type) || instr->type == 'p')
				? 2 : 1) * instr->alter_form;
			diff -= ((instr->space && INT_TYPE(instr->type))
				|| instr->plus || instr->ltz) ? 1 : 0;
		}
		ADD_ZEROS;
	}
}

void				ft_alter_instruct_precision(t_instr *instr)
{
	int		diff;

	if ((instr->type == 's' || instr->type == 'S') && instr->precision >= 0)
		(instr->precision >= (long)ft_strlen(instr->str)) ? 0 :
			ft_strncpy_mod(instr->str, instr->str, instr->precision);
	else if ((TPCST_INT(instr->type)
		|| instr->type == 'p') && instr->precision > 0)
	{
		if (NOT_HEX_TYPE(instr->type) && instr->type != 'p')
		{
			diff = ((instr->precision > (int)ft_strlen(instr->str))
				? instr->precision - ft_strlen(instr->str) : 0);
			diff -= ((OCT_TYPE(instr->type)) ? 1 : 2) * instr->alter_form;
		}
		else
		{
			diff = (instr->precision > (int)ft_strlen(instr->str))
				? instr->precision - ft_strlen(instr->str) : 0;
		}
		ADD_ZEROS;
	}
}

t_ft_chng_instrc	*ft_set_function_arr(void)
{
	t_ft_chng_instrc	*func_arr;

	func_arr = (t_ft_chng_instrc*)malloc(sizeof(t_ft_chng_instrc*) * 8 + 1);
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

void				ft_apply_instruct_flags(t_instr *instr)
{
	t_ft_chng_instrc	*type_funcs;
	int					counter;

	type_funcs = ft_set_function_arr();
	counter = -1;
	while (type_funcs[++counter] != NULL)
	{
		type_funcs[counter](instr);
	}
}
