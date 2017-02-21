/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hhd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/17 09:37:02 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, int nb, int len)
{
	unsigned int unb;

	unb = (nb < 0) ? (unsigned int)-nb : nb;
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_u(unb));
	*str = ft_strcat(*str, ft_itoa_u(unb));
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_u(unb) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, int nb, int len)
{
	unsigned int unb;

	unb = (nb < 0) ? (unsigned int)-nb : nb;
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_u(unb) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_u(unb) - len);
	*str = ft_strcat(*str, ft_itoa_u(unb));
}

static int	ft_convert_len_acc(t_print ptf, int nb)
{
	int len;

	len = ft_intlen(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	else if ((ptf.space == 1 || ptf.plus == 1) && nb >= 0)
		len++;
	return (len);
}

int			ft_flag_hhd(t_print ptf, int nb, char **str)
{
	int		len;
	int		i;

	len = ft_convert_len_acc(ptf, nb);
	ft_realloc_adr(str, len);
	i = ft_convert_signe(str, ptf , nb);
	i += (nb < 0) ? 1 : 0;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	return (len);
}