/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_type3.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/30 13:49:55 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 14:47:59 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*b_conv(va_list va, t_data *data)
{
	unsigned long long	nb;
	char				*num;

	nb = va_arg(va, unsigned long long);
	num = ft_itoa_base_uns(nb, 2);
	return (num);
}
