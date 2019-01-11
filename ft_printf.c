/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 07:45:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 17:01:56 by vde-sain    ###    #+. /#+    ###.fr     */
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

	j = -1;
	initial_i = i;
	k = i;
	while (format[i] != '%')
		i++;
	tmp = ft_strnew(i - k);
	while (++j < i - initial_i)
		tmp[j] = format[k++];
	tmp[j] = '\0';
	output = ft_strjoin(output, tmp);
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
	length.length = "hlLjtz";
	length.conv = "cspfdiouxX";
	while (is_contained_in(format, length.flags, i) > 0)
		i++;
	while (is_contained_in(format, length.nb, i) > 0)
		i++;
	if (format[i] == '.')
		i++;
	while (is_contained_in(format, length.nb, i) > 0)
		i++;
	if (is_contained_in(format, length.conv, i) > 0)
		i++;
		return (i);
}

/*
**		FILL OUTPUT STRING BIT BY BIT AND DISPLAY IT
*/

int					ft_printf(const char * restrict format, ...)
{
	va_list			va;
	char			*output;
	int				i;

	i = 0;
	output = ft_strnew(0);
	va_start(va, format);
	while (format[i])
	{
		output = fill_string_output((char*)format, output, i);
		while (format [i] && format[i] != '%')
			i++;
		if (format[i] == '%')
		{
			output = determ_data((char*)format, output, va, ++i);
			i = count_all_datas((char*)format, i);
		}
	}
	va_end(va);
	ft_putstr(output);
	free(output);
	return (0);
}
