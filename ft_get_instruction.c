/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:19:26 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 15:25:01 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_allowed_stuff(char c)
{
	return ((sym_flags(c) || cast_flags(c) || (c >= 48 && c <= 57)) ? 1 : 0);
}

t_instr		*ft_printf_validing(const char *str, t_instr *instr)
{
	int		i;

	i = 0;
	while (str[++i] && !(conversion_flags(str[i])) && (ft_allowed_stuff(str[i])))
		;
	if (str[i] == '\0')
		return (NULL);
	instr->str = ft_strsub(str, 0, i + 1);
	instr->instruct_len = i + 1;
	return (instr);
}
