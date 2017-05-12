/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:33:29 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 15:35:28 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_type_ptr_zero_arg(t_instr *instr, void *arg)
{
	int		temp;

	if ((int)arg < 0)
		temp = (-1) * (int)arg;
	else if ((int)arg == 0)
		temp = 0;
	else
		temp = -1;
	instr->alter_form = 4;
	if (temp >= 0)
	{
		if (temp == 0 && instr->precision == 0)
		{
			instr->str = ft_strdup("");
			instr->precision = -1;
		}
		else
			instr->str = ft_itoa_base_usig((uintmax_t)arg, 16);
	}
	else
		instr->str = ft_itoa_base_usig((uintmax_t)arg, 16);
}

void				ft_type_ptr(t_instr *instr, va_list ap)
{
	if (instr->type == 'p')
		ft_type_ptr_zero_arg(instr, va_arg(ap, void*));
}

void				ft_bg_x(t_instr *instr, va_list ap)
{
	uintmax_t		arg;

	if (instr->type == 'X')
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
		instr->str = (arg == 0 && instr->precision == 0) ? char_is_zero(instr) : ft_str_capitalize(ft_itoa_base_usig(arg, 16));
		instr->alter_form = (arg == 0) ? 0 : instr->alter_form;
	}
}

void				ft_sml_x(t_instr *instr, va_list ap)
{
	uintmax_t		arg;

	if ((int)instr->type == 'x')
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
		instr->str = (instr->precision == 0 && arg == 0) ? ft_strdup("") : ft_strdup(ft_itoa_base_usig(arg, 16));
		instr->alter_form = ((instr->precision == 0 && arg == 0) || (arg == 0 && instr->alter_form)) ? 0 : instr->alter_form;
	}
}
