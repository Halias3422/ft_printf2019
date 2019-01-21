/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_flags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:57:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:09:59 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char				*flag_zero(t_data data, char *arg)
{
	int				i;

	i = 0;
	if (data.prec_dot == 0)
	{
		while (data.flag[i] && data.flag[i] != '-')
			i++;
	}
	if (data.flag[i] == '\0')
	{
		while (ft_strlen(arg) < (size_t)data.width)
			arg = add_char_begin_string(arg, "0");
	}
	return (arg);
}

char				*flag_minus(t_data data, char *arg)
{
	char			*right_width;
	int				i;
	char			*tmp;

	i = -1;
	right_width = ft_strnew(data.width);
	while (++i < (data.width - (int)ft_strlen(arg)))
		right_width[i] = ' ';
	tmp = arg;
	arg = ft_strjoin(arg, right_width);
	free(tmp);
	free (right_width);
	return (arg);
}

char			*flag_diez(t_data data, char *arg)
{
	char		*tmp;
	int			i;

	i = 0;
	if (data.conv_type == 3)
	{
		while (arg[i] && arg[i] != '.')
			i++;
		if (arg[i] == '\0')
			arg = add_char_end_string(arg, ".", 0);
	}
	else if ((data.conv_type == 6 && data.tmp_prec == '\0') ||
			data.conv_type == 8 || data.conv_type == 9)
	{
		tmp = arg;
		if (data.conv_type == 6)
			arg = ft_strjoin("0", arg);
		if (data.conv_type == 8)
			arg = ft_strjoin("0x", arg);
		if (data.conv_type == 9)
			arg = ft_strjoin("0X", arg);
		free (tmp);
	}
	return (arg);
}

char			*add_flag_to_conv(t_data data, char *arg)
{
	int			i;
	int			plus;

	plus = 0;
	i = -1;
	while (data.flag[++i])
	{
		if (data.flag[i] == '0')
			arg = flag_zero(data, arg);
		if (data.flag[i] == '+' && plus++ == 0)
		{
			if (arg[0] != '-' && data.conv_type >= 3 && data.conv_type <= 5)
			arg = add_char_begin_string(arg, "+");
		}
		else if (data.flag[i] == '-' && data.width != 0)
			arg = flag_minus(data, arg);
		else if (data.flag[i] == '#')
			arg = flag_diez(data, arg);
	}
	arg = handle_prec_and_width(data, arg);
	return (arg);
}
