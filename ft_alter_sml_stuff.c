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
	if (instr->alternative_form && (instr->type == 'X' || instr->type == 'x'))
		instr->str = (instr->type == 'X') ? ft_strjoin("0X", instr->str) : ft_strjoin("0x", instr->str);
	else if (instr->alternative_form && (instr->type == 'O' || instr->type == 'o'))
		instr->str = ft_strjoin("0", instr->str);
	else if (instr->type == 'p')
	{
		if (instr->alternative_form == 3)
			instr->str = ft_strjoin("0x10", instr->str);
		else if (instr->alternative_form == 4)
			instr->str = ft_strjoin("0x", instr->str);
		instr->alternative_form = 0;
	}
}

void						ft_alter_instruct_space(t_instr *instr)
{
	if (instr->space && (instr->plus != 1) && (!instr->alternative_form) &&
		(!instr->ltz) && (instr->type == 'd' || instr->type == 'i' || instr->type == 'D'))
	{
		instr->str = ft_strjoin(" ", instr->str);
		instr->space = 0;
	}
}

void						ft_alter_instruct_plus(t_instr *instr)
{
	if (instr->plus && (!instr->ltz) &&
		(instr->type == 'd' || instr->type == 'i' || instr->type == 'D'))
	{
		instr->str = ft_strjoin("+", instr->str);
		instr->plus = 0;
	}
}

void						ft_alter_instruct_minus(t_instr *instr)
{
	if (instr->ltz && (instr->type == 'd' || instr->type == 'i' || instr->type == 'D'))
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
		if ((instr->type != 'X' && instr->type != 'x') && (instr->type != 'O' && instr->type != 'o'))
			diff = ((instr->width > (int)ft_strlen(instr->str)) ? instr->width - ft_strlen(instr->str) - (2 * instr->alternative_form) : 0);
		else
			diff = ((instr->width > (int)ft_strlen(instr->str)) ? instr->width - ft_strlen(instr->str) : 0);
		instr->str = ft_strcat(instr->str, ft_mutiply_str(" ", diff));
	}
}
