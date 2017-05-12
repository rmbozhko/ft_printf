/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_sml_stuff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:00:29 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 16:01:24 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_alter_instruct_alternative_form(t_instr *instr)
{
	if (instr->alter_form && (instr->type == 'X' || instr->type == 'x'))
		instr->str = (instr->type == 'X') ?
			ft_strjoin("0X", instr->str) : ft_strjoin("0x", instr->str);
	else if (instr->alter_form && OCTAL_SIGN)
		instr->str = ft_strjoin("0", instr->str);
	else if (instr->type == 'p')
	{
		if (instr->alter_form == 3)
			instr->str = ft_strjoin("0x10", instr->str);
		else if (instr->alter_form == 4)
			instr->str = ft_strjoin("0x", instr->str);
		instr->alter_form = 0;
	}
}

void						ft_alter_instruct_space(t_instr *instr)
{
	if (instr->space && (instr->plus != 1) && (!instr->alter_form) &&
		(!instr->ltz) && (INT_CHARS(instr->type) || instr->type == 'D'))
	{
		instr->str = ft_strjoin(" ", instr->str);
		instr->space = 0;
	}
}

void						ft_alter_instruct_plus(t_instr *instr)
{
	if (instr->plus && (!instr->ltz) && (INT_CHARS(instr->type) || instr->type == 'D'))
	{
		instr->str = ft_strjoin("+", instr->str);
		instr->plus = 0;
	}
}

void						ft_alter_instruct_minus(t_instr *instr)
{
	if (instr->ltz && (INT_CHARS(instr->type) || instr->type == 'D'))
	{
		instr->str = ft_strjoin("-", instr->str);
		instr->ltz = 0;
	}
}

void						ft_alter_instruct_minus_flag(t_instr *instr)
{
	int			diff;

	if (instr->minus_flag && instr->width > 0)
	{
		if ((NOT_HEX_CHARS(instr->type))
			&& (instr->type != 'O' && instr->type != 'o'))
			diff = ((instr->width > (int)ft_strlen(instr->str)) ? instr->width -
				ft_strlen(instr->str) - (2 * instr->alter_form) : 0);
		else
			diff = ((instr->width > (int)ft_strlen(instr->str))
				? instr->width - ft_strlen(instr->str) : 0);
		instr->str = ft_strcat(instr->str, ft_mutiply_str(" ", diff));
	}
}
