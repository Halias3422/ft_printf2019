/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   determ_data.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 09:46:18 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 12:45:31 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*init_data(t_data *data)
{
	data->conv = 0;
	data->conv_type = 0;
	data->flag = ft_strnew(0);
	data->tmp_width = ft_strnew(0);
	data->width = 0;
	data->prec_dot = 0;
	data->flag_minus = 0;
	data->minus = 0;
	data->tmp_prec = ft_strnew(0);
	data->length = ft_strnew(0);
	data->f_inf = 0;
	data->f_nan = 0;
	data->diez_length = 0;
	return (data);
}

char		*add_char_begin_string(char *dest, char *lett)
{
	char	*str;

	str = ft_strjoin(lett, dest);
	free(dest);
	return (str);
}

/*
**	FT ALLOWS TO ADD CHAR AT THE END OF STRING
*/

char		*add_char_end_string(char *dest, char *lett, int i)
{
	char	*tmp;
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
	conv_types = "cspfdiouxX%";
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

char		*determ_data(char *format, t_data *data, va_list va, int i)
{
	init_data(data);
	while (format[i] && (format[i] == '0' || format[i] == '+' || format[i] == '-' || format[i] == ' ' || format[i] == '#'))
	{
		if(format[i] == '-')
			data->flag_minus++;
	data->flag = add_char_end_string(data->flag, format, i++);
	}
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		data->tmp_width = add_char_end_string(data->tmp_width, format, i++);
	if (data->tmp_width[0] != '\0')
		data->width = ft_atoi(data->tmp_width);
	if (format[i] && format[i] == '.')
	{
		data->prec_dot = 1;
		while (format[++i] >= '0' && format[i] <= '9')
			data->tmp_prec = add_char_end_string(data->tmp_prec, format, i);
		data->prec = ft_atoi(data->tmp_prec);
	}
	while (format[i] && (format[i] == 'h' || format[i] == 'l' || format[i] == 'L'))
	{
		data->length = add_char_end_string(data->length, format, i++);
	}
	data->conv = determ_conv(data, data->conv, format, i);
	if (check_non_valid_conv(data) == 1)
	{
		free_data(data, 0);
		return (data->output);
	}
	data->output = add_conversion_output(data, data->output, va);
	free_data(data, 0);
	return (data->output);
}
