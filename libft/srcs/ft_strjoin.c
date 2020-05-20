/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:51:19 by jslave            #+#    #+#             */
/*   Updated: 2020/03/16 17:14:35 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_start_strings(const char *s1, const char *s2)
{
	if (s1 && s2)
		return (1);
	else
		exit(1);
	return (-1);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (check_start_strings(s1, s2) == 1)
	{
		if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
			return (NULL);
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			ptr[i] = s2[j];
			i++;
			j++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
