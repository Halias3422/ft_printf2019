/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_printf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 14:54:19 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 12:39:41 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"


int			print_printf(t_data *data)
{
	int		i;
	int		printed_backslash;
	int		backslash_last_pos;

	printed_backslash = 0;
	i = 0;
	backslash_last_pos = 0;
	while (data->output[i])
	{
		if (data->backslash > 0 && printed_backslash <= data->backslash && printed_backslash < data->args_nb && i == data->tab_arg_nb[printed_backslash])
		{
			printed_backslash++;
			ft_putchar('\0');
		}
		ft_putchar(data->output[i++]);
	}
	if (printed_backslash < data->args_nb && data->tab_arg_nb[printed_backslash] == ft_strlen(data->output) && data->backslash > 0)
	{
		ft_putchar('\0');
		backslash_last_pos++;
	}
	return (i + printed_backslash + backslash_last_pos);
}
