/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 16:23:29 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{

	printf("expected =  Coucou mon cochon /%-10d/ test /%c/\n", 1, 'a'), fflush(stdout);
	ft_printf("ft_printf = Coucou mon cochon /%-10d/ test /%c/\n", 1, 'a');	
	return (0);
}
