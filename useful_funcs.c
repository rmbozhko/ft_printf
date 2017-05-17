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

static int	ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

intmax_t	ft_atoi_base(char *str, int base)
{
	intmax_t	value;
	int 		sign;

	value = 0;
	if (base <= 1 || base > 36)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'A' >= 0)
			value = value * base + (*str - 'A' + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * sign);
}

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

void		ft_del_num(t_instr *instr, char *num)
{
	char	*temp;
	int		i;
	int		j;
	int		middle;

	middle = ft_strstr(instr->str, num) - instr->str;
	temp = (char*)malloc(ft_strlen(instr->str) - ft_strlen(num) + 1);
	i = -1;
	j = -1;
	while (instr->str[++i])
	{
		i += (i == middle) ? ft_strlen(num) : 0;
		temp[++j] = instr->str[i];
	}
	free(instr->str);
	temp[++j] = '\0';
	instr->str = temp;
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
