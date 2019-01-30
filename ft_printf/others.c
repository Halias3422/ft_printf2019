/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 14:56:11 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 14:22:26 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** FREE DATA ELEMS MALLOCED IN DETERM DATA
*/

char		*free_strjoin(char *str1, char *str2)
{
	char	*tmp;

	tmp = str1;
	str1 = ft_strjoin(str1, str2);
	free(tmp);
	return (str1);
}

int			check_non_valid_conv(t_data *data)
{
	if (data->conv == 0 && data->conv_type == 12)
	{
		while (--data->width > 0)
			data->output = add_char_end_string(data->output, " ", 0);
		return (1);
	}
	else
		return (0);
}

void		free_data(t_data *data, int usage)
{
	if (usage == 0)
	{
		free(data->flag);
		free(data->tmp_width);
		free(data->tmp_prec);
		free(data->length);
	}
	else if (usage == 1)
	{
		free(data->tab_arg_nb);
		free(data->output);
	}
}
