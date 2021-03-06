/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:48:11 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/18 16:01:08 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_omit_zeros(char *str, int counter)
{
	int		i;

	i = 0;
	(str[counter + 1] == '0') ? counter++ : 0;
	while (str[counter] == '0')
	{
		i++;
		counter++;
	}
	return (i);
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

void			ft_del_chars(t_instr *instr, char *omit_chr)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char*)malloc(ft_strlen_mod(instr->str, omit_chr) + 1);
	i = -1;
	j = -1;
	while (instr->str[++i])
		(!(ft_strchr(omit_chr, instr->str[i])) ? tmp[++j] = instr->str[i] : 0);
	free(instr->str);
	tmp[++j] = '\0';
	instr->str = tmp;
}

char			*rev_wstr(char *str)
{
	char	c;
	char	*temp;
	int		i;
	int		j;

	j = -1;
	i = ft_strlen(str) - 1;
	temp = (char*)malloc(i + 1);
	while (i > -1)
	{
		c = str[i--];
		temp[++j] = c;
	}
	temp[++j] = '\0';
	return (temp);
}
