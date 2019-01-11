/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_flags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:57:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 17:13:22 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char				*flag_minus(t_data data, char *arg)
{
	char			*right_width;
	unsigned long	i;

	i = -1;
	right_width = ft_strnew(data.width);
	while (++i < (data.width - ft_strlen(arg)))
		right_width[i] = ' ';
	arg = ft_strjoin(arg, right_width);
	free (right_width);
	return (arg);
}

char			*flag_diez(t_data data, char *arg)
{
	if (data.conv_type == 6 && ft_strlen(data.tmp_prec) == 0)
		arg = ft_strjoin("0", arg);
	if (data.conv_type == 8)
		arg = ft_strjoin("0x", arg);
	if (data.conv_type == 9)
		arg = ft_strjoin("0X", arg);
	return (arg);
}

char			*add_flag_to_conv(t_data data, char *arg)
{
	int			i;

	i = -1;
	while (data.flag[++i])
	{
		//if (data.flag[i] == '0')

		if (data.flag[i] == '+')
		{
			if (arg[0] != '-')
			{
				add_char_begin_string(arg, "+");
			}
		}
		else if (data.flag[i] == '-' && ft_strlen(data.tmp_width) != 0)
			arg = flag_minus(data, arg);
		else if (data.flag[i] == '#')
			arg = flag_diez(data, arg);
	}
	return (arg);
}
