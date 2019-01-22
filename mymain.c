/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 18:48:47 by vde-sain    ###    #+. /#+    ###.fr     */
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
/*
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
	printf("test arrondi float /%.0f/ /%.f/ /%.2f/ /%.12f/\n", 55.5994578, 55.5994578, 55.5994578, 55.5994578), F;
	ft_printf("test arrondi float /%.0f/ /%.f/ /%.2f/ /%.12f/\n\n\n", 55.5994578, 55.5994578, 55.5994578, 55.5994578);

	//	MINUS TESTS

	printf("		TEST OF -\n\n"), F;
	printf("expected =  Test-c /%-10c/ /%-3c/ /%--5c/\n", 'a', 'B', 'c'), F;
	ft_printf("ft_printf = Test-c /%-10c/ /%-3c/ /%--5c/\n\n\n", 'a', 'B', 'c'), F;
	
	printf("expected =  Test-s /%-12s/ /%-s/ /%--5s/\n", "hello", "bouuuh", ""), F;
	ft_printf("ft_printf = Test-s /%-12s/ /%-s/ /%--5s/\n\n\n", "hello", "bouuuh", "");
	
	printf("expected =  Test-p /%-15p/ /%-12p/ /%-p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Test-p /%-15p/ /%-12p/ /%-p/\n\n\n", p1, p2, p3);

//	printf("expected =  Test-f /%-12f/ /%-0f/ /%-7f/\n", 78.50140, 0.1240002, 41782.1), F;
	ft_printf("ft_printf = Test-f /%-12f/ /%-0f/ /%-7f/\n\n\n", 78.50140, 0.1240002, 41782.1);

//	printf("expected =  Test-d /%-d/ /%-15d/ /%-0d/\n", 3, 50412, -2145), F;
	ft_printf("ft_printf = Test-d /%-d/ /%-15d/ /%-0d/\n\n\n", 3, 50412, -2145);

	printf("expected =  Test-i /%-i/ /%-18i/ /%--8i/\n", 78, 364578, 0), F;
	ft_printf("ft_printf = Test-i /%-i/ /%-18i/ /%--8i/\n\n\n", 78, 364578, 0);

//	printf("expected =  Test-o /%-o/ /%-0o/ /%-18o/\n", 0, 48, -78954), F;
	ft_printf("ft_printf = Test-o /%-o/ /%-0o/ /%-18o/\n\n\n", 0, 48, -78954);

//	printf("expected =  Test-u /%-u/ /%-0u/ /%-19u/\n", 4215, -7584, 0), F;
	ft_printf("ft_printf = Test-u /%-u/ /%-0u/ /%-19u/\n\n\n", 4215, -7584, 0);

//	printf("expected =  Test-x /%-x/ /%-0x/ /%-25x/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test-x /%-x/ /%-0x/ /%-25x/\n\n\n", 789456, -45721, 0);

//	printf("expected =  Test-X /%-X/ /%-0X/ /%-25X/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test-X /%-X/ /%-0X/ /%-25X/\n\n\n", 789456, -45721, 0);

	//	PLUS TESTS

	printf("		TEST OF +\n\n"), F;
//	printf("expected =  Test+c /%+c/ /%+c/ /%++c/\n", 'a', 'B', 'c'), F;
	ft_printf("ft_printf = Test+c /%+c/ /%+c/ /%++c/\n\n\n", 'a', 'B', 'c'), F;
	
//	printf("expected =  Test+s /%+s/ /%+s/ /%++s/\n", "hello", "bouuuh", ""), F;
	ft_printf("ft_printf = Test+s /%+s/ /%+s/ /%++5s/\n\n\n", "hello", "bouuuh", "");
	
//	printf("expected =  Test+p /%+p/ /%+p/ /%++p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Test+p /%+p/ /%+p/ /%++p/\n\n\n", p1, p2, p3);

	printf("expected =  Test+f /%+f/ /%+f/ /%++f/\n", 78.50140, 0.1240002, 41782.1), F;
	ft_printf("ft_printf = Test+f /%+f/ /%+f/ /%++f/\n\n\n", 78.50140, 0.1240002, 41782.1);

	printf("expected =  Test+d /%+d/ /%+d/ /%++d/\n", 3, 50412, -2145), F;
	ft_printf("ft_printf = Test+d /%+d/ /%+d/ /%++d/\n\n\n", 3, 50412, -2145);

	printf("expected =  Test+i /%+i/ /%+i/ /%++i/\n", 78, 364578, 0), F;
	ft_printf("ft_printf = Test+i /%+i/ /%+i/ /%++i/\n\n\n", 78, 364578, 0);

//	printf("expected =  Test+o /%+o/ /%+o/ /%++o/\n", 0, 48, -78954), F;
	ft_printf("ft_printf = Test+o /%+o/ /%+o/ /%++o/\n\n\n", 0, 48, -78954);

//	printf("expected =  Test+u /%+u/ /%+u/ /%++u/\n", 4215, -7584, 0), F;
	ft_printf("ft_printf = Test+u /%+u/ /%+u/ /%++u/\n\n\n", 4215, -7584, 0);

//	printf("expected =  Test+x /%+x/ /%+x/ /%++x/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test+x /%+x/ /%+x/ /%++x/\n\n\n", 789456, -45721, 0);

//	printf("expected =  Test+X /%+X/ /%+X/ /%++X/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Test+X /%+X/ /%+X/ /%++X/\n\n\n", 789456, -45721, 0);

	//	# TESTS

	printf("expected =  Test#o /%#o/\n", 78945), F;
	ft_printf("ft_printf = Test#o /%#o/\n\n\n", 78945);

	printf("expected =  Test#x /%#x/\n", -7854), F;
	ft_printf("ft_printf = Test#x /%#x/\n\n\n", -7854);

	printf("expected =  Test#X /%#X/\n", 64215), F;
	ft_printf("ft_printf = Test#X /%#X/\n\n\n", 64215);

	printf("expected =  Test#f /%#f/ /%#.f/ /%#.0f/ /%#.5f/\n", 78945.25, 78945.25, 78945.25, 78945.25), F;
	ft_printf("ft_printf = Test#f /%#f/ /%#.f/ /%#.0f/ /%#.5f/\n\n\n", 78945.25, 78945.25, 78945.25, 78945.25);

//	printf("expected = Test#c /%#c/\n", 'a'), F;
	ft_printf("ft_printf = Test#c /%#c/\n\n\n", 'a');


	//	ZERO TESTS

//	printf("expected =  Test0d /%0d/ /%010d/ /%-05d/ /%08.5d/\n", 487, 487, 487, 487), F;
	ft_printf("ft_printf = Test0d /%0d/ /%010d/ /%-05d/ /%08.5d/\n\n\n", 487, 487, 487, 487);

//	printf("expected =  Test0i /%0i/ /%010i/ /%-05i/ /%08.5i/\n", 487, 487, 487, 487), F;
	ft_printf("ft_printf = Test0i /%0i/ /%010i/ /%-05i/ /%08.5i/\n\n\n", 487, 487, 487, 487);

//	printf("expected =  Test0u /%0u/ /%010u/ /%-05u/ /%08.5u/\n", 487, 487, 487, 487), F;
	ft_printf("ft_printf = Test0u /%0u/ /%010u/ /%-05u/ /%08.5u/\n", 487, 487, 487, 487);

//	printf("expected =  Test0x /%0x/ /%010x/ /%-05x/ /%08.5x/\n", 487, 487, 487, 487), F;
	ft_printf("ft_printf = Test0x /%0x/ /%010x/ /%-05x/ /%08.5x/\n", 487, 487, 487, 487);

//	printf("expected =  Test0X /%0X/ /%010X/ /%-05X/ /%08.5X/\n", 487, 487, 487, 487), F;
	ft_printf("ft_printf = Test0X /%0X/ /%010X/ /%-05X/ /%08.5X/\n", 487, 487, 487, 487);

//	printf("expected =  Test0o /%0o/ /%010o/ /%-05o/ /%08.5o/\n", 487, 487, 487, 487), F;
	ft_printf("ft_printf = Test0o /%0o/ /%010o/ /%-05o/ /%08.5o/\n", 487, 487, 487, 487);
	
//	printf("expected =  Test0f /%0f/ /%010f/ /%-05f/\n", 458.36, 458.36, 458.36), F;
	ft_printf("ft_printf = Test0f /%0f/ /%010f/ /%-05f/\n", 458.36, 458.36, 458.36);

	//	PREC TESTS
*/
	printf("expected =  Test.c /%.c/ /%.10c/ /%.0c/ /%5.12c/\n", 'a', 'v', '7', '^'), F;
	ft_printf("ft_printf = Test.c /%.c/ /%.10c/ /%.0c/ /%5.12c/\n\n\n", 'a', 'v', '7', '^');

	printf("expected =  Test.s /%.s/ /%.10s/ /%.0s/ /%5.18s/\n", "hello", "hello", "hello", "hello"), F;
	ft_printf("ft_printf = Test.s /%.s/ /%.18s/ /%.0s/ /%5.18s/\n\n\n", "hello", "hello", "hello", "hello");

	printf("expected =  Test.p /%.p/ /%.3p/ /%.0p/ /%.18p/\n", p1, p2, p3, p1), F;
	ft_printf("ft_printf = Test.p /%.p/ /%.10p/ /%.0p/ /%.18p/\n\n\n", p1, p2, p3, p1);

	printf("expected =  Test.d /%.d/ /%.10d/ /%.0d/ /%5.18d/\n", 7895, 789, -785424, 15547856), F;
	ft_printf("ft_printf = Test.d /%.d/ /%.10d/ /%.0d/ /%5.18d/\n\n\n", 7895, 789, -785424, 15547856);

	printf("expected =  Test.i /%.i/ /%.10i/ /%.0i/ /%5.18i/\n", 7895, 789, -785424, 15547856), F;
	ft_printf("ft_printf = Test.i /%.i/ /%.10i/ /%.0i/ /%5.18i/\n\n\n", 7895, 789, -785424, 15547856);

	printf("expected =  Test.o /%.o/ /%.10o/ /%.0o/ /%5.18o/\n", 7895, 789, -789521, 15547856), F;
	ft_printf("ft_printf = Test.o /%.o/ /%.10o/ /%.0o/ /%5.18o/\n\n\n", 7895, 789, -789521, 15547856);

	printf("expected =  Test.u /%.u/ /%.10u/ /%.0u/ /%5.18u/\n", 7895, 789, -789521, 15547856), F;
	ft_printf("ft_printf = Test.u /%.u/ /%.10u/ /%.0u/ /%5.18u/\n\n\n", 7895, 789, -789521, 15547856);

	printf("expected =  Test.x /%.x/ /%.10x/ /%.0x/ /%5.18x/\n", 7895, 789, -789521, 15547856), F;
	ft_printf("ft_printf = Test.x /%.x/ /%.10x/ /%.0x/ /%5.18x/\n\n\n", 7895, 789, -789521, 15547856);

	printf("expected =  Test.X /%.X/ /%.10X/ /%.0X/ /%5.18X/\n", 7895, 789, -789521, 15547856), F;
	ft_printf("ft_printf = Test.X /%.X/ /%.10X/ /%.0X/ /%5.18X/\n\n\n", 7895, 789, -789521, 15547856);
	printf("FIN\n"), F;
