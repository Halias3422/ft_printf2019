/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 14:29:22 by vde-sain    ###    #+. /#+    ###.fr     */
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

	// D TESTS

	printf("		TEST OF d\n\n"), F;
	printf("expected =  Testd /%d/ /%d/ /%d/\n", 15, -50, 123456), F;
	ft_printf("ft_printf = Testd /%d/ /%d/ /%d/\n\n\n", 15, -50, 123456);

	//	C TESTS
	printf("		TEST OF c\n\n"), F;
	printf("expected =  Testc /%c/ /%c/ /%c/\n", 'j', 'Z', '0');
	ft_printf("ft_printf = Testc /%c/ /%c/ /%c/\n\n\n", 'j', 'Z', '0');

	//	S TESTS

	printf("		TEST OF s\n\n"), F;
	printf("expected =  Tests /%s/ /%s/ /%s/\n", "Hello", "Ca marche", "01254-()"), F;
	ft_printf("ft_printf = Tests /%s/ /%s/ /%s/\n\n\n", "Hello", "Ca marche", "01254-()");

	//	P TESTS

	printf("		TEST OF p\n\n"), F;
	printf("expected =  Testp /%p/ /%p/ /%p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Testp /%p/ /%p/ /%p/\n\n\n", p1, p2, p3);

	//	I TESTS

	printf("		TEST OF i\n\n"), F;
	printf("expected =  Testi /%i/ /%i/ /%i/\n", 54, -6875, 789521), F;
	ft_printf("ft_printf = Testi /%i/ /%i/ /%i/\n\n\n", 54, -6875, 789521);

	//	O TESTS

	printf("		TEST OF o\n\n"), F;
	printf("expected =  Testo /%o/ /%o/ /%o/\n", 53, 765421, 42), F;
	ft_printf("ft_printf = Testo /%o/ /%o/ /%o/\n\n\n", 53, 765421, 42);

	//	U TESTS

	printf("		TEST OF u\n\n"), F;
	printf("expected =  Testu /%u/ /%u/ /%u/\n", 1542, -4752, 4), F;
	ft_printf("expected =  Testu /%u/ /%u/ /%u/\n\n\n", 1542, -4752, 4);

	//	X TESTS

	printf("		TEST OF x\n\n"), F;
	printf("expected =  Testx /%x/ /%x/ /%x/\n", 45789, 3, -7865), F;
	ft_printf("ft_printf = Testx /%x/ /%x/ /%x/\n\n\n", 45789, 3, -7865);

	//	BIG X TESTS

	printf("		TEST OF X\n\n"), F;
	printf("expected =  TestX /%X/ /%X/ /%X/\n", 45789, 3, -7865), F;
	ft_printf("ft_printf = TestX /%X/ /%X/ /%X/\n\n\n", 45789, 3, -7865);

	//	F TESTS

	printf("		TEST OF f\n\n"), F;
	printf("expected =  Testf /%f/ /%f/ /%f/\n", 128.000001, 53.8975, -7.95), F;
	ft_printf("ft_printf = Testf /%f/ /%f/ /%f/\n\n\n", 128.000001, 53.8975, -7.95);

	return (0);
}
