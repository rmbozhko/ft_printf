/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:34:21 by ybelilov          #+#    #+#             */
/*   Updated: 2017/05/18 16:00:44 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int			i;
	char		nb;
	long int	res;
	char		*temp;

	i = 0;
	res = 0;
	nb = '\0';
	temp = ft_strdup(str);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' ||
				str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	(str[i] == '-') ? nb = '-' : 0;
	(str[i] == '+') ? nb = '+' : 0;
	if (nb)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((nb == '-') ? res * (-1) : (res));
}
