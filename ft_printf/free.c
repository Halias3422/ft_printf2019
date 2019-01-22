/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 14:56:11 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:38:16 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** FREE DATA ELEMS MALLOCED IN DETERM DATA
*/

void	free_data(t_data data)
{
	free(data.flag);
	free(data.tmp_width);
	free(data.tmp_prec);
	free(data.length);
}
