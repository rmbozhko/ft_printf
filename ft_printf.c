/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:55:05 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 14:57:41 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_applying_existing_flags(va_list ap, t_instruction *instruction)
{
	ft_set_instruct_type(instruction, ap);
	ft_apply_instruct_flags(instruction);
}

t_instruction		*ft_printf_parse_controller(va_list ap, t_instruction *instruction)
{
	get_precision_sign(instruction);
	get_width_contoller(instruction);
	zero_padding(instruction);
	get_instruct_type(instruction);
	get_alterform(instruction);
	sign_flag(instruction);
	get_typecast_ltrs(instruction);
	get_spaces_instruction(instruction);
	ft_del_chars(instruction, "0123456789");
	ft_del_chars(instruction, ".");
	ft_applying_existing_flags(ap, instruction);
	ft_putstring(instruction->str, 0);
	(instruction->type == 'c' && instruction->alternative_form) ? ft_putchar_mod(0, 0) : 0;
	return (instruction);
}

void				ft_printf_processing(const char *str, va_list ap, t_instruction *instruction)
{
	char		*temp;

	temp = ft_strchr(str, '%');
	if (temp == NULL)
		ft_putstring(str, 0);
	else if (temp > str)
	{
		ft_putnstr((char*)str, (temp - str), 0);
		return (ft_printf_processing(temp, ap, instruction));
	}
	else
	{
		if (ft_printf_validing(str, instruction) != NULL)
		{
			if (ft_printf_parse_controller(ap, instruction))
				ft_printf_processing(str += instruction->instruct_len, ap, instruction);
		}
		else
			return ;
	}
}

int					ft_printf(const char *str, ...)
{
	va_list			ap;
	t_instruction	instruction;

	instruction.ltz = 0;
	instruction.types = 0;
	setlocale(LC_ALL, "");
	if (*str == '\0')
		return (0);
	else if (str == NULL)
		return (-1);
	va_start(ap, str);
	ft_printf_processing(str, ap, &instruction);
	va_end(ap);
	return (ft_putchar_mod(0, 1));
}
