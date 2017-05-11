/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:30:17 by rbozhko           #+#    #+#             */
/*   Updated: 2017/04/15 18:05:45 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	char 	*test;

	if (s1 && s2)
	{
		// temp = NULL;
		temp = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		// temp[ft_strlen(s1) + ft_strlen(s2)] = '\0';
		if (temp)
		{
			test = ft_strdup(s2);
			// printf("len_s2:%d\n", ft_strlen(s2));
			temp = ft_strcpy(temp, s1);
			// printf("tem:%s\n", s2);
			// printf("temp:[%s]\n", temp);
			//free((void*)s1);
			temp = ft_strcat(temp, test);
			//free((void*)s2);
			// printf("len_temp:%d\n", ft_strlen(temp));
			return (temp);
		}
	}
	return (NULL);
}
