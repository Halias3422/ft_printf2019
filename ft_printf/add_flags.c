/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_flags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:57:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 20:49:08 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char				*flag_zero(t_data data, char *arg)
{
	int				i;
	char			*tmp_arg;

	if (data.plus > 0)
	{
		tmp_arg = arg;
		arg = ft_copy_part_str(arg, 1, 1);
		free(tmp_arg);
	}
	i = 0;
	if (data.prec_dot == 0)
	{
		while (data.flag[i] && data.flag[i] != '-')
			i++;
	}
	if (data.flag[i] == '\0' && ft_strlen(arg) < (size_t)data.width)
	{
		while (ft_strlen(arg) < ((size_t)data.width - (size_t)data.plus -
				(size_t)data.space))
			arg = add_char_begin_string(arg, "0");
	}
	if (data.plus > 0)
		arg = add_char_begin_string(arg, "+");
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
		if (data.flag[find_space] == ' ')
			data.width--;
	}
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
	int			i;

	i = 0;
	if (data.conv_type == 3)
	{
		while (arg[i] && arg[i] != '.')
			i++;
		if (arg[i] == '\0')
			arg = add_char_end_string(arg, ".", 0);
	}
	else if ((data.conv_type == 6 && data.tmp_prec[0] == '\0') ||
			data.conv_type == 8 || data.conv_type == 9)
	{
		if (data.conv_type == 6 && ft_strcmp(arg, "0") != 0)
			arg = add_char_begin_string(arg, "0");
		if (data.conv_type == 8  && ft_strcmp(arg, "0") != 0)
			arg = add_char_begin_string(arg, "0x");
		if (data.conv_type == 9 && ft_strcmp(arg, "0") != 0)
			arg = add_char_begin_string(arg, "0X");
	}
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
	while (data.flag[++i])
	{
		if (data.flag[i] == '0')
			arg = flag_zero(data, arg);
		if (data.flag[i] == '+' && data.plus++ == 0)
		{
			if (arg[0] != '-' && data.conv_type >= 3 && data.conv_type <= 5)
				arg = add_char_begin_string(arg, "+");
		}
		else if (data.flag[i] == '-' && data.width != 0)
			arg = flag_minus(data, arg);
		else if (data.flag[i] == '#')
			arg = flag_diez(data, arg);
		if (data.flag[i] == ' '  && data.conv_type >= 3 && data.conv_type <= 5
				&& data.space++ == 0)
			arg = flag_space(data, arg);
	}
	arg = handle_width(data, arg);
	return (arg);
}