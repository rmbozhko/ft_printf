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
			diff = instr->width - ft_strlen(instr->str) -
				((INT_CHARS || instr->type == 'D') ? instr->space : 0);
			if (INT_CHARS || instr->type == 'u' || instr->type == 'U')
				diff -= instr->ltz;
		}
		(diff > 0) ? instr->str =
			ft_strcat(ft_mutiply_str(" ", diff), instr->str) : 0;
	}
}

void				ft_alter_instruct_zero_padding(t_instr *instr)
{
	int		diff;
	int		p_alter_form;

	if (instr->precision > -1 && instr->zero_padding && (!instr->minus_flag) && tpcst_int(instr->type) && instr->width > 0)
		ft_alter_instruct_width(instr);
	else if ((!instr->minus_flag) && instr->width > 0 && instr->zero_padding &&
			(tpcst_char(instr->type) || tpcst_int(instr->type) || instr->type == 'p'))
	{
		diff = 0;
		if (instr->width > (int)ft_strlen(instr->str))
		{
			if (instr->type == 'p')
			{
				p_alter_form = instr->alter_form;
				instr->alter_form = 1;
			}
			diff = instr->width - ft_strlen(instr->str);
			if (instr->type != 'c')
				diff -= (((instr->type == 'x' || instr->type == 'X'
					|| instr->type == 'p') ? 2 : 1) * instr->alter_form);
			diff -= ((instr->space && HEX_CHARS) || instr->plus || instr->ltz) ? 1 : 0;
			(instr->type == 'p') ? instr->alter_form = p_alter_form : 0;
		}
		ADD_ZEROS;
	}
}

void				ft_alter_instruct_precision(t_instr *instr)
{
	int		diff;

	if ((instr->type == 's' || instr->type == 'S') && instr->precision >= 0)
		(instr->precision >= ft_strlen(instr->str)) ? 0 :
			ft_strncpy_mod(instr->str, instr->str, instr->precision);
	else if ((tpcst_int(instr->type)
		|| instr->type == 'p') && instr->precision > 0)
	{
		if (HEX_CHARS && instr->type != 'p')
		{
			diff = ((instr->precision > (int)ft_strlen(instr->str))
				? instr->precision - ft_strlen(instr->str) : 0);
			diff -= ((octal_sign) ? 1 : 2) * instr->alter_form;
		}
		else
		{
			diff = (instr->precision > (int)ft_strlen(instr->str))
				? instr->precision - ft_strlen(instr->str) : 0;
		}
		ADD_ZEROS;
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

void				ft_apply_instruct_flags(t_instr *instr)
{
	ft_chng_instrc	*type_funcs;
	int				counter;

	type_funcs = ft_set_function_arr();
	counter = -1;
	while (type_funcs[++counter] != NULL)
		type_funcs[counter](instr);
}
