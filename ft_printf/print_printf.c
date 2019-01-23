/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_printf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 14:54:19 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 17:11:39 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_printf(t_data *data)
{
	int		i;
	int		len;
	
	i = 0;
	len = -1;
	while (data->output[i])
	{
		while (data->output[i])
		{
			ft_putchar(data->output[i]);
//			printf("data->output[%d] = %c\n", i, data->output[i]);
			i++;
			len++;
		}
//		printf("je sors de la boucle\n\n");
		if (data->backslash-- >= 0)
		{
			ft_putchar('\0');
			i++;
			len++;
		}
//		printf("output = //%s//\n", data->output);
	}
	return (len);
}
