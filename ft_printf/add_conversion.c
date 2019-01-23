/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_conversion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:14:09 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 17:15:43 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	INIT OF ARRAY OF POINTER ON FT AND SELECTING ACCORDING FT
*/

char		*conversion_type(t_data *data, va_list va)
{
	char	*(*conv_pt[14])(va_list, t_data *);
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
	arg = (*conv_pt[data->conv_type])(va, data);
	return (arg);
}

char		*backslash_strjoin(char *s1, char *s2, t_data data)
{
	char	*dest;
	size_t	i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2) + data.backslash;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (data.backslash > 0)
	{
		dest[i] = s1[i];
		i++;
		if (s1[i] == '\0')
			data.backslash--;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i++] = '\0';
	dest[i] = '\0';
	printf("dest = /%s/\n", dest);
	return (dest);
}

char		*add_conversion_output(t_data *data, char *output, va_list va)
{
	char	*arg;
	char	*tmp;

	if (data->conv_type == 3)
		arg = f_conv(va, *data);
	else
		arg = conversion_type(data, va);
	if (arg[0] == '-')
		data->minus++;
	arg = add_flag_to_conv(*data, arg);
	tmp = output;
	if (data->backslash > 0)
//		output = backslash_strjoin(output, arg, *data);
//	else
		output = ft_strjoin(output, arg);
	free(tmp);
	free(arg);
	return (output);
}
