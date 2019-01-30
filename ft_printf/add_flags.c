/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_flags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:57:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 13:03:17 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char				*flag_zero(t_data data, char *arg)
{
	int				i;
	size_t			tmp_plus;

	tmp_plus = 0;
	if (is_contained_in("+", data.flag, 0) == 1 && arg[0] != '-')
		tmp_plus++;
	i = 0;
	arg = handle_plus_minus_with_zero(data, arg);
	if (data.prec_dot == 0 || data.conv_type == 0)
	{
		while (data.flag[i] && data.flag[i] != '-')
			i++;
	}
	if (data.flag[i] == '\0' && ft_strlen(arg) < (size_t)data.width)
	{
		while (ft_strlen(arg) < ((size_t)data.width - tmp_plus -
				(size_t)data.space) - (size_t)data.minus - data.diez_length)
			arg = add_char_begin_string(arg, "0");
	}
	if (data.plus > 0)
		arg = add_char_begin_string(arg, "+");
	else if (data.minus > 0)
		arg = add_char_begin_string(arg, "-");
	return (arg);
}

char				*flag_minus(t_data data, char *arg)
{
	char			*right_width;
	int				i;
	char			*tmp;
	int				find_space;
	
	find_space = -1;
	while (data.flag[++find_space])
	{
		if (data.flag[find_space] == ' ' || (data.flag[find_space] == '+' && data.f_nan != 1 && data.plus != 1 && data.f_inf != 1))
			data.width--;
	}
	i = -1;
	right_width = ft_strnew(data.width);
	while (++i < (data.width - (int)ft_strlen(arg)))
	{
		if ((((is_contained_in("+", data.flag, 0) == 1) && data.f_inf == 1) || (is_contained_in("#", data.flag, 0) == 1 && data.conv_type == 6 && data.diez_length == 0))  && i  == (data.width - (int)ft_strlen(arg) - 1))
			break;
			right_width[i] = ' ';
	}
	tmp = arg;
	arg = ft_strjoin(arg, right_width);
	free(tmp);
	free (right_width);
	return (arg);
}

char			*flag_diez(t_data *data, char *arg)
{
	int			i;

	i = 0;
	if (data->conv_type == 3)
	{
		while (arg[i] && arg[i] != '.')
			i++;
		if (arg[i] == '\0')
			arg = add_char_end_string(arg, ".", 0);
	}
	else if ((data->conv_type == 6 && data->tmp_prec[0] == '\0')||
			data->conv_type == 8 || data->conv_type == 9)
	{
		if (is_contained_in("0", data->flag, 0) == 1)
		{
			data->zero++;
			data->diez_length = 2;
			if (data->conv_type == 6)
				data->diez_length = 1;
			arg = flag_zero(*data, arg);
		}
		if (data->conv_type == 6 && ft_strcmp(arg, "0") != 0)
			arg = add_char_begin_string(arg, "0");
		if (data->conv_type == 8 && ft_strcmp(arg, "0") != 0 && ft_strcmp(arg, "") != 0)
			arg = add_char_begin_string(arg, "0x");
		if (data->conv_type == 9 && ft_strcmp(arg, "0") != 0 && ft_strcmp(arg, "") != 0)
			arg = add_char_begin_string(arg, "0X");
	}
	data->diez_length = 1;
	return (arg);
}

char			*flag_space(t_data data, char *arg)
{
	int			i;
	int			find_zero;

	find_zero = -1;
	if (data.zero == 0)
	{
		while (data.flag[++find_zero])
		{
			if (data.flag[find_zero] == '0')
			{
				arg = flag_zero(data, arg);
				data.zero++;
			}
		}
	}
	i = -1;
	while (data.flag[++i])
	{
		if (data.flag[i] == '+')
			return (arg);
	}
	if (arg[0] != '-')
		arg = add_char_begin_string(arg, " ");
	return (arg);
}

char			*add_flag_to_conv(t_data data, char *arg)
{
	int			i;

	data.plus = 0;
	data.space = 0;
	data.zero = 0;
	i = -1;
	arg = handle_prec(data, arg);
	while (data.flag[++i] && (ft_strlen(arg) >= 1 || data.args_nb > 0))
	{
		if (data.flag[i] == '0' && data.zero == 0)
			arg = flag_zero(data, arg);
		if (data.flag[i] == '+' && data.plus++ == 0)
		{
			if (arg[0] != '-' && data.conv_type >= 3 && data.conv_type <= 5 && data.f_nan != 1)
				arg = add_char_begin_string(arg, "+");
		}
		else if (data.flag[i] == '-' && data.width != 0)
			arg = flag_minus(data, arg);
		else if (data.flag[i] == '#')
			arg = flag_diez(&data, arg);
		if (data.flag[i] == ' '  && data.conv_type >= 3 && data.conv_type <= 5
				&& data.space++ == 0)
			arg = flag_space(data, arg);
	}
	arg = handle_width(data, arg);
	return (arg);
}
