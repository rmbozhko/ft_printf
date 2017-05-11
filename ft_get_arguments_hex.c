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

void				ft_type_ptr_zero_arg(t_instruction *instruction, void *arg)
{
	int		temp;

	if ((int)arg < 0)
		temp = (-1) * (int)arg;
	else if ((int)arg == 0)
		temp = 0;
	else
		temp = -1;
	instruction->alternative_form = 4;
	if (temp >= 0)
	{
		if (temp == 0 && instruction->precision == 0)
		{
			instruction->str = ft_strdup("");
			instruction->precision = -1;
		}
		else
			instruction->str = ft_itoa_base_usig((uintmax_t)arg, 16);
	}
	else
		instruction->str = ft_itoa_base_usig((uintmax_t)arg, 16);
}

void				ft_type_ptr(t_instruction *instruction, va_list ap)
{
	if (instruction->type == 'p')
		ft_type_ptr_zero_arg(instruction, va_arg(ap, void*));
}

void				ft_bg_x(t_instruction *instruction, va_list ap)
{
	uintmax_t		arg;

	if (instruction->type == 'X')
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
		instruction->str = (arg == 0 && instruction->precision == 0) ? char_is_zero(instruction) : ft_str_capitalize(ft_itoa_base_usig(arg, 16));
		instruction->alternative_form = (arg == 0) ? 0 : instruction->alternative_form;
	}
}

void				ft_sml_x(t_instruction *instruction, va_list ap)
{
	uintmax_t		arg;

	if ((int)instruction->type == 'x')
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
		instruction->str = (instruction->precision == 0 && arg == 0) ? ft_strdup("") : ft_strdup(ft_itoa_base_usig(arg, 16));
		instruction->alternative_form = ((instruction->precision == 0 && arg == 0) || (arg == 0 && instruction->alternative_form)) ? 0 : instruction->alternative_form;
	}
}
