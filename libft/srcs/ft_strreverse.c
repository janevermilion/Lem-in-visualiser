/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:01:42 by jslave            #+#    #+#             */
/*   Updated: 2020/01/26 20:01:44 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(char *str)
{
	int		i;
	int		j;
	char	a;
	size_t	len;

	if (str)
	{
		len = ft_strlen((const char *)str);
		i = 0;
		j = len - 1;
		while (i < j)
		{
			a = str[i];
			str[i] = str[j];
			str[j] = a;
			i++;
			j--;
		}
		return (str);
	}
	else
		return (NULL);
}
