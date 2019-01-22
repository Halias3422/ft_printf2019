/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_conversion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:14:09 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 12:59:34 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	INIT OF ARRAY OF POINTER ON FT AND SELECTING ACCORDING FT
*/

char		*conversion_type(t_data data, va_list va)
{
	char	*(*conv_pt[14])(va_list, t_data);
	char	*arg;

	conv_pt[0] = &(c_conv);
	conv_pt[1] = &(s_conv);
	conv_pt[2] = &(p_conv);
	conv_pt[4] = &(d_conv);
	conv_pt[5] = &(d_conv);
	conv_pt[6] = &(o_conv);
	conv_pt[7] = &(u_conv);
	conv_pt[8] = &(x_conv);
	conv_pt[9] = &(X_conv);
	arg = (*conv_pt[data.conv_type])(va, data);
	return (arg);
}

char		*add_conversion_output(t_data data, char *output, va_list va)
{
	char	*arg;
	char	*tmp;

	if (data.conv_type == 3)
		arg = f_conv(va, data);
	else
		arg = conversion_type(data, va);
	arg = add_flag_to_conv(data, arg);
	tmp = output;
	output = ft_strjoin(output, arg);
	free(tmp);
	free(arg);
	return (output);
}
