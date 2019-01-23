/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 07:45:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 17:09:34 by vde-sain    ###    #+. /#+    ###.fr     */
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
	tmp2 = output;
	output = ft_strjoin(output, tmp);
	free(tmp2);
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
	length.conv = "cspfdiouxX";
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

	if (format[i + 1] == '%')
	{
		i++;
		tmp = data->output;
		data->output = ft_strjoin(data->output, "%");
		free(tmp);
		i++;
	}
	else if (format[i + 1] != '\0')
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
	printf("backslash total = %d\n", data.backslash);
//	ft_putstr(data.output);
//	output_len = ft_strlen(data.output);
//	free(data.output);
//	printf("\n\n");
	return (print_printf(&data));
}
