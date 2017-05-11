/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:25:59 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 15:30:23 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_bg_c(t_instruction *instruction, va_list ap)
{
	int		arg;

	if (instruction->type == 'C')
	{
		arg = va_arg(ap, int);
		instruction->str = (arg == 0) ? char_is_zero(instruction) : ft_wchar((int)arg);
	}
}

void				ft_bg_s(t_instruction *instruction, va_list ap)
{
	int		*arg;

	if (instruction->type == 'S')
	{
		arg = va_arg(ap, int*);
		instruction->str = (arg != NULL) ? ft_wstr(arg, instruction->precision) : ft_strjoin("(null)", "");
	}
}

void				ft_sml_c(t_instruction *instruction, va_list ap)
{
	int		arg;

	if (instruction->type == 'c')
	{
		if (instruction->types == 3)
		{
			arg = va_arg(ap, wint_t);
			instruction->str = (arg == 0) ? char_is_zero(instruction) : ft_wchar((int)arg);
		}
		else
		{
			arg = va_arg(ap, int);
			instruction->str = (arg == 0) ? char_is_zero(instruction) : ft_char_to_string((int)arg);
		}
	}
}

void				ft_sml_s(t_instruction *instruction, va_list ap)
{
	int		*arg;
	char	*str;

	if (instruction->type == 's')
	{
		if (instruction->types == 3)
		{
			arg = va_arg(ap, int*);
			instruction->str = (arg != NULL) ? ft_wstr(arg, instruction->precision) : ft_strjoin("(null)", "");
		}
		else
		{
			str = va_arg(ap, char*);
			instruction->str = (str != NULL) ? ft_strjoin("", str) : ft_strjoin("(null)", "");
		}
	}
}

void				ft_other_chars(t_instruction *instruction, va_list ap)
{
	if (!(conversion_flags((int)instruction->type)))
		instruction->str = ft_char_to_string(instruction->type);
}
