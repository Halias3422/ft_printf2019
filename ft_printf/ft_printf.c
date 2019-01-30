/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 07:45:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 14:50:10 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 **		FILL OUTPUT WITH STRING PART OF FT_PRINTF
 */

char				*fill_string_output(char *format, char *output, int i)
{
	int				j;
	int				k;
	int				initial_i;
	char			*tmp;
	char			*tmp2;

	j = -1;
	initial_i = i;
	k = i;
	while (format[i] && format[i] != '%')
		i++;
	tmp = ft_strnew(i - k);
	while (++j < i - initial_i)
		tmp[j] = format[k++];
	tmp[j] = '\0';
	output = free_strjoin(output, tmp);
	free (tmp);
	return (output);
}

/*
 **		COUNT LENGTH OF ONE SPECIFIC TYPE OF PARAM FOR EACH %
 */

int					is_contained_in(char *format, char *compare, int i)
{
	int				j;
	int				res;

	j = 0;
	res = 0;
	while (compare[j])
	{
		if (format[i] == compare[j])
			res++;
		j++;
	}
	return (res);
}

/*
 **		COUNT LENGTH OF ALL PARAMS OF EACH %
 */

int					count_all_datas(char *format, int i)
{
	t_length		length;

	length.flags = "0+- #";
	length.nb = "0123456789";
	length.length = "hlL";
	length.conv = "cspfdiouxXb%";
	while (is_contained_in(format, length.flags, i) > 0)
		i++;
	while (is_contained_in(format, length.nb, i) > 0)
		i++;
	if (format[i] == '.')
		i++;
	while (is_contained_in(format, length.nb, i) > 0)
		i++;
	while (is_contained_in(format, length.length, i) > 0)
		i++;
	if (is_contained_in(format, length.conv, i) > 0)
		i++;
	return (i);
}

/*
 **		ADD '%' IN OUTPUT IN CASE THERE IS %%
 */

int				crossing_pourcent(char *format, t_data *data, int i, va_list va)
{
	char			*tmp;

	if (format[i + 1] != '\0')
	{
		data->output = determ_data((char*)format, data, va, ++i);
		i = count_all_datas((char*)format, i);
	}
	else
		i++;
	return (i);
}

/*
 **		FILL OUTPUT STRING BIT BY BIT AND DISPLAY IT
 */

int					ft_printf(const char * restrict format, ...)
{
	va_list			va;
	int				i;
	int				output_len;
	t_data			data;
	int				final_len;

	data.backslash = 0;
	data.args_nb = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			data.args_nb++;
	}
	if (!(data.tab_arg_nb = (size_t*)malloc(sizeof(size_t) * data.args_nb)))
		return (-1);
	i = 0;
	data.output = ft_strnew(0);
	va_start(va, format);
	while (format[i])
	{
		data.output = fill_string_output((char*)format, data.output, i);
		while (format[i] && format[i] != '%')
			i++;
		if (format[i] == '%')
			i = crossing_pourcent((char*)format, &data, i, va);
	}
	va_end(va);
	final_len = print_printf(&data);
	free_data(&data, 1);
	return (final_len);
}
