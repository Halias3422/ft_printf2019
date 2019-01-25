/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_type2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 10:51:52 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 14:08:07 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char			*o_conv(va_list va, t_data *data)
{
	unsigned long long	nb;
	char		*num;
	int			i;

i = 0;
	if (data->length[0] == '\0')
		num = ft_itooct(nb = va_arg(va, unsigned int));
	else if (ft_strcmp(data->length, "hh") == 0)
		num = ft_itooct(nb = (unsigned char)va_arg(va, long long));
	else if (ft_strcmp(data->length, "h") == 0)
		num = ft_itooct(nb = (unsigned short)va_arg(va, long long));
	else if (ft_strcmp(data->length, "l") == 0)
		num = ft_itooct(nb = va_arg(va, unsigned long));
	else if (ft_strcmp(data->length, "ll") == 0)
		num = ft_itooct(nb = va_arg(va, unsigned long long));
	while (data->flag[i] && data->flag[i] != '#')
		i++;
	if (data->flag[i] == '\0' && nb == 0 && data->prec_dot == 1
			&& data->prec == 0)
	{
		num[0] = '\0';
		data->backslash++;
	}
	return (num);
}

char			*x_conv(va_list va, t_data *data)
{
	unsigned long long		nb;
	char		*num;

	if (data->length[0] == '\0')
		num = ft_itoh(nb = va_arg(va, unsigned int));
	else if (ft_strcmp(data->length, "hh") == 0)
		num = ft_itoh(nb = (unsigned char)va_arg(va, long));
	else if (ft_strcmp(data->length, "h") == 0)
		num = ft_itoh(nb = (unsigned short)va_arg(va, long));
	else if (ft_strcmp(data->length, "l") == 0)
		num = ft_itoh(nb = va_arg(va, unsigned long));
	else if (ft_strcmp(data->length, "ll") == 0)
		num = ft_itoh(nb = va_arg(va, unsigned long long));
	if (nb == 0 && data->prec_dot == 1 && data->prec == 0)
	{
		num[0] = '\0';
		data->backslash++;
	}
	return (num);
}

char			*X_conv(va_list va, t_data *data)
{
	unsigned long long	nb;
	char		*num;
	int			i;

	i = -1;
	if (data->length[0] == '\0')
		num = ft_itoh(nb = va_arg(va, unsigned int));
	else if (ft_strcmp(data->length, "hh") == 0)
		num = ft_itoh(nb = (unsigned char)va_arg(va, long));
	else if (ft_strcmp(data->length, "h") == 0)
		num = ft_itoh(nb = (unsigned short)va_arg(va, long));
	else if (ft_strcmp(data->length, "l") == 0)
		num = ft_itoh(nb = va_arg(va, unsigned long));
	else if (ft_strcmp(data->length, "ll") == 0)
		num = ft_itoh(nb = va_arg(va, unsigned long long));
	while (num[++i])
	{
		if (num[i] >= 'a' && num[i] <= 'f')
			num[i] = num[i] - 32;
	}
	return (num);
}

char			*f_conv(va_list va, t_data data)
{
	long double	nb;
	char		*num;

	if (data.length[0] == '\0' || ft_strcmp(data.length, "l") == 0)
		nb = va_arg(va, double);
	else if (ft_strcmp(data.length, "L") == 0)
		nb = va_arg(va, long double);
	num = handle_float(nb, data);
	return (num);
}

char			*pourcent_conv(t_data *data)
{
	char		*pourcent;

	pourcent = ft_strnew(1);
	pourcent[0] = '%';
	pourcent[1] = '\0';
	return (pourcent);
}
