/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:51:41 by jslave            #+#    #+#             */
/*   Updated: 2020/02/09 19:51:48 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			handle_int_precision_uns(t_pf *pf, unsigned long long int num)
{
	char		*zero;
	int			len;

	len = ft_strlen(pf->filling);
	if (pf->precision > len)
	{
		zero = fill_zero_string(pf, len, num);
		pf->filling = ft_strjoinfree_both(zero, pf->filling);
	}
}

void			handle_int_width_and_precision_uns(t_pf *pf,
		unsigned long long int num)
{
	int len;

	handle_int_precision_uns(pf, num);
	len = ft_strlen(pf->filling);
	if (pf->width > pf->precision)
	{
		if (pf->precision != 0 && pf->precision != -1)
			turn_width_more_prec_uns(pf, len);
		else if (pf->precision <= 0 && num == 0)
		{
			ft_memdel((void **)&pf->filling);
			pf->filling = ft_strdup(pf->str_empty);
			if (pf->need_sign == 1 && pf->align_left != 1)
				pf->filling[ft_strlen(pf->filling) - 1] = '+';
			else if (pf->need_sign == 1 && pf->align_left == 1)
				pf->filling[0] = '+';
			pf->need_sign = 0;
		}
	}
	else
		handle_int_precision_uns(pf, num);
}
