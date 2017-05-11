/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:59:24 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/11 14:59:52 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int end, short int flag)
{
	int		i;

	i = 0;
	while (i < end)
	{
		ft_putchar_mod(str[i], flag);
		i++;
	}
}

void	ft_putstring(char const *s, short int flag)
{
	size_t		i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_putchar_mod(s[i], flag);
	}
}

int		ft_putchar_mod(char c, short int flag)
{
	static int	counter = 0;
	int			temp;

	(!flag) ? write(1, &c, 1) : 0;
	counter++;
	if (flag)
	{
		temp = --counter;
		counter = 0;
		return (temp);
	}
	else
		return (0);
}
