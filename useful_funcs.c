/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:35:27 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 14:39:29 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_wchar(int wchar)
{
	unsigned char	two_bytes[3];
	unsigned char	three_bytes[4];

	if (wchar < 128)
		return (ft_char_to_string(wchar));
	if (wchar > 127 && wchar < 2048)
	{
		two_bytes[0] = (wchar >> 6) + 192;
		two_bytes[1] = (wchar << 2);
		two_bytes[1] = (two_bytes[1] >> 2) + 128;
		two_bytes[2] = '\0';
		return (ft_strdup((char*)two_bytes));
	}
	three_bytes[0] = (wchar >> 12) + 224;
	three_bytes[1] = (wchar >> 6);
	three_bytes[1] = (three_bytes[1] << 2);
	three_bytes[1] = (three_bytes[1] >> 2) + 128;
	three_bytes[2] = wchar << 2;
	three_bytes[2] = (three_bytes[2] >> 2) + 128;
	three_bytes[3] = '\0';
	return (ft_strdup((char*)three_bytes));
}

char		*ft_wstr(int *arr, int precision)
{
	int			len;
	char		*symb;
	char		*str;
	size_t		counter;

	counter = -1;
	len = 0;
	str = ft_strdup("");
	while (arr[++counter])
	{
		symb = ft_wchar(arr[counter]);
		if (precision > 0)
		{
			len += ft_strlen(symb);
			if (len <= precision)
				str = ft_strjoin(str, symb);
		}
		else
			str = ft_strcat(str, symb);
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

void		ft_del_num(t_instruction *instruction, char *num)
{
	char	*temp;
	int		i;
	int		j;
	int		middle;

	middle = ft_strstr(instruction->str, num) - instruction->str;
	temp = (char*)malloc(ft_strlen(instruction->str) - ft_strlen(num) + 1);
	i = -1;
	j = -1;
	while (instruction->str[++i])
	{
		i += (i == middle) ? ft_strlen(num) : 0;
		temp[++j] = instruction->str[i];
	}
	free(instruction->str);
	temp[++j] = '\0';
	instruction->str = temp;
}

char		*rev_wstr(char *str)
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
