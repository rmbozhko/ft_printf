/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments_octal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:30:59 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 15:33:08 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_sml_o(t_instr *instr, va_list ap)
{
	uintmax_t		arg;

	if (instr->type == 'o')
	{
		if (instr->types == 6)
			arg = va_arg(ap, size_t);
		else if (instr->types == 1)
			arg = (unsigned char)va_arg(ap, int);
		else if (instr->types == 2)
			arg = (unsigned short int)va_arg(ap, int);
		else if (instr->types == 3)
			arg = va_arg(ap, unsigned long int);
		else if (instr->types == 4)
			arg = va_arg(ap, unsigned long long int);
		else if (instr->types == 5)
			arg = va_arg(ap, uintmax_t);
		else if (instr->types == 7)
			arg = va_arg(ap, ptrdiff_t);
		else
			arg = va_arg(ap, unsigned int);
		instr->alter_form = (arg == 0
			&& (instr->precision != 0)) ? 0 : instr->alter_form;
		instr->str = (arg == 0 && instr->precision == 0)
			? char_is_zero(instr) : ft_strdup(ft_itoa_base_usig(arg, 8));
	}
}

void				ft_bg_o(t_instr *instr, va_list ap)
{
	uintmax_t		arg;

	if ((int)instr->type == 'O')
	{
		if (instr->types == 6)
			arg = va_arg(ap, size_t);
		else if (instr->types == 1)
			arg = va_arg(ap, unsigned int);
		else if (instr->types == 2)
			arg = va_arg(ap, unsigned int);
		else if (instr->types == 3)
			arg = va_arg(ap, unsigned long int);
		else if (instr->types == 4)
			arg = va_arg(ap, unsigned long long int);
		else if (instr->types == 5)
			arg = va_arg(ap, uintmax_t);
		else
			arg = va_arg(ap, unsigned long int);
		instr->alter_form = (arg == 0
			&& (instr->precision != 0)) ? 0 : instr->alter_form;
		instr->str = (arg == 0 && instr->precision == 0)
			? char_is_zero(instr) : ft_strdup(ft_itoa_base_usig(arg, 8));
	}
}
