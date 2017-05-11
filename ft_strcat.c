/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:45:22 by rbozhko           #+#    #+#             */
/*   Updated: 2016/12/25 16:02:33 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(dest);
	k = 0;
	// printf("src:[%s: %d]\n", src, ft_strlen(src));
	// printf("dest:[%s]\n", dest);
	// printf("i_len:%d\n", i);
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		k++;
		i++;
		// write(1, "HURA12\n", 7);
	}
	dest[i] = '\0';
	// printf("strings:%s\n", dest);
	return (dest);
}
