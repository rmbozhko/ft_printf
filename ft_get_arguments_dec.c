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

void				ft_d_and_i(t_instr *instr, va_list ap)
{
	intmax_t		arg;

	if (instr->type == 'd' || instr->type == 'i')
	{
		// printf("HEER!\n");
		if (instr->types == 6)
			arg = va_arg(ap, size_t);
		else if (instr->types == 1)
			arg = (signed char)va_arg(ap, int);
		else if (instr->types == 2)
			arg = (short int)va_arg(ap, int);
		else if (instr->types == 3)
			arg = va_arg(ap, long int);
		else if (instr->types == 4)
			arg = va_arg(ap, long long int);
		else if (instr->types == 5)
			arg = va_arg(ap, intmax_t);
		else if (instr->types == 7)
			arg = va_arg(ap, ptrdiff_t);
		else
			arg = va_arg(ap, int);
		instr->ltz = (arg < 0) ? 1 : 0;
		arg = (instr->ltz) ? -arg : arg;
		instr->str = (arg == 0 && instr->precision == 0)
			? char_is_zero(instr) : ft_strdup(ft_itoa_base_usig(arg, 10));
		// printf("temp:%s\n", instr->str);
	}
}

void				ft_bg_d(t_instr *instr, va_list ap)
{
	long int		arg;

	if (instr->type == 'D')
	{
		arg = va_arg(ap, long int);
		instr->ltz = (arg < 0) ? 1 : 0;
		arg = (instr->ltz) ? -arg : arg;
		instr->str = (arg == 0 && instr->precision == 0)
			? char_is_zero(instr) : ft_strdup(ft_itoa_base_usig(arg, 10));
	}
}

void				ft_sml_u(t_instr *instr, va_list ap)
{
	uintmax_t		arg;

	if (instr->type == 'u')
	{
		arg = 0;
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
		instr->str = (arg == 0 && instr->precision == 0)
			? char_is_zero(instr) : ft_strdup(ft_itoa_base_usig(arg, 10));
	}
}

void				ft_bg_u(t_instr *instr, va_list ap)
{
	unsigned long int		arg;

	if (instr->type == 'U')
	{
		arg = va_arg(ap, unsigned long int);
		instr->str = (arg == 0 && instr->precision == 0)
			? char_is_zero(instr) : ft_strdup(ft_itoa_base_usig(arg, 10));
	}
}
