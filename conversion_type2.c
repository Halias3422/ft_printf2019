/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_type2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 10:51:52 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 11:13:43 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char			*o_conv(va_list va)
{
	long long	nb;
	char		*num;

	num = ft_itooct(nb = va_arg(va, long long));
	return (num);
}

char			*x_conv(va_list va)
{
	long long	nb;
	char		*num;

	num = ft_itoh(nb = va_arg(va, long long));
	return (num);
}

char			*X_conv(va_list va)
{
	long long	nb;
	char		*num;
	int			i;

	i = -1;
	num = ft_itoh(nb = va_arg(va, long long));
	while (num[++i])
	{
		if (num[i] >= 'a' && num[i] <= 'f')
			num[i] = num[i] - 32;
	}
	return (num);
}
