/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/10 18:42:56 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_flag_d(t_print ptf, int nb, char **str)
{
	int		len;
	int		i;

	len = ft_convert_len_acc(ptf, nb);
	ft_realloc_adr(str, len);
	len = ft_convert_signe(str, ptf);
	if (ptf.moins == 1)
	{
		if (ptf.accuracy > 0)
			*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen(nb));
		*str = ft_strcat(*str, ft_itoa(nb));
		if (ptf.accuracy == 0)
			*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen(nb) - len);
		else
			*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	}
	else
	{
		if (ptf.accuracy == 0)
			*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen(nb) - len);
		else
			*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen(nb));
		*str = ft_strcat(*str, ft_itoa(nb));
	}
	return (len);
}
