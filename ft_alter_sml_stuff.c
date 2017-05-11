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

void						ft_alter_instruct_alternative_form(t_instruction *instruction)
{
	if (instruction->alternative_form && (instruction->type == 'X' || instruction->type == 'x'))
		instruction->str = (instruction->type == 'X') ? ft_strjoin("0X", instruction->str) : ft_strjoin("0x", instruction->str);
	else if (instruction->alternative_form && (instruction->type == 'O' || instruction->type == 'o'))
		instruction->str = ft_strjoin("0", instruction->str);
	else if (instruction->type == 'p')
	{
		if (instruction->alternative_form == 3)
			instruction->str = ft_strjoin("0x10", instruction->str);
		else if (instruction->alternative_form == 4)
			instruction->str = ft_strjoin("0x", instruction->str);
		instruction->alternative_form = 0;
	}
}

void						ft_alter_instruct_space(t_instruction *instruction)
{
	if (instruction->space && (instruction->plus != 1) && (!instruction->alternative_form) &&
		(!instruction->ltz) && (instruction->type == 'd' || instruction->type == 'i' || instruction->type == 'D'))
	{
		instruction->str = ft_strjoin(" ", instruction->str);
		instruction->space = 0;
	}
}

void						ft_alter_instruct_plus(t_instruction *instruction)
{
	if (instruction->plus && (!instruction->ltz) &&
		(instruction->type == 'd' || instruction->type == 'i' || instruction->type == 'D'))
	{
		instruction->str = ft_strjoin("+", instruction->str);
		instruction->plus = 0;
	}
}

void						ft_alter_instruct_minus(t_instruction *instruction)
{
	if (instruction->ltz && (instruction->type == 'd' || instruction->type == 'i' || instruction->type == 'D'))
	{
		instruction->str = ft_strjoin("-", instruction->str);
		instruction->ltz = 0;
	}
}

void						ft_alter_instruct_minus_flag(t_instruction *instruction)
{
	int			diff;

	if (instruction->minus_flag && instruction->width > 0)
	{
		if ((instruction->type != 'X' && instruction->type != 'x') && (instruction->type != 'O' && instruction->type != 'o'))
			diff = ((instruction->width > (int)ft_strlen(instruction->str)) ? instruction->width - ft_strlen(instruction->str) - (2 * instruction->alternative_form) : 0);
		else
			diff = ((instruction->width > (int)ft_strlen(instruction->str)) ? instruction->width - ft_strlen(instruction->str) : 0);
		instruction->str = ft_strcat(instruction->str, ft_mutiply_str(" ", diff));
	}
}
