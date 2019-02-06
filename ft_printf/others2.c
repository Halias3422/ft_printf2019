/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   others2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 08:54:16 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 08:23:31 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_color(t_color *col)
{
	col->color = NULL;
	col->bold = 0;
	col->underlined = 0;
	col->italic = 0;
	col->text = 0;
	col->back = 0;
	col->blinking = 0;
	col->check = 0;
}
