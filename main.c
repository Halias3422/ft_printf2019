/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:13:07 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#define F fflush(stdout)

int			main(void)
{
	char	*p1;
	char	*p2;
	char	*p3;

	p1 = "Testitude1";
	p2 = "Testitude2";
	p3 = "Testitude3";

	// BASIC TESTS
	printf("		BASIC TESTS\n\n"), F;
	printf("expected =  Testd /%d/ /%d/ /%d/\n", 15, -50, 123456), F;
	ft_printf("ft_printf = Testd /%d/ /%d/ /%d/\n\n", 15, -50, 123456);
	printf("expected =  Testc /%c/ /%c/ /%c/\n", 'j', 'Z', '0');
	ft_printf("ft_printf = Testc /%c/ /%c/ /%c/\n\n", 'j', 'Z', '0');
	printf("expected =  Tests /%s/ /%s/ /%s/\n", "Hello", "Ca marche", "01254-()"), F;
	ft_printf("ft_printf = Tests /%s/ /%s/ /%s/\n\n", "Hello", "Ca marche", "01254-()");
	printf("expected =  Testp /%p/ /%p/ /%p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Testp /%p/ /%p/ /%p/\n\n", p1, p2, p3);
	return (0);
}
