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
	ft_set_instruct_type(instr, ap);
	ft_apply_instruct_flags(instr);
}

t_instr		*ft_printf_parse_controller(va_list ap, t_instr *instr)
{
	get_precision_sign(instr);
	get_width_contoller(instr);
	zero_padding(instr);
	get_instruct_type(instr);
	get_alterform(instr);
	sign_flag(instr);
	get_typecast_ltrs(instr);
	get_spaces_instruction(instr);
	ft_del_chars(instr, "0123456789");
	ft_del_chars(instr, ".");
	ft_applying_existing_flags(ap, instr);
	ft_putstring(instr->str, 0);
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
