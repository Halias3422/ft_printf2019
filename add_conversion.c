/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_conversion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:14:09 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 15:28:34 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	INIT OF ARRAY OF POINTER ON FT AND SELECTING ACCORDING FT
*/

char		*conversion_type(int conv_type, char *output, va_list va)
{
	char	*(*conv_pt[15])(char*, va_list);

	conv_pt[0] = &(c_conv);
/*	conv_pt[1] = s_conv;
	conv_pt[2] = p_conv;
	conv_pt[3] = f_conv;
	conv_pt[4] = d_conv;
	conv_pt[5] = i_conv;
	conv_pt[6] = o_conv;
	conv_pt[7] = u_conv;
	conv_pt[8] = x_conv;
	conv_pt[9] = X_conv;
	conv_pt[10] = C_conv;
	conv_pt[11] = S_conv;
	conv_pt[12] = D_conv;
	conv_pt[13] = U_conv;*/
	output = (*conv_pt[conv_type])(output, va);
	return (output);
}

char		*add_conversion_output(t_data data, char *output, va_list va)
{
	conversion_type(data.conv_type, output, va);
	return (output);
}
