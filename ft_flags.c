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

void		zero_padding(t_instr *instr)
{
	int		i;

	i = -1;
	while (instr->str[++i])
	{
		if ((instr->str[i] == '0') && !(ft_isdigit(instr->str[i - 1]))
				&& (instr->str[i - 1] != '.'))
		{
			instr->padding = 1;
			break ;
		}
		else
			instr->padding = 0;
	}
}

void		sign_flag(t_instr *instr)
{
	if (ft_strchr(instr->str, '-') != NULL)
	{
		ft_del_chars(instr, "-");
		instr->minus_flag = 1;
	}
	else
		instr->minus_flag = 0;
	if (ft_strchr(instr->str, '+') != NULL && !TPCST_CHAR(instr->type))
	{
		ft_del_chars(instr, "+");
		instr->plus = 1;
	}
	else
		instr->plus = 0;
}

void		get_alterform(t_instr *instr)
{
	instr->alter_form = ((instr->type == 'x' || instr->type == 'X'
		|| instr->type == 'o' || instr->type == 'O')
		&& ft_strchr(instr->str, '#')) ? 1 : 0;
	ft_del_chars(instr, "#");
}

char		*get_width_perfomer(t_instr *instr, int i)
{
	int		k;
	char	*num;

	k = 0;
	num = (char*)malloc(ft_char_numlen(instr->str) + 1);
	while (ft_isdigit(instr->str[i]))
	{
		// printf("num:%c\n", instr->str[i]);
		num[k++] = instr->str[i++];
	}
	num[k] = '\0';
	// printf("width_str:%s\n", num);
	return (num);
}

void		get_width_contoller(t_instr *instr)
{
	int				i;
	intmax_t		width;
	int 			flag;

	i = -1;
	instr->width = 0;
	// write(1, "HERE\n", 5);
	// printf("str_width:%s\n", instr->str);
	while (instr->str[++i] && !(flag = 0))
	{
		if (instr->str[i] >= 49 && instr->str[i] <= 57)
		{
			// printf("char:%c\n", instr->str[i]);
			// if ((width = ft_atoi(get_width_perfomer(instr, i))) > 2147483647 || (width = ft_atoi(get_width_perfomer(instr, i))) < 0)
			// {
			// 	// printf("width_num:%d\n", width);
			// 	// write(1, "LOL\n", 4);
			// 	width = 0;
			// 	flag = 1;
			// 	break ;
			// }
			// printf("width:%d\n", width);
			width = ft_atoi_base(get_width_perfomer(instr, i), 10);
			i += ft_char_numlen(ft_itoa_base_usig(width, 10)) - 1;
			instr->width =
				(instr->str[i - ft_char_numlen(ft_itoa_base_usig(width, 10))] == '.')
				? instr->width : width;
		}
	}
	// printf("end_width:%d\n", width);
	instr->str = rev_wstr(instr->str);
	ft_del_num(instr, ft_itoa_base_usig(instr->width, 10));
	instr->str = rev_wstr(instr->str);
	instr->width = (instr->precision > 2147483647) ? 0 : instr->width;
	// write(1, "BAD\n", 4);
}
