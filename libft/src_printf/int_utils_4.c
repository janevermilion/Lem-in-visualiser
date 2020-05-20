/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:40:28 by jslave            #+#    #+#             */
/*   Updated: 2020/02/09 19:40:30 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			handle_int_width(t_pf *pf, long long int num)
{
	int len;

	len = ft_strlen(pf->filling);
	if (pf->width > len)
	{
		if (num < 0)
			fill_empty_str_neg_num(pf, len, num);
		else
			fill_empty_str_pos_num(pf, len);
		ft_memdel((void **)&pf->filling);
		pf->filling = ft_strdup(pf->str_empty);
	}
}

char			*fill_zero_string(t_pf *pf, int len, long long int num)
{
	char *zero;

	if (num < 0)
	{
		zero = ft_memalloc(sizeof(char) * (pf->precision - len + 2));
		ft_memset(zero, '0', pf->precision - len + 1);
	}
	else
	{
		zero = ft_memalloc(sizeof(char) * (pf->precision - len + 1));
		ft_memset(zero, '0', pf->precision - len);
	}
	return (zero);
}
