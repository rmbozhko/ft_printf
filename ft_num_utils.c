/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:00:16 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 15:10:40 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_convert_sig(intmax_t n, int base, char *str, int i)
{
	intmax_t	div;
	char		temp;

	div = 1;
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	while (n / div >= (intmax_t)base)
		div *= base;
	while (div > 0)
	{
		temp = '0' + n / div;
		str[i] = (temp > '9') ? (temp + 39) : temp;
		n %= div;
		div /= base;
		i++;
	}
	return (str);
}

static char			*ft_convert_usig(uintmax_t n, int base, char *str, int i)
{
	uintmax_t	div;
	char		temp;

	div = 1;
	while ((n / div) >= (uintmax_t)base)
		div *= base;
	while (div > 0)
	{
		temp = '0' + n / div;
		str[i] = (temp > '9') ? (temp + 39) : temp;
		n %= div;
		div /= base;
		i++;
	}
	return (str);
}

char				*ft_itoa_base_sig(intmax_t n, int base)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*str) * 20);
	i = 0;
	while (i < 20)
		str[i++] = '\0';
	i = 0;
	return (ft_convert_sig(n, base, str, i));
}

char				*ft_itoa_base_usig(uintmax_t n, int base)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * 20);
	i = 0;
	while (i < 20)
		str[i++] = '\0';
	i = 0;
	return (ft_convert_usig(n, base, str, i));
}
