/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:30:18 by jslave            #+#    #+#             */
/*   Updated: 2020/01/26 20:30:20 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static char			*check_validity_ll(long long int n)
{
	long long int		min;
	char				*res;
	long long int		max;

	min = LLONG_MIN;
	max = LLONG_MAX;
	res = NULL;
	if (n <= min)
		return (res = ft_strdup("-9223372036854775808"));
	if (n < min)
		return (res);
	if (n == 0)
	{
		res = ft_strdup("0");
		return (res);
	}
	if ((n > min && n < 0) || (n > 0 && n <= max))
		res = ft_strnew(find_len_of_num(n));
	return (res);
}

static char			*check_validity(long long int n)
{
	long long int		min;
	char				*res;
	long long int		max;

	min = LLONG_MIN;
	max = LLONG_MAX;
	res = NULL;
	if (n <= min)
		return (res = ft_strdup("−2147483648"));
	if (n < min)
		return (res);
	if (n == 0)
	{
		res = ft_strdup("0");
		return (res);
	}
	if ((n > min && n < 0) || (n > 0 && n <= max))
		res = ft_strnew(find_len_of_num(n));
	return (res);
}

char				*ft_itoa_long_long(long long int n)
{
	char				*res;
	size_t				i;
	long long int		sign;
	size_t				len;

	res = check_validity_ll(n);
	i = 0;
	len = find_len_of_num(n);
	if (res && n != LLONG_MIN && n != 0)
	{
		if ((sign = n) < 0)
		{
			res[i + len - 1] = '-';
			n = -n;
			len--;
		}
		while (i < len)
		{
			res[i++] = n % 10 + '0';
			n /= 10;
		}
		ft_strreverse(res);
	}
	return (res);
}

char				*ft_itoa_long_long_uns(unsigned long long int n)
{
	char		*res;
	size_t		i;
	size_t		len;

	res = check_validity(n);
	i = 0;
	len = find_len_of_num(n);
	if (res && n != 0)
	{
		while (i < len)
		{
			res[i++] = n % 10 + '0';
			n /= 10;
		}
		ft_strreverse(res);
	}
	return (res);
}
