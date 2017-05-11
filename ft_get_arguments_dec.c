/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments_dec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:36:27 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 15:38:10 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_d_and_i(t_instruction *instruction, va_list ap)
{
	intmax_t		arg;

	if (instruction->type == 'd' || instruction->type == 'i')
	{
		if (instruction->types == 6)
			arg = va_arg(ap, size_t);
		else if (instruction->types == 1)
			arg = (signed char)va_arg(ap, int);
		else if (instruction->types == 2)
			arg = (short int)va_arg(ap, int);
		else if (instruction->types == 3)
			arg = va_arg(ap, long int);
		else if (instruction->types == 4)
			arg = va_arg(ap, long long int);
		else if (instruction->types == 5)
			arg = va_arg(ap, intmax_t);
		else if (instruction->types == 7)
			arg = va_arg(ap, ptrdiff_t);
		else
			arg = va_arg(ap, int);
		instruction->ltz = (arg < 0) ? 1 : 0;
		arg = (instruction->ltz) ? -arg : arg;
		instruction->str = (arg == 0 && instruction->precision == 0) ? char_is_zero(instruction) : ft_strdup(ft_itoa_base_usig(arg, 10));
	}
}

void				ft_bg_d(t_instruction *instruction, va_list ap)
{
	long int		arg;

	if (instruction->type == 'D')
	{
		arg = va_arg(ap, long int);
		instruction->ltz = (arg < 0) ? 1 : 0;
		arg = (instruction->ltz) ? -arg : arg;
		instruction->str = (arg == 0 && instruction->precision == 0) ? char_is_zero(instruction) : ft_strdup(ft_itoa_base_usig(arg, 10));
	}
}

void				ft_sml_u(t_instruction *instruction, va_list ap)
{
	uintmax_t		arg;

	if (instruction->type == 'u')
	{
		arg = 0;
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
		instruction->str = (arg == 0 && instruction->precision == 0) ? char_is_zero(instruction) : ft_strdup(ft_itoa_base_usig(arg, 10));
	}
}

void				ft_bg_u(t_instruction *instruction, va_list ap)
{
	unsigned long int		arg;

	if (instruction->type == 'U')
	{
		arg = va_arg(ap, unsigned long int);
		instruction->str = (arg == 0 && instruction->precision == 0) ? char_is_zero(instruction) : ft_strdup(ft_itoa_base_usig(arg, 10));
	}
}
