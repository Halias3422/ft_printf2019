/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 12:51:10 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{

	printf("Coucou mon cochon /%#o/\n", 5);
	ft_printf("Coucou mon cochon /%#o/\n\n\n\n", 5);
	return (0);
}
