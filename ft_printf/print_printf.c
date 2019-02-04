/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_printf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 14:54:19 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 07:53:14 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			add_color_to_output(t_data *data, t_color col, int i)
{
	char	*num;
	int		j;

	data->code = ft_strdup("\033[");
	if (col.bold == 1)
		data->code = free_strjoin(data->code, "1;");
	if (col.underlined == 1)
		data->code = free_strjoin(data->code, "4;");
	if (col.italic == 1)
		data->code = free_strjoin(data->code, "3;");
	if (col.blinking == 1)
		data->code = free_strjoin(data->code, "5;");
	if (col.text > 0)
	{
		num = ft_itoa(col.text);
		data->code = free_strjoin(data->code, num);
		data->code = free_strjoin(data->code, ";");
		free(num);
	}
	if (col.back > 0)
	{
		num = ft_itoa(col.back);
		data->code = free_strjoin(data->code, num);
		data->code = free_strjoin(data->code, ";");
		free(num);
	}
	j = ft_strlen(data->code);
	data->code[j - 1] = 'm';
	ft_putstr(data->code);
	if (data->last_color != NULL)
		free(data->last_color);
	data->last_color = ft_strnew(ft_strlen(data->code));
	data->last_color = ft_strcpy(data->last_color, data->code);
	free(data->code);
	return (i);
}

int			search_color(int i, char *output, int usage)
{
	int	tmp;

	tmp = -1;
	if (strncmp(output + i, "grey.", 5) == 0)
		tmp = usage == 0 ? 40 : 30;
	if (strncmp(output + i, "red.", 4) == 0)
		tmp = usage == 0 ? 41 : 31;
	if (strncmp(output + i, "green.", 6) == 0)
		tmp = usage == 0 ? 42 : 32;
	if (strncmp(output + i, "yellow.", 7) == 0)
		tmp = usage == 0 ? 43 : 33;
	if (strncmp(output + i, "blue.", 5) == 0)
		tmp = usage == 0 ? 44 : 34;
	if (strncmp(output + i, "purple.", 7) == 0)
		tmp = usage == 0 ? 45 : 35;
	if (strncmp(output + i, "cyan.", 5) == 0)
		tmp = usage == 0 ? 46 : 36;
	if (strncmp(output + i, "white.", 6) == 0)
		tmp = usage == 0 ? 47 : 37;
	return (tmp);
}

int			handle_colors(t_data *d, int i)
{
	int		tmp;
	t_color	col;
	int		check;

	check = 0;
	col.bold = 0;
	col.underlined = 0;
	col.italic = 0;
	col.text = 0;
	col.back = 0;
	col.blinking = 0;
	tmp = i;
	while (d->output[i] && d->output[i] != '}')
	{
		check = 0;
		if (d->output[i] == 'B' && d->output[i + 1] == '.' && check++ >= 0)
			col.bold = 1;
		else if (d->output[i] == 'U' && d->output[i + 1] == '.' && check++ >= 0)
			col.underlined = 1;
		else if (d->output[i] == 'I' && d->output[i + 1] == '.' && check++ >= 0)
			col.italic = 1;
		else if (d->output[i] == 'F' && d->output[i + 1] == '.' && check++ >= 0)
			col.blinking = 1;
		else if (d->output[i] == 'T' && d->output[i + 1] == '.' && check++ >= 0)
			col.text = search_color(i + 2, d->output, 1);
		else if (d->output[i] == 'S' && d->output[i + 1] == '.' && check++ >= 0)
			col.back = search_color(i + 2, d->output, 0);
		else if (ft_strncmp(d->output + i, "eoc}", 4) == 0)
		{
			ft_putstr("\033[0m");
			d->code = NULL;
			return (i + 4);
		}
		else
			return (tmp - 1);
		if (check > 0)
			i += 2;
		if (col.back != -1 || col.text != -1)
		{
			while ((d->output[i] < 'A' || d->output[i] > 'Z') && d->output[i] != '}')
				i++;
		}
	}
	if (!d->output[i] || check == 0)
		return (tmp -1);
	i = add_color_to_output(d, col, i + 1);
	return (i);
}

int			print_printf(t_data *data, int i)
{
	int		printed_backslash;
	int		backslash_last_pos;

	printed_backslash = 0;
	backslash_last_pos = 0;
	data->code = NULL;
	data->last_color = NULL;
	while (data->output[i])
	{
		if (data->output[i] && data->output[i] == '{')
			i = handle_colors(data, i + 1);
		if (data->backslash > 0 && printed_backslash <= data->backslash &&
				printed_backslash < data->args_nb &&
				i == data->tab_arg_nb[printed_backslash])
		{
			printed_backslash++;
			ft_putchar('\0');
		}
		if (data->output[i] && data->output[i] == '\n' && data->last_color != NULL)
		{
			ft_putstr("\033[0m\n");
			ft_putstr(data->last_color);
			i++;
		}
		else
			ft_putchar(data->output[i++]);
	}
	if (printed_backslash < data->args_nb &&
			data->tab_arg_nb[printed_backslash] == ft_strlen(data->output) &&
			data->backslash > 0)
	{
		ft_putchar('\0');
		backslash_last_pos++;
	}
	if (data->last_color != NULL)
	{
		ft_putstr("\033[0m");
		free(data->last_color);
	}
	return (i + printed_backslash + backslash_last_pos);
}