/*
//		WIDTH TESTS

//	printf("		TEST OF WIDTH\n\n"), F;
	printf("expected =  Testc /%15c/ /%5c/ /%-5c/\n", 'a', 'B', 'c'), F;
	ft_printf("ft_printf = Testc /%15c/ /%5c/ /%-5c/\n\n\n", 'a', 'B', 'c');
	
	printf("expected =  Tests /%-12s/ /%12s/ /%-5s/\n", "hello", "bouuuh", ""), F;
	ft_printf("ft_printf = Tests /%-12s/ /%12s/ /%-5s/\n\n\n", "hello", "bouuuh", "");
	
	printf("expected =  Testp /%1p/ /%15p/ /%-15p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Testp /%1p/ /%15p/ /%-15p/\n\n\n", p1, p2, p3);

	printf("expected =  Testf /%0f/ /%+15f/ /%-15f/\n", 78.50140, 0.1240002, 41782.1), F;
	ft_printf("ft_printf = Testf /%0f/ /%+15f/ /%-15f/\n\n\n", 78.50140, 0.1240002, 41782.1);

	printf("expected =  Testd /%15d/ /%+15d/ /%-15d/\n", 3, 50412, -2145), F;
	ft_printf("ft_printf = Testd /%15d/ /%+15d/ /%-15d/\n\n\n", 3, 50412, -2145);

	printf("expected =  Testi /%15i/ /%+15i/ /%-15i/\n", 78, 364578, 0), F;
	ft_printf("ft_printf = Testi /%15i/ /%+15i/ /%-15i/\n\n\n", 78, 364578, 0);

	printf("expected =  Testo /%15o/ /%0o/ /%-15o/\n", 0, 48, -78954), F;
	ft_printf("ft_printf = Testo /%15o/ /%0o/ /%-15o/\n\n\n", 0, 48, -78954);

	printf("expected =  Testu /%15u/ /%0u/ /%-15u/\n", 4215, -7584, 0), F;
	ft_printf("ft_printf = Testu /%15u/ /%0u/ /%-15u/\n\n\n", 4215, -7584, 0);

	printf("expected =  Testx /%15x/ /%0x/ /%-15x/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Testx /%15x/ /%0x/ /%-15x/\n\n\n", 789456, -45721, 0);

	printf("expected =  TestX /%15X/ /%0X/ /%-15X/\n", 789456, -45721, 0);
	ft_printf("ft_printf = TestX /%15X/ /%0X/ /%-15X/\n\n\n", 789456, -45721, 0);


//		SPACE TESTS

	printf("		TEST OF SPACE\n\n"), F;
	printf("expected =  Testc /% c/ /% c/ /%c/\n", 'a', 'B', 'c'), F;
	ft_printf("ft_printf = Testc /% c/ /%  c/ /%c/\n\n\n", 'a', 'B', 'c');

	printf("expected =  Tests /% s/ /%   s/ /% +s/\n", "hello", "bouuuh", ""), F;
	ft_printf("ft_printf = Tests /% s/ /%   s/ /% +s/\n\n\n", "hello", "bouuuh", "");
	
	printf("expected =  Testp /% p/ /%   p/ /% +p/\n", p1, p2, p3), F;
	ft_printf("ft_printf = Testp /% p/ /%   p/ /% +p/\n\n\n", p1, p2, p3);

	printf("expected =  Testf /% f/ /%  f/ /%      +f/\n", 78.50140, 0.1240002, 41782.1), F;
	ft_printf("ft_printf = Testf /% f/ /%  f/ /%      +f/\n\n\n", 78.50140, 0.1240002, 41782.1);

	printf("expected =  Testd /% d/ /%   d/ /% +d/\n", 3, 50412, -2145), F;
	ft_printf("ft_printf = Testd /% d/ /%   d/ /% +d/\n\n\n", 3, 50412, -2145);

	printf("expected =  Testi /% i/ /%   i/ /% +i/\n", 78, 364578, 0), F;
	ft_printf("ft_printf = Testi /% i/ /%   i/ /% +i/\n\n\n", 78, 364578, 0);

	printf("expected =  Testo /% o/ /%   o/ /% +o/\n", 0, 48, -78954), F;
	ft_printf("ft_printf = Testo /% o/ /%   o/ /% +o/\n\n\n", 0, 48, -78954);

	printf("expected =  Testu /% u/ /%   u/ /% +u/\n", 4215, -7584, 0), F;
	ft_printf("ft_printf = Testu /% u/ /%   u/ /% +u/\n\n\n", 4215, -7584, 0);

	printf("expected =  Testx /% x/ /%   x/ /% +x/\n", 789456, -45721, 0);
	ft_printf("ft_printf = Testx /% x/ /%   x/ /% +x/\n\n\n", 789456, -45721, 0);

	printf("expected =  TestX /% X/ /%   X/ /% +X/\n", 789456, -45721, 0);
	ft_printf("ft_printf = TestX /% X/ /%   X/ /% +X/\n\n\n", 789456, -45721, 0);

//		TESTS %%
*/
	printf("printf =  Test du %%%d %d %s\n", 10, "hello"), F;
	ft_printf("ft_printf = Test du %%%+d %d %s\n\n\n", 10, "hello");
