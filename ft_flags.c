/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:42:01 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 15:50:56 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zero_padding(t_instruction *instruction)
{
	int		i;

	i = -1;
	while (instruction->str[++i])
	{
		if ((instruction->str[i] == '0') && !(ft_isdigit(instruction->str[i - 1]))
				&& (instruction->str[i - 1] != '.'))
		{
			instruction->zero_padding = 1;
			break ;
		}
		else
			instruction->zero_padding = 0;
	}
}

void		sign_flag(t_instruction *instruction)
{
	if (ft_strchr(instruction->str, '-') != NULL)
	{
		ft_del_chars(instruction, "-");
		instruction->minus_flag = 1;
	}
	else
		instruction->minus_flag = 0;
	if (ft_strchr(instruction->str, '+') != NULL && !typecast_flags_char(instruction->type))
	{
		ft_del_chars(instruction, "+");
		instruction->plus = 1;
	}
	else
		instruction->plus = 0;
}

void		get_alterform(t_instruction *instruction)
{
	instruction->alternative_form = ((instruction->type == 'x' || instruction->type == 'X' ||
				instruction->type == 'o' || instruction->type == 'O') && ft_strchr(instruction->str, '#')) ? 1 : 0;
	ft_del_chars(instruction, "#");
}

char		*get_width_perfomer(t_instruction *instruction, int i)
{
	int		k;
	char	*num;

	k = 0;
	num = (char*)malloc(ft_char_numlen(instruction->str) + 1);
	// write(1, "OLA\n", 4);
	while (ft_isdigit(instruction->str[i]))
	{
		// write(1, "HEy\n", 4);
		num[k++] = instruction->str[i++];
	}
	num[k] = '\0';
	return (num);
}

void		get_width_contoller(t_instruction *instruction)
{
	int		i;
	int		width;

	i = -1;
	instruction->width = 0;
	while (instruction->str[++i])
	{
		if (instruction->str[i] >= 49 && instruction->str[i] <= 57)
		{
			// write(1, "HERE\n", 5);
			width = ((width = ft_atoi(get_width_perfomer(instruction, i))) < 0) ? 0 : width;
			//width = ft_atoi(get_width_perfomer(instruction, i));
			//width = (width < 0) ? 0 : width;
			// printf("numlen:%d\n", ft_char_numlen(ft_itoa(width)));
			i += ft_char_numlen(ft_itoa(width)) - 1;
			instruction->width = (instruction->str[i - ft_char_numlen(ft_itoa(width))] == '.') ? instruction->width : width;
		}
	}
	// write(1, "HAHA\n", 5);
	instruction->str = rev_wstr(instruction->str);
	ft_del_num(instruction, rev_wstr(ft_itoa(instruction->width)));
	instruction->str = rev_wstr(instruction->str);
	// write(1, "lol\n", 4);
}
