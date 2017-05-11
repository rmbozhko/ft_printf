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

void				ft_sml_o(t_instruction *instruction, va_list ap)
{
	uintmax_t		arg;

	if (instruction->type == 'o')
	{
		if (instruction->types == 6)
			arg = va_arg(ap, size_t);
		else if (instruction->types == 1)
			arg = (unsigned char)va_arg(ap, int);
		else if (instruction->types == 2)
			arg = (unsigned short int)va_arg(ap, int);
		else if (instruction->types == 3)
			arg = va_arg(ap, unsigned long int);
		else if (instruction->types == 4)
			arg = va_arg(ap, unsigned long long int);
		else if (instruction->types == 5)
			arg = va_arg(ap, uintmax_t);
		else if (instruction->types == 7)
			arg = va_arg(ap, ptrdiff_t);
		else
			arg = va_arg(ap, unsigned int);
		instruction->alternative_form = (arg == 0 && (instruction->precision != 0)) ? 0 : instruction->alternative_form;
		instruction->str = (arg == 0 && instruction->precision == 0) ? char_is_zero(instruction) : ft_strdup(ft_itoa_base_usig(arg, 8));
	}
}

void				ft_bg_o(t_instruction *instruction, va_list ap)
{
	uintmax_t		arg;

	if ((int)instruction->type == 'O')
	{
		if (instruction->types == 6)
			arg = va_arg(ap, size_t);
		else if (instruction->types == 1)
			arg = va_arg(ap, unsigned int);
		else if (instruction->types == 2)
			arg = va_arg(ap, unsigned int);
		else if (instruction->types == 3)
			arg = va_arg(ap, unsigned long int);
		else if (instruction->types == 4)
			arg = va_arg(ap, unsigned long long int);
		else if (instruction->types == 5)
			arg = va_arg(ap, uintmax_t);
		else
			arg = va_arg(ap, unsigned long int);
		instruction->alternative_form = (arg == 0 && (instruction->precision != 0)) ? 0 : instruction->alternative_form;
		instruction->str = (arg == 0 && instruction->precision == 0) ? char_is_zero(instruction) : ft_strdup(ft_itoa_base_usig(arg, 8));
	}
}
