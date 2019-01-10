/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_conversion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:14:09 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 17:17:15 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_flag_to_conv(t_data data, char *arg)
{
	int		i;

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
		/*else if (data.flag[i] == '-')

		else if (data.flag[i] == '#')*/

	}
	return (arg);
}

/*
**	INIT OF ARRAY OF POINTER ON FT AND SELECTING ACCORDING FT
*/

char		*conversion_type(int conv_type, va_list va)
{
	char	*(*conv_pt[14])(va_list);
	char	*arg;

	conv_pt[0] = &(c_conv);
	conv_pt[1] = &(s_conv);
	conv_pt[2] = &(p_conv);
//	conv_pt[3] = &(f_conv);
	conv_pt[4] = &(d_conv);
	conv_pt[5] = &(d_conv);
//	conv_pt[6] = &(o_conv);
	conv_pt[7] = &(u_conv);
//	conv_pt[8] = &(x_conv);
//	conv_pt[9] = &(X_conv);
	arg = (*conv_pt[conv_type])(va);
	return (arg);
}

char		*add_conversion_output(t_data data, char *output, va_list va)
{
	char	*arg;

	arg = conversion_type(data.conv_type, va);
	arg = add_flag_to_conv(data, arg);
	output = ft_strjoin(output, arg);
	return (output);
}
