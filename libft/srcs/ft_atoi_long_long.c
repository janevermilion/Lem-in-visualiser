/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:55:55 by jslave            #+#    #+#             */
/*   Updated: 2020/03/16 17:00:28 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int			ft_return(unsigned long long int res,
		long long int neg)
{
	if (res >= 9223372036854775807 && neg == 1)
		return (-1);
	if (res >= 9223372036854775807 && neg == -1)
		return (0);
	return (res * neg);
}

unsigned long long int			ft_atoi_long_long_uns(const char *str)
{
	int							i;
	unsigned long long int		result;
	long long int				neg;

	result = 0;
	i = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_return(result, neg));
}

long long int					ft_atoi_long_long(const char *str)
{
	int					i;
	long long int		result;
	long long int		neg;

	result = 0;
	i = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_return(result, neg));
}
