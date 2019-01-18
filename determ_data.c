/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   determ_data.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 09:46:18 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 19:12:01 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_data(t_data *data)
{
	data->flag = ft_strnew(0);
	data->tmp_width = ft_strnew(0);
	data->width = 0;
	data->prec_dot = 0;
	data->tmp_prec = ft_strnew(0);
	data->length = ft_strnew(0);
}

char		*add_char_begin_string(char *dest, char *lett)
{
	char	*tmp;
	size_t	j;
	int		i;

	j = 0;
	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(dest) + 2)))
		exit (-1);
	tmp[j] = lett[0];
	while (j < ft_strlen(dest) + 1)
		tmp[++j] = dest[i++];
	tmp[j] = '\0';
	dest = ft_strcpy(dest, tmp);
	free (tmp);
	return (dest);
}

/*
**	FT ALLOWS TO ADD CHAR AT THE END OF STRING
*/

char		*add_char_end_string(char *dest, char *lett, int i)
{
	char	*tmp;
//	char	*tmp_dest;
	int		j;

	j = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(dest) + 2)))
		exit (-1);
	while (dest[++j])
		tmp[j] = dest[j];
	tmp[j] = lett[i];
	j++;
	tmp[j] = '\0';
	free(dest);
	dest = ft_strnew(ft_strlen(tmp));
//	tmp_dest = ft_strnew(ft_strlen(tmp));
//	tmp_dest = ft_strcpy(dest, tmp);
	dest = ft_strcpy(dest, tmp);
	free (tmp);
	return (dest);
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
		if (format[i] == conv_types[data->conv_type])
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

	init_data(&data);
	while (format[i] == '0' || format[i] == '+' || format[i] == '-' || format[i] == ' ' || format[i] == '#')
		data.flag = add_char_end_string(data.flag, format, i++);
	while (format[i] >= '0' && format[i] <= '9')
		data.tmp_width = add_char_end_string(data.tmp_width, format, i++);
	if (ft_strlen(data.tmp_width) >= 1)
		data.width = ft_atoi(data.tmp_width);
	if (format[i] == '.')
	{
		data.prec_dot = 1;
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
