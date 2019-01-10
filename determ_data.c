/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   determ_data.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 09:46:18 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 11:22:05 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	FT ALLOWS TO ADD CHAR AT THE END OF STRING
*/

char		*add_char_end_string(char *flag, char *format, int i)
{
	char	*tmp;
	int		j;

	j = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(flag) + 2)))
		exit (-1);
	while (flag[++j])
		tmp[j] = flag[j];
	tmp[j] = format[i];
	j++;
	tmp[j] = '\0';
	flag = ft_strcpy(flag, tmp);
	free (tmp);
	return (flag);
}

/*
**	FILLING CONV & CONV_TYPE ELEM OF DATA STRUCT
*/

char		determ_conv(t_data *data, char conv, char *format, int i)
{
	char	*conv_types;

	data->conv_type = -1;
	conv_types = "cspfdiouxXCSDU";
	while (conv_types[++data->conv_type] && conv_types[data->conv_type] != format[i])
	{
		if (format[i] == conv_types[++data->conv_type])
			conv = conv_types[data->conv_type];
	}
	return (conv);
}

/*
**	INIT DATA STRUCT ELEMENTS & FILLING THEM
*/

char		*determ_data(char *format, char *output, va_list va, int i)
{
	t_data	data;

	data.flag = ft_strnew(0);
	data.tmp_width = ft_strnew(0);
	data.tmp_prec = ft_strnew(0);
	data.length = ft_strnew(0);
	while (format[i] == '0' || format[i] == '+' || format[i] == '-' || format[i] == ' ' || format[i] == '#')
		data.flag = add_char_end_string(data.flag, format, i++);
	while (format[i] >= '0' && format[i] <= '9')
		data.tmp_width = add_char_end_string(data.tmp_width, format, i++);
	if (ft_strlen(data.tmp_width) >= 1)
		data.width = ft_atoi(data.tmp_width);
	if (format[i] == '.')
	{
		while (format[++i] >= '0' && format[i] <= '9')
			data.tmp_prec = add_char_end_string(data.tmp_prec, format, i);
		data.prec = ft_atoi(data.tmp_prec);
	}
	while (format[i] == 'h' || format[i] == 'l' || format[i] == 'L' || format[i] == 'j' || format[i] == 't' || format[i] == 'z')
		data.length = add_char_end_string(data.length, format, i++);
	data.conv = determ_conv(&data, data.conv, format, i);
	output = add_conversion_output(data, output, va);
	free_data(data);
	return (output);
}
