/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:40:15 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 14:46:47 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_count_alpha(char *str, char c)
{
	int		i;
	int		counter;

	i = -1;
	counter = 0;
	while (str[++i])
		(str[i] == c) ? counter++ : 0;
	return (counter);
}

char		*ft_mutiply_str(char *str, uintmax_t times)
{
	uintmax_t		i;
	char			*tmp;

	i = 0;
	tmp = (char*)malloc(times + 1);
	while (i < times)
	{
		tmp[i++] = str[0];
	}
	tmp[i] = '\0';
	return (tmp);
}

char		*ft_char_to_string(int c)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(int) + 1);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

char		*ft_str_capitalize(char *str)
{
	int		i;
	char	*temp;

	temp = (char*)malloc(ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			temp[i] = str[i] - 32;
		else
			temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char		*ft_strncpy_mod(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	dst[i] = '\0';
	return (dst);
}
