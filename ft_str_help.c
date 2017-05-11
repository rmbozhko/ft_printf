/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:48:11 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 14:53:18 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_omit_zeros(char *str, int counter)
{
	while (str[counter] == '0')
		counter++;
	return (counter);
}

int				ft_char_numlen(char *str)
{
	int counter;
	int i;

	i = -1;
	counter = 0;
	while (ft_isdigit(str[++i]))
		counter++;
	return (counter);
}

static int		ft_strlen_mod(char *str, char *ltrs_to_omit)
{
	int		counter;
	int		i;

	i = -1;
	counter = 0;
	while (str[++i])
		(!(ft_strchr(ltrs_to_omit, str[i])) ? counter++ : 0);
	return (counter);
}

void			ft_del_chars(t_instruction *instruction, char *omit_chr)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char*)malloc(ft_strlen_mod(instruction->str, omit_chr) + 1);
	i = -1;
	j = -1;
	while (instruction->str[++i])
		(!(ft_strchr(omit_chr, instruction->str[i])) ? tmp[++j] = instruction->str[i] : 0);
	free(instruction->str);
	tmp[++j] = '\0';
	instruction->str = tmp;
}
