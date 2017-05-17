/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:55:05 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/12 13:01:41 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_applying_existing_flags(va_list ap, t_instr *instr)
{

	// write(1, "BAD12\n", 6);
	ft_set_instruct_type(instr, ap);
	// printf("%s\n", instr->str);
	// write(1, "BAD21\n", 6);
	ft_apply_instruct_flags(instr);
	// printf("%s\n", instr->str);
	// write(1, "BAD121\n", 7);
}

t_instr		*ft_printf_parse_controller(va_list ap, t_instr *instr)
{
	// write(1, "LOL\n", 4);
	get_precision_sign(instr);
	// printf("%d\n", instr->precision);
	// printf("str1:%s\n", instr->str);
	// write(1, "BAD4\n", 5);
	get_width_contoller(instr);
	// write(1, "BAD2\n", 5);
	// printf("str:%s\n", instr->str);
	zero_padding(instr);
	// write(1, "BAD1\n", 5);
	get_instruct_type(instr);
	// write(1, "BAD3\n", 5);
	get_alterform(instr);
	// write(1, "BAD4\n", 5);
	sign_flag(instr);
	// write(1, "BAD5\n", 5);
	get_typecast_ltrs(instr);
	// write(1, "BAD6\n", 5);
	get_spaces_instruction(instr);
	// write(1, "BAD7\n", 5);
	ft_del_chars(instr, "0123456789");
	// write(1, "BAD8\n", 5);
	ft_del_chars(instr, ".");
	// write(1, "BAD9\n", 5);
	ft_applying_existing_flags(ap, instr);
	// write(1, "BADA\n", 5);
	ft_putstring(instr->str, 0);
	// write(1, "BADB\n", 5);
	(instr->type == 'c' && instr->alter_form) ? ft_putchar_mod(0, 0) : 0;
	return (instr);
}

void		ft_printf_processing(const char *str, va_list ap, t_instr *instr)
{
	char		*temp;

	temp = ft_strchr(str, '%');
	if (temp == NULL)
		ft_putstring(str, 0);
	else if (temp > str)
	{
		ft_putnstr((char*)str, (temp - str), 0);
		return (ft_printf_processing(temp, ap, instr));
	}
	else
	{
		if (ft_printf_validing(str, instr) != NULL)
		{
			if (ft_printf_parse_controller(ap, instr))
				ft_printf_processing(str += instr->instruct_len, ap, instr);
		}
		else
			return ;
	}
}

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	t_instr		instr;

	instr.ltz = 0;
	instr.types = 0;
	setlocale(LC_ALL, "");
	if (*str == '\0')
		return (0);
	else if (str == NULL)
		return (-1);
	va_start(ap, str);
	ft_printf_processing(str, ap, &instr);
	va_end(ap);
	return (ft_putchar_mod(0, 1));
}
