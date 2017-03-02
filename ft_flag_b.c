/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:29:34 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/22 17:24:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				ft_flag_b(t_print ptf, unsigned int nb, char **str)
{
	int len;

	len = ft_intlen_base(nb, 2);
	ft_realloc_adr_p(str, len, ptf.ret);
	*str = ft_strcat_p(*str, ft_itoa_base(nb, 2), ptf.ret);
	return (len);
}