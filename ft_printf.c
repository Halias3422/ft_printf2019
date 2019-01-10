/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 07:45:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 13:13:00 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	FILL FIRST STRING PART OF FT_PRINTF IN OUTPUT
*/

char			*init_output(char *format, char *output)
{
	int			i;
	int			j;

	i = 0;
	j = -1;
	while (format[i] != '%')
		i++;
	if (!(output = (char*)malloc(sizeof(char) * i + 1)))
		exit (-1);
	while (++j < i)
		output[j] = format[j];
	output[j] = '\0';
	return (output);
}

/*
**	 INIT VA_LIST & FILLING START OF OUTPUT
*/

int				ft_printf(const char * restrict format, ...)
{
	va_list		va;
	char		*output;
	int			i;

	i = 0;
	output = NULL;
	va_start(va, format);
	output = init_output((char*)format, output);
	while (format[i] && format[i] != '%')
		i++;
	if (format[i] != '\0')
		output = determ_data((char*)format, output, va, ++i);
		/*nb = va_arg(va, int);
		ft_putnbr(nb);
		i += 2;*/
	va_end(va);
	ft_putstr(output);
	free(output);
	return (0);
}