/**/

//		TESTS hh
/*
	printf("printf =    Test avec (hd) %hd test sans %d\n",457845, 457845);
	ft_printf("ft_printf = Test avec (hd) %hd test sans %d\n\n\n", 457845, 457845);

	printf("printf =    Test avec (hhd) %hhd test sans %d\n", 457845, 457845);
	ft_printf("ft_printf = Test avec (hhd) %hhd test sans %d\n\n\n", 457845, 457845);

	printf("printf =    Test avec (ld) %ld test sans %d\n",  4578453259999999999, 4578453259);
	ft_printf("ft_printf = Test avec (ld) %ld test sans %d\n\n\n",  4578453259999999999, 4578453259);

	printf("printf =    Test avec (lld) %lld test sans %d\n",  4578453259999999999, 4578453259);
	ft_printf("ft_printf = Test avec (lld) %lld test sans %d\n\n\n",  4578453259999999999, 4578453259);

	printf("printf =    Test avec (ho) %ho test sans %o\n",457845, 457845);
	ft_printf("ft_printf = Test avec (hd) %ho test sans %o\n\n\n", 457845, 457845);

	printf("printf =    Test avec (hhd) %hho test sans %o\n", 457845, 457845);
	ft_printf("ft_printf = Test avec (hhd) %hho test sans %o\n\n\n", 457845, 457845);

	printf("printf =    Test avec (ld) %lo test sans %o\n",  4578453259999999999, 4578453255);
	ft_printf("ft_printf = Test avec (ld) %lo test sans %o\n\n\n",  4578453259999999999, 4578453255);

	printf("printf =    Test avec (lld) %llo test sans %o\n",  4578453259999999999, 4578453259);
	ft_printf("ft_printf = Test avec (lld) %llo test sans %o\n\n\n",  4578453259999999999, 4578453259);

	printf("printf =    Test avec (hu) %hu test sans %u\n",457845, 457845);
	ft_printf("ft_printf = Test avec (hu) %hu test sans %u\n\n\n", 457845, 457845);

	printf("printf =    Test avec (hhu) %hhu test sans %u\n", 457845, 457845);
	ft_printf("ft_printf = Test avec (hhu) %hhu test sans %u\n\n\n", 457845, 457845);

	printf("printf =    Test avec (lu) %lu test sans %u\n",  4578453259999999999, 4578453255);
	ft_printf("ft_printf = Test avec (lu) %lu test sans %u\n\n\n",  4578453259999999999, 4578453255);

	printf("printf =    Test avec (llu) %llu test sans %u\n",  4578453259999999999, 4578453259);
	ft_printf("ft_printf = Test avec (llu) %llu test sans %u\n\n\n",  4578453259999999999, 4578453259);

	printf("printf =    Test avec (hx) %hx test sans %x\n",457845, 457845);
	ft_printf("ft_printf = Test avec (hx) %hx test sans %x\n\n\n", 457845, 457845);

	printf("printf =    Test avec (hhx) %hhx test sans %x\n", 457845, 457845);
	ft_printf("ft_printf = Test avec (hhx) %hhx test sans %x\n\n\n", 457845, 457845);

	printf("printf =    Test avec (lx) %lx test sans %x\n",  4578453259999999999, 4578453255);
	ft_printf("ft_printf = Test avec (lx) %lx test sans %x\n\n\n",  4578453259999999999, 4578453255);

	printf("printf =    Test avec (llx) %llx test sans %x\n",  4578453259999999999, 4578453259);
	ft_printf("ft_printf = Test avec (llx) %llx test sans %x\n\n\n",  4578453259999999999, 4578453259);

	printf("printf =    Test avec (hX) %hX test sans %X\n",457845, 457845);
	ft_printf("ft_printf = Test avec (hX) %hX test sans %X\n\n\n", 457845, 457845);

	printf("printf =    Test avec (hhX) %hhX test sans %X\n", 457845, 457845);
	ft_printf("ft_printf = Test avec (hhX) %hhX test sans %X\n\n\n", 457845, 457845);

	printf("printf =    Test avec (lX) %lX test sans %X\n",  4578453259999999999, 4578453255);
	ft_printf("ft_printf = Test avec (lX) %lX test sans %X\n\n\n",  4578453259999999999, 4578453255);

	printf("printf =    Test avec (llX) %llX test sans %X\n",  4578453259999999999, 4578453259);
	ft_printf("ft_printf = Test avec (llX) %llX test sans %X\n\n\n",  4578453259999999999, 4578453259);

	printf("printf =    Test avec (lf) %lf test sans %f\n",  4578453259999999999.45421, 4578453255.45421);
	ft_printf("ft_printf = Test avec (lf) %lf test sans %f\n\n\n",  4578453259999999999.45421, 4578453255.45421);

	printf("printf =    Test avec (llf) %Lf test sans %f\n",  4578453259999999999.45421, 4578453259.45421);
	ft_printf("ft_printf = Test avec (llf) %Lf test sans %f\n\n\n",  4578453259999999999.45421, 4578453259.45421);
*/
	return (0);
}
