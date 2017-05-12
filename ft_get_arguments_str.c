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

void				ft_bg_c(t_instr *instr, va_list ap)
{
	int		arg;

	if (instr->type == 'C')
	{
		if (instr->types == 3)
		{
			arg = va_arg(ap, wint_t);
			instr->str = (arg == 0)
				? char_is_zero(instr) : ft_wchar((int)arg);
		}
		else
		{
			arg = va_arg(ap, int);
			instr->str = (arg == 0)
				? char_is_zero(instr) : ft_char_to_string((int)arg);
		}
	}
}

void				ft_bg_s(t_instr *instr, va_list ap)
{
	int		*arg;

	if (instr->type == 'S')
	{
		arg = va_arg(ap, int*);
		instr->str = (arg != NULL)
			? ft_wstr(arg, instr->precision) : ft_strjoin("(null)", "");
	}
}

void				ft_sml_c(t_instr *instr, va_list ap)
{
	int		arg;

	if (instr->type == 'c')
	{
		if (instr->types == 3)
		{
			arg = va_arg(ap, wint_t);
			instr->str = (arg == 0)
				? char_is_zero(instr) : ft_wchar((int)arg);
		}
		else
		{
			arg = va_arg(ap, int);
			instr->str = (arg == 0)
				? char_is_zero(instr) : ft_char_to_string((int)arg);
		}
	}
}

void				ft_sml_s(t_instr *instr, va_list ap)
{
	int		*arg;
	char	*str;

	if (instr->type == 's')
	{
		if (instr->types == 3)
		{
			arg = va_arg(ap, int*);
			instr->str = (arg != NULL) ?
			ft_wstr(arg, instr->precision) : ft_strjoin("(null)", "");
		}
		else
		{
			str = va_arg(ap, char*);
			instr->str = (str != NULL) ? ft_strjoin("", str)
				: ft_strjoin("(null)", "");
		}
	}
}

void				ft_other_chars(t_instr *instr, va_list ap)
{
	if (!(conversion_flags((int)instr->type)))
		instr->str = ft_char_to_string(instr->type);
}
