/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 16:54:15 by vde-sain    ###    #+. /#+    ###.fr     */
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

	//	MINUS TESTS

/*	printf("		TEST OF -\n\n"), F;
	printf("expected =  Test-c /%-10c/ /%-3c/ /%--5c/\n", 'a', 'B', 'c'), F;
	ft_printf("ft_printf = Test-c /%-10c/ /%-3c/ /%--5c/\n\n\n", 'a', 'B', 'c'), F;
	
	printf("expected =  Test-s /%-12s/ /%-s/ /%--5s/\n", "hello", "bouuuh", ""), F;
	ft_printf("ft_printf = Test-s /%-12s/ /%-s/ /%--5s/\n\n\n", "hello", "bouuuh", "");
	
	printf("expected =  Test-p /%-15p/ /%-12p/ /%-p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Test-p /%-15p/ /%-12p/ /%-p/\n\n\n", p1, p2, p3);
	
	printf("expected =  Test-f /%-12f/ /%-0f/ /%-7f/\n", 78.50140, 0.1240002, 41782.1), F;
	ft_printf("ft_printf = Test-f /%-12f/ /%-0f/ /%-7f/\n\n\n", 78.50140, 0.1240002, 41782.1);
	
	printf("expected =  Test-d /%-d/ /%-15d/ /%-0d/\n", 3, 50412, -2145), F;
	ft_printf("ft_printf = Test-d /%-d/ /%-15d/ /%-0d/\n\n\n", 3, 50412, -2145);

	printf("expected =  Test-i /%-i/ /%-18i/ /%--8i/\n", 78, 364578, 0), F;
	ft_printf("ft_printf = Test-i /%-i/ /%-18i/ /%--8i/\n\n\n", 78, 364578, 0);

	printf("expected =  Test-o /%-o/ /%-0o/ /%-18o/\n", 0, 48, -78954), F;
	ft_printf("ft_printf = Test-o /%-o/ /%-0o/ /%-18o/\n\n\n", 0, 48, -78954);

	printf("expected =  Test-u /%-u/ /%-0u/ /%-19u/\n", 4215, -7584, 0), F;
	ft_printf("ft_printf = Test-u /%-u/ /%-0u/ /%-19u/\n\n\n", 4215, -7584, 0);

	printf("expected =  Test-x /%-x/ /%-0x/ /%-25x/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test-x /%-x/ /%-0x/ /%-25x/\n\n\n", 789456, -45721, 0);

	printf("expected =  Test-X /%-X/ /%-0X/ /%-25X/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test-X /%-X/ /%-0X/ /%-25X/\n\n\n", 789456, -45721, 0);*/

	//	PLUS TESTS
/*
	printf("		TEST OF +\n\n"), F;
	printf("expected =  Test+c /%+c/ /%+c/ /%++c/\n", 'a', 'B', 'c'), F;
	ft_printf("ft_printf = Test+c /%+c/ /%+c/ /%++c/\n\n\n", 'a', 'B', 'c'), F;
	
	printf("expected =  Test+s /%+s/ /%+s/ /%++s/\n", "hello", "bouuuh", ""), F;
	ft_printf("ft_printf = Test+s /%+s/ /%+s/ /%++5s/\n\n\n", "hello", "bouuuh", "");
	
	printf("expected =  Test+p /%+p/ /%+p/ /%++p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Test+p /%+p/ /%+p/ /%++p/\n\n\n", p1, p2, p3);
	
	printf("expected =  Test+f /%+f/ /%+f/ /%++f/\n", 78.50140, 0.1240002, 41782.1), F;
	ft_printf("ft_printf = Test+f /%+f/ /%+f/ /%++f/\n\n\n", 78.50140, 0.1240002, 41782.1);
	
	printf("expected =  Test+d /%+d/ /%+d/ /%++d/\n", 3, 50412, -2145), F;
	ft_printf("ft_printf = Test+d /%+d/ /%+d/ /%++d/\n\n\n", 3, 50412, -2145);

	printf("expected =  Test+i /%+i/ /%+i/ /%++i/\n", 78, 364578, 0), F;
	ft_printf("ft_printf = Test+i /%+i/ /%+i/ /%++i/\n\n\n", 78, 364578, 0);

	printf("expected =  Test+o /%+o/ /%+o/ /%++o/\n", 0, 48, -78954), F;
	ft_printf("ft_printf = Test+o /%+o/ /%+o/ /%++o/\n\n\n", 0, 48, -78954);

	printf("expected =  Test+u /%+u/ /%+u/ /%++u/\n", 4215, -7584, 0), F;
	ft_printf("ft_printf = Test+u /%+u/ /%+u/ /%++u/\n\n\n", 4215, -7584, 0);

	printf("expected =  Test+x /%+x/ /%+x/ /%++x/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test+x /%+x/ /%+x/ /%++x/\n\n\n", 789456, -45721, 0);

	printf("expected =  Test+X /%+X/ /%+X/ /%++X/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test+X /%+X/ /%+X/ /%++X/\n\n\n", 789456, -45721, 0);*/

	//	# TESTS

	printf("expected =  Test#o avec # /%#o/ sans # /%o/\n", 78945, 78945), F;
	printf("expected =  Test#x avec # /%#x/ sans # /%x/\n", -7854, -7854), F;
	printf("expected =  Test#X avec # /%#X/ sans # /%X/\n", 64215, 64215), F;
	printf("expected =  Test#f avec # /%#.0f/ sans # /%.0f/\n", 78.056, 78.056), F;
	return (0);
}
