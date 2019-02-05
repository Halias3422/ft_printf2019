/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 13:40:58 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <limits.h>

#define F fflush(stdout)

int			main(void)
{	
	char	*p1;
	char	*p2;
	char	*p3;
	char **tab;
	int i = -1;
	int j;
	char c = 33;
	char *string = NULL;
	short	zeroshort = 0;
	short	short1 = 15;
	short	short2 = -15;
	short	short_max = 32767;
	short	short_min = -32767;
	int		zeroint = 0;
	int		int1 = 25;
	int		int2 = -25;
	int		int_max = 2147483647;
	int		int_min = -2147483648;
	long	zerolong = 0;
	long	long1 = 35;
	long	long2 = -35;
	long	long_max = 9223372036854775807;
	long	long_min = -9223372036854775807;
	long long	zerolonglong = 0;
	long long	longlong1 = 45;
	long long	longlong2 =		-45;
	long long	longlong_max = 9223372036854775807;
	long long	longlong_min = -9223372036854775807;
	double crash_float = 0.0 / 0.0;
	double crash_float2 = pow(1024, 1024);
	double t_f1 = 0.0;
	float  t_f2 = 1.6;
	double t_f3 = -1.6;
	double t_f4 = 50.4;
	double t_f5 = -50.4;
	double t_f6 = 2147483647.0;
	double t_f7 = -2147483648.0;
	long double t_f = 1234567890.1234567890;
	long t_bit = 2147483647;
	long double t_f8  = 0.000001;
	char	hh_test = 'E';
	int t_o = 102;
	int t_x = 15;
	int t_X		= 15;
	int t_d = 42;
	unsigned int t_u = 52;
	char t_c = '*';
	char*pointer_test;
	char *t_s = "    123456789     ";
	float t_fl = 123.12345;

	p1 = "Testitude1";
	p2 = "Testitude2";
	p3 = "Testitude3";


	char **tab2;
	int i2 = -1;
	int j2;
	char c2 = 33;

	int		test_part1 = 1;
	int		test_part2 = 1;
	int		test_part3 = 1;
	int		test_part4 = 1;
	int		test_bonus = 1;


	int		**int_tab;
	int		fill_tab;
	int		fill_case;
	int		put_int = 1;


	char	***example_triple;
	int		m = -1;
	int		n;
	int		o;

	

	if (test_part1 == 1)
	{
		// D TESTS

		ft_printf("         TEST OF d\n\n");
		ft_printf("ft_printf = Test du %%%d, %s%%\n\n\n", 10, "hello");


		ft_printf("ft_printf = Testd /%d/ /%d/ /%d/\n\n\n", 15, -50, 123456);

		//	C TESTS

		ft_printf("         TEST OF c\n\n");
		ft_printf("ft_printf = Testc /%c/ /%c/ /%c/\n\n\n", 'j', 'Z', '0');

		//	S TESTS

		ft_printf("         TEST OF s\n\n");
		ft_printf("ft_printf = Tests /%s/ /%s/ /%s/\n\n\n", "Hello", "Ca marche", "01254-()");

		//	P TESTS

		ft_printf("         TEST OF p\n\n");
		ft_printf("ft_printf = Testp /%p/ /%p/ /%p/\n\n\n", p1, p2, p3);

		//	I TESTS

		ft_printf("         TEST OF i\n\n");
		ft_printf("ft_printf = Testi /%i/ /%i/ /%i/\n\n\n", 54, -6875, 789521);

		//	O TESTS

		ft_printf("ft_printf = Testo /%o/ /%o/ /%o/\n\n\n", 53, 765421, 42);

		//	U TESTS

		ft_printf("expected =  Testu /%u/ /%u/ /%u/\n\n\n", 1542, -4752, 4);

		//	X TESTS

		ft_printf("ft_printf = Testx /%x/ /%x/ /%x/\n\n\n", 45789, 3, -7865);

		//	BIG X TESTS

		ft_printf("ft_printf = TestX /%X/ /%X/ /%X/\n\n\n", 45789, 3, -7865);

		//	F TESTS

		ft_printf("ft_printf = Testf /%f/ /%f/ /%f/\n\n\n", 128.000001, 53.8975, -7.95);
		ft_printf("test arrondi float /%.0f/ /%.f/ /%.2f/ /%.12f/\n\n\n", 55.5994578, 55.5994578, 55.5994578, 55.5994578);

		//	MINUS TESTS

		ft_printf("ft_printf = Test-c /%-10c/ /%-3c/ /%--5c/\n\n\n", 'a', 'B', 'c');

		ft_printf("ft_printf = Test-s /%-12s/ /%-s/ /%-5s/\n\n\n", "hello", "bouuuh", "");

		ft_printf("ft_printf = Test-p /%-15p/ /%-12p/ /%-p/\n\n\n", p1, p2, p3);

		ft_printf("ft_printf = Test-f /%-12f/ /%-0f/ /%-7f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		ft_printf("ft_printf = Test-d /%-d/ /%-15d/ /%-0d/\n\n\n", 3, 50412, -2145);

		ft_printf("ft_printf = Test-i /%-i/ /%-18i/ /%--8i/\n\n\n", 78, 364578, 0);

		ft_printf("ft_printf = Test-o /%-o/ /%-0o/ /%-18o/\n\n\n", 0, 48, -78954);

		ft_printf("ft_printf = Test-u /%-u/ /%-0u/ /%-19u/\n\n\n", 4215, -7584, 0);

		ft_printf("ft_printf = Test-x /%-x/ /%-0x/ /%-25x/\n\n\n", 789456, -45721, 0);

		ft_printf("ft_printf = Test-X /%-X/ /%-0X/ /%-25X/\n\n\n", 789456, -45721, 0);

		//	PLUS TESTS

		ft_printf("ft_printf = Test+c /%+c/ /%+c/ /%++c/\n\n\n", 'a', 'B', 'c');

		ft_printf("ft_printf = Test+s /%+s/ /%+s/ /%++s/\n\n\n", "hello", "bouuuh", "");

		ft_printf("ft_printf = Test+p /%+p/ /%+p/ /%++p/\n\n\n", p1, p2, p3);

		ft_printf("ft_printf = Test+f /%+f/ /%+f/ /%++f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		ft_printf("ft_printf = Test+d /%+d/ /%+d/ /%++d/\n\n\n", 3, 50412, -2145);

		ft_printf("ft_printf = Test+i /%+i/ /%+i/ /%++i/\n\n\n", 78, 364578, 0);

		ft_printf("ft_printf = Test+o /%+o/ /%+o/ /%++o/\n\n\n", 0, 48, -78954);

		ft_printf("ft_printf = Test+u /%+u/ /%+u/ /%++u/\n\n\n", 4215, -7584, 0);

		ft_printf("ft_printf = Test+x /%+x/ /%+x/ /%++x/\n\n\n", 789456, -45721, 0);

		ft_printf("ft_printf = Test+X /%+X/ /%+X/ /%++X/\n\n\n", 789456, -45721, 0);

		//	# TESTS

		ft_printf("ft_printf = Test#o /%#o/\n\n\n", 78945);

		ft_printf("ft_printf = Test#x /%#x/\n\n\n", -7854);

		ft_printf("ft_printf = Test#X /%#X/\n\n\n", 64215);

		ft_printf("ft_printf = Test#f /%#f/ /%#.f/ /%#.0f/ /%#.5f/\n\n\n", 78945.25, 78945.25, 78945.25, 78945.25);

		ft_printf("ft_printf = Test#c /%#c/\n\n\n", 'a');


		//	ZERO TESTS

		ft_printf("ft_printf = Test0d /%0d/ /%010d/ /%-05d/ /%08.5d/\n\n\n", 487, 487, 487, 487);

		ft_printf("ft_printf = Test0i /%0i/ /%010i/ /%-05i/ /%08.5i/\n\n\n", 487, 487, 487, 487);

		ft_printf("ft_printf = Test0u /%0u/ /%010u/ /%-05u/ /%08.5u/\n", 487, 487, 487, 487);

		ft_printf("ft_printf = Test0x /%0x/ /%010x/ /%-05x/ /%08.5x/\n", 487, 487, 487, 487);

		ft_printf("ft_printf = Test0X /%0X/ /%010X/ /%-05X/ /%08.5X/\n", 487, 487, 487, 487);

		ft_printf("ft_printf = Test0o /%0o/ /%010o/ /%-05o/ /%08.5o/\n", 487, 487, 487, 487);

		ft_printf("ft_printf = Test0f /%0f/ /%010f/ /%-05f/\n", 458.36, 458.36, 458.36);

		//	PREC TESTS

		ft_printf("ft_printf = Test.c /%.c/ /%.10c/ /%.0c/ /%5.12c/\n\n\n", 'a', 'v', '7', '^');

		ft_printf("ft_printf = Test.s /%.s/ /%.18s/ /%.0s/ /%5.18s/\n\n\n", "hello", "hello", "hello", "hello");

		ft_printf("ft_printf = Test.p /%.p/ /%.10p/ /%.0p/ /%.18p/\n\n\n", p1, p2, p3, p1);

		ft_printf("ft_printf = Test.d /%.d/ /%.10d/ /%.0d/ /%5.18d/\n\n\n", 7895, 789, -785424, 15547856);

		ft_printf("ft_printf = Test.i /%.i/ /%.10i/ /%.0i/ /%5.18i/\n\n\n", 7895, 789, -785424, 15547856);

		ft_printf("ft_printf = Test.o /%.o/ /%.10o/ /%.0o/ /%5.18o/\n\n\n", 7895, 789, -789521, 15547856);

		ft_printf("ft_printf = Test.u /%.u/ /%.10u/ /%.0u/ /%5.18u/\n\n\n", 7895, 789, -789521, 15547856);

		ft_printf("ft_printf = Test.x /%.x/ /%.10x/ /%.0x/ /%5.18x/\n\n\n", 7895, 789, -789521, 15547856);

		ft_printf("ft_printf = Test.X /%.X/ /%.10X/ /%.0X/ /%5.18X/\n\n\n", 7895, 789, -789521, 15547856);


		//		WIDTH TESTS

		ft_printf("ft_printf = Testc /%15c/ /%5c/ /%-5c/\n\n\n", 'a', 'B', 'c');

		ft_printf("ft_printf = Tests /%-12s/ /%12s/ /%-5s/\n\n\n", "hello", "bouuuh", "");

		ft_printf("ft_printf = Testp /%1p/ /%15p/ /%-15p/\n\n\n", p1, p2, p3);

		ft_printf("ft_printf = Testf /%0f/ /%+15f/ /%-15f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		ft_printf("ft_printf = Testd /%15d/ /%+15d/ /%-15d/\n\n\n", 3, 50412, -2145);

		ft_printf("ft_printf = Testi /%15i/ /%+15i/ /%-15i/\n\n\n", 78, 364578, 0);

		ft_printf("ft_printf = Testo /%15o/ /%0o/ /%-15o/\n\n\n", 0, 48, -78954);

		ft_printf("ft_printf = Testu /%15u/ /%0u/ /%-15u/\n\n\n", 4215, -7584, 0);

		ft_printf("ft_printf = Testx /%15x/ /%0x/ /%-15x/\n\n\n", 789456, -45721, 0);

		ft_printf("ft_printf = TestX /%15X/ /%0X/ /%-15X/\n\n\n", 789456, -45721, 0);


		//		SPACE TESTS

		ft_printf("ft_printf = Testc /% c/ /%  c/ /%c/\n\n\n", 'a', 'B', 'c');

		ft_printf("ft_printf = Tests /% s/ /%   s/ /% +s/\n\n\n", "hello", "bouuuh", "");

		ft_printf("ft_printf = Testp /% p/ /%   p/ /% +p/\n\n\n", p1, p2, p3);

		ft_printf("ft_printf = Testf /% f/ /%  f/ /%      +f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		ft_printf("ft_printf = Testd /% d/ /%   d/ /% +d/\n\n\n", 3, 50412, -2145);

		ft_printf("ft_printf = Testi /% i/ /%   i/ /% +i/\n\n\n", 78, 364578, 0);

		ft_printf("ft_printf = Testo /% o/ /%   o/ /% +o/\n\n\n", 0, 48, -78954);

		ft_printf("ft_printf = Testu /% u/ /%   u/ /% +u/\n\n\n", 4215, -7584, 0);

		ft_printf("ft_printf = Testx /% x/ /%   x/ /% +x/\n\n\n", 789456, -45721, 0);

		ft_printf("ft_printf = TestX /% X/ /%   X/ /% +X/\n\n\n", 789456, -45721, 0);

		//		TESTS %%


		//		TESTS hh

		ft_printf("ft_printf = Test avec (hd) %hd test sans %d\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (hhd) %hhd test sans %d\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (ld) %ld test sans %d\n\n\n",  4578453259999999999, 4578453259);

		ft_printf("ft_printf = Test avec (lld) %lld test sans %d\n\n\n",  4578453259999999999, 4578453259);

		ft_printf("ft_printf = Test avec (hd) %ho test sans %o\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (hhd) %hho test sans %o\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (ld) %lo test sans %o\n\n\n",  4578453259999999999, 4578453255);

		ft_printf("ft_printf = Test avec (lld) %llo test sans %o\n\n\n",  4578453259999999999, 4578453259);

		ft_printf("ft_printf = Test avec (hu) %hu test sans %u\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (hhu) %hhu test sans %u\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (lu) %lu test sans %u\n\n\n",  4578453259999999999, 4578453255);

		ft_printf("ft_printf = Test avec (llu) %llu test sans %u\n\n\n",  4578453259999999999, 4578453259);

		ft_printf("ft_printf = Test avec (hx) %hx test sans %x\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (hhx) %hhx test sans %x\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (lx) %lx test sans %x\n\n\n",  4578453259999999999, 4578453255);

		ft_printf("ft_printf = Test avec (llx) %llx test sans %x\n\n\n",  4578453259999999999, 4578453259);

		ft_printf("ft_printf = Test avec (hX) %hX test sans %X\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (hhX) %hhX test sans %X\n\n\n", 457845, 457845);

		ft_printf("ft_printf = Test avec (lX) %lX test sans %X\n\n\n",  4578453259999999999, 4578453255);

		ft_printf("ft_printf = Test avec (llX) %llX test sans %X\n\n\n",  4578453259999999999, 4578453259);

		ft_printf("ft_printf = Test avec (lf) %lf test sans %f\n\n\n",  4578453259999999999.45421, 4578453255.45421);

	}
	// TEST FLAGS l ll h hh L

	// sur les %d
	//  ------------------------ ANCIENNE PARTIE 1 ------------------------------------
	if (test_part2 == 1)
	{
		ft_printf("lalalalala %d\n", 10);
		ft_printf("f- /%5%/\n");
		ft_printf("f- /%-5%/\n");
		ft_printf("f- /%.0%/\n");
		ft_printf("f- /%   %/\n", "test");
		ft_printf("f- /%#x/ /%#x/\n", 0, 5);
		ft_printf("f- /%#04x/\n", 42);
		ft_printf("f- /%#-08x/\n", 42);
		ft_printf("f- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0);
		ft_printf("f- /@moulitest: /%.x/ /%.0x/\n", 0, 0);
		ft_printf("f- /@moulitest: /%s/\n", NULL);
		ft_printf("f- /%.2c/\n", NULL);
		ft_printf("f- /%s %s/\n", NULL, string);
		ft_printf("f- /@moulitest: /%c//\n", 0);
		ft_printf("f- /%2c/\n", 0);
		ft_printf("f- /null %c and text/\n", 0);
		ft_printf("f- /% c/\n", 0);
		ft_printf("f- /%-05o/\n", 2500);
		ft_printf("f- /@moulitest: /%.o/ /%5.0o/\n", 0, 0);
		ft_printf("f- /@moulitest: /%5.o/ /%5.0o/\n", 0, 0);
		ft_printf("f- /@moulitest: /%#.o/ /%#.0o/\n", 0, 0);
		ft_printf("f- /@moulitest: /%.x/ /%.0x/\n", 0, 0);
		ft_printf("f- /@moulitest: /%5.x/ /%5.0x/\n", 0, 0);
		ft_printf("f- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0);
		ft_printf("f- /% d/\n", -42);
		ft_printf("f- /%05d/\n", -42);
		ft_printf("f- /%0+5d/\n", -42);
		ft_printf("f- /%-05d/\n", 42);
		ft_printf("f- /%-05d/\n", -42);
		ft_printf("f- /%hd/\n", 32768);
		ft_printf("f- /%hhd/\n", 128);
		ft_printf("f- /%hhd/\n", -129);
		ft_printf("f- /%lld/\n", -9223372036854775808);
		ft_printf("f- /%03.2d/\n", -1);
		ft_printf("f- /@moulitest: %.10d/\n", -42);
		ft_printf("f- /@moulitest: /%.d/ /%.0d/\n", 0, 0);
		ft_printf("f- /@moulitest: /%5.d/ /%5.0d/\n", 0, 0);
		ft_printf("f- /% u/\n", 4294967295);
		ft_printf("f- /%+u/\n", 4294967295);

		ft_printf("f - {%c}\n", 0);
		ft_printf("f- {%3c}\n", 0);
		ft_printf("f- {%03c}\n", 0);
		ft_printf("f- {%+c}\n", 0);
		ft_printf("f- {% c}\n", 0);
		ft_printf("f - {%05.c}\n", 0);

		ft_printf("f - bonjour /%c/ ca va /%c/ ?\n", 0, 0);

		ft_printf("f - {%s}\n", 0);
		ft_printf("f- {%3s}\n", 0);
		ft_printf("f- {%03s}\n", 0);
		ft_printf("f- {%+s}\n", 0);
		ft_printf("f- {% s}\n", 0);
		ft_printf("f - {%05.s}\n", 0);
		ft_printf("f - {%05s}\n", 0);
		ft_printf("f - {%03.s}\n", 0);
		ft_printf("f - {%05.s}\n", "bouuuuh");
		ft_printf("f - {%05s}\n", "ha");
		ft_printf("f - {%03.s}\n", "mais pourquoi?");
		ft_printf("f - {%05.10s}\n", 0);
		ft_printf("f - {%05s}\n", 0);
		ft_printf("f - {%03.4s}\n", 0);


		ft_printf("f- %o, %ho, %hho\n", -42, -42, -42);

		ft_printf("f- /%4.s/\n", "42");

		ft_printf("f- %+- Z0#10.50hhd\n", 42);
		ft_printf("f - /% +10.5hZhdoooo/\n", 42);

		ft_putstr("1er\n");
		ft_printf("%.o", 0);
		ft_putstr("\n2 eme \n");
		ft_printf("%.0o",0);
		ft_putstr("\nfin\n");
		ft_printf("valeur de retour = %d\n", ft_printf("@moulitest: ->%.o<- ->%.0o<-/\n", 0, 0));

		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- \n/%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.0);

		ft_printf("@moulitest: /%.d/ /%.0d/\n", 0, 0);
	}
	//	-------------------- ANCIENNE PARTIE 2 ------------------------------------

	if (test_part3 == 1)
	{
		// test des limites 

		ft_printf("-f UCHAR_MAX = %d\n", UCHAR_MAX);
		ft_printf("-f USHRT_MAX = %d\n", USHRT_MAX);
		ft_printf("f- The number of bits in a byte %d\n", CHAR_BIT);
		ft_printf("f- The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
		ft_printf("f- The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
		ft_printf("f- The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);
		ft_printf("f- The minimum value of SHORT INT = %d\n", SHRT_MIN);
		ft_printf("f- The maximum value of SHORT INT = %d\n", SHRT_MAX);
		ft_printf("f- The minimum value of INT = %d\n", INT_MIN);
		ft_printf("f- The maximum value of INT = %d\n", INT_MAX);
		ft_printf("f- The minimum value of CHAR = %d\n", CHAR_MIN);
		ft_printf("f- The maximum value of CHAR = %d\n", CHAR_MAX);
		ft_printf("f- The minimum value of LONG = %ld\n", LONG_MIN);
		ft_printf("f- The maximum value of LONG = %ld\n", LONG_MAX);

		//TEST DES H L LL

		// sur les %d
		ft_printf("zeroshort = %hd // short1 = %hd // short2 = %hd // short_max = %hd // short_min = %hd\n", zeroshort, short1, short2, short_max, short_min);

		ft_printf("zeroint = %d // int1 = %d // int2 = %d // int_max = %d // int_min = %d\n", zeroint, int1, int2, int_max, int_min);

		ft_printf("zerolong = %ld // long1 = %ld // long2 = %ld // long_max = %ld // long_min = %ld\n", zerolong, long1, long2, long_max, long_min);

		ft_printf("zerolonglong = %lld // longlong1 = %lld // longlong2 = %lld // longlong_max = %lld // longlong_min = %lld\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %o

		ft_printf("zeroshort = %ho // short1 = %ho // short2 = %ho // short_max = %ho // short_min = %ho\n", zeroshort, short1, short2, short_max, short_min);

		ft_printf("zeroint = %o // int1 = %o // int2 = %o // int_max = %o // int_min = %o\n", zeroint, int1, int2, int_max, int_min);

		ft_printf("zerolong = %lo // long1 = %lo // long2 = %lo // long_max = %lo // long_min = %lo\n", zerolong, long1, long2, long_max, long_min);

		ft_printf("zerolonglong = %llo // longlong1 = %llo // longlong2 = %llo // longlong_max = %llo // longlong_min = %llo\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %x

		ft_printf("zeroshort = %hx // short1 = %hx // short2 = %hx // short_max = %hx // short_min = %hx\n", zeroshort, short1, short2, short_max, short_min);

		ft_printf("zeroint = %x // int1 = %x // int2 = %x // int_max = %x // int_min = %x\n", zeroint, int1, int2, int_max, int_min);

		ft_printf("zerolong = %lx // long1 = %lx // long2 = %lx // long_max = %lx // long_min = %lx\n", zerolong, long1, long2, long_max, long_min);

		ft_printf("zerolonglong = %llx // longlong1 = %llx // longlong2 = %llx // longlong_max = %llx // longlong_min = %llx\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %u


		ft_printf("zeroshort = %hu // short1 = %hu // short2 = %hu // short_max = %hu // short_min = %hu\n", zeroshort, short1, short2, short_max, short_min);

		ft_printf("zeroint = %u // int1 = %u // int2 = %u // int_max = %u // int_min = %u\n", zeroint, int1, int2, int_max, int_min);

		ft_printf("zerolong = %lu // long1 = %lu // long2 = %lu // long_max = %lu // long_min = %lu\n", zerolong, long1, long2, long_max, long_min);

		ft_printf("zerolonglong = %llu // longlong1 = %llu // longlong2 = %llu // longlong_max = %llu // longlong_min = %llu\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %f

		ft_printf("/%-+10f/\n\n", crash_float);

		ft_printf("/%-+10f/\n\n", crash_float2);

		ft_printf("/%+10f/\n\n", crash_float);

		ft_printf("/%+10f/\n\n", crash_float2);

		ft_printf("/%-10f/\n\n", crash_float);

		ft_printf("/%-10f/\n\n", crash_float2);

		ft_printf("/%10f/\n\n", crash_float2);	

		ft_printf("/%f/\n\n", crash_float);

		// sur les %f	

		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", t_f1, t_f2, t_f3, t_f4, t_f5, t_f6, t_f7, -5.6);

		ft_printf("f- /%.9Lf/\n", t_f);

		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.123456789);

		ft_printf("f - /%x/ -- /%#x/ \n", t_bit, t_bit);
		ft_printf("f - /%#.Lf/\n", t_f8);

		// TEST DES HH

		ft_printf("/%hhd/ -- /%hho/ -- /%hhu/ -- /%hhx/\n", hh_test, hh_test, hh_test, hh_test);

		//  TEST FLAGS 0 + - ' ' #

		// sur les %o

		// ----------- TEST FLAG HASH -----------

		ft_printf("f- rien /%o/\n", t_o);
		ft_printf("f- seul /%#o/\n", t_o);
		ft_printf("f- avec size /%#10o/\n", t_o);
		ft_printf("f- size > accu /%#10.5o/\n", t_o);
		ft_printf("f- size < accu /%#5.10o/\n", t_o);

		ft_printf("f- rien /%-o/\n", t_o);
		ft_printf("f- seul /%-o/\n", t_o);
		ft_printf("f- avec size /%-10o/\n", t_o);
		ft_printf("f- size > accu /%o/ /%-o/ /%-10o/ /%-10.o/ /%-10.5o/\n", t_o, t_o, t_o, t_o, t_o);
		ft_printf("f- size < accu /%o/ /%-o/ /%-5o/ /%-5.o/ /%-5.10o/\n", t_o, t_o, t_o, t_o, t_o);


		ft_printf("f- rien /%#-o/\n", t_o);
		ft_printf("f- seul /%#-o/\n", t_o);
		ft_printf("f- avec size /%#-10o/\n", t_o);
		ft_printf("f- size > accu /%#-10.5o/\n", t_o);
		ft_printf("f- size < accu /%#-5.10o/\n", t_o);

		//	sur les %x
	}
	// ----------- TEST FLAG HASH -----------

	if (test_part4 == 1)
	{
		ft_printf("f- rien /%x/\n", t_x);
		ft_printf("f- seul /%#x/\n", t_x);
		ft_printf("f- avec size /%#10x/\n", t_x);
		ft_printf("f- size > accu /%#10.5x/\n", t_x);
		ft_printf("f- size < accu /%#5.10x/\n", t_x);
		ft_printf("f- rien /%-x/\n", t_x);
		ft_printf("f- seul /%-x/\n", t_x);
		ft_printf("f- avec size /%-10x/\n", t_x);
		ft_printf("f- size > accu /%-10.5x/\n", t_x);
		ft_printf("f- size < accu /%-5.10x/\n", t_x);
		ft_printf("f- rien /%#-x/\n", t_x);
		ft_printf("f- seul /%#-x/\n", t_x);
		ft_printf("f- avec size /%#-10x/\n", t_x);
		ft_printf("f- size > accu /%#-10.5x/\n", t_x);
		ft_printf("f- size < accu /%#-5.10x/\n", t_x);

		//	sur les %X

		// ----------- TEST FLAG HASH -----------


		ft_printf("f- rien /%X/\n", t_X);
		ft_printf("f- seul /%#X/\n", t_X);
		ft_printf("f- avec size /%#10X/\n", t_X);
		ft_printf("f- size > accu /%#10.5X/\n", t_X);
		ft_printf("f- size < accu /%#5.10X/\n", t_X);
		ft_printf("f- rien /%-X/\n", t_X);
		ft_printf("f- seul /%-X/\n", t_X);
		ft_printf("f- avec size /%-10X/\n", t_X);
		ft_printf("f- size > accu /%-10.5X/\n", t_X);
		ft_printf("f- size < accu /%-5.10X/\n", t_X);
		ft_printf("f- rien /%#-X/\n", t_X);
		ft_printf("f- seul /%#-X/\n", t_X);
		ft_printf("f- avec size /%#-10X/\n", t_X);
		ft_printf("f- size > accu /%#-10.5X/\n", t_X);
		ft_printf("f- size < accu /%#-5.10X/\n", t_X);
		ft_printf("f- size = accu /%#-10.10X/\n", t_X);

		// sur les %d

		// ----------- TEST FLAG PLUS ------------

		ft_printf("f- plus tout seul        /%+d/\n", t_d);
		ft_printf("f- plus avec size        /%+10d/\n", t_d);
		ft_printf("f- plus avec accu        /%+.5d/\n", t_d);
		ft_printf("f- plus avec size > accu /%+10.5d/\n", t_d);
		ft_printf("f- plus avec size < accu /%+5.10d/\n", t_d);
		ft_printf("f- plus avec size = accu /%+10.10d/\n", t_d);

		// ------------ TEST FLAG ZERO --------------

		ft_printf("f- zero tout seul            /%0d/\n", t_d);
		ft_printf("f- zero avec size            /%010d/\n", t_d);
		ft_printf("f- zero avec accu            /%0.5d/\n", t_d);
		ft_printf("f- zero avec size > accu     /%010.5d/\n", t_d);
		ft_printf("f- zero avec size < accu     /%05.10d/\n", t_d);
		ft_printf("f- zero avec size = accu     /%010.10d/\n", t_d);

		// ------------ TEST FLAG SPACE --------------

		ft_printf("f- space tout seul            /% d/\n", t_d);
		ft_printf("f- space avec size            /% 10d/\n", t_d);
		ft_printf("f- space avec accu            /% .5d/\n", t_d);
		ft_printf("f- space avec size > accu     /% 10.5d/\n", t_d);
		ft_printf("f- space avec size < accu     /% 5.10d/\n", t_d);
		ft_printf("f- space avec size = accu     /% 10.10d/\n", t_d);

		// ------------- TEST FLAG MINUS ------------

		ft_printf("f- minus tout seul            /%-d/\n", t_d);
		ft_printf("f- minus avec size            /%-10d/\n", t_d);
		ft_printf("f- minus avec accu            /%-.5d/\n", t_d);
		ft_printf("f- minus avec size > accu     /%-10.5d/\n", t_d);
		ft_printf("f- minus avec size < accu     /%-5.10d/\n", t_d);
		ft_printf("f- minus avec size = accu     /%-10.10d/\n", t_d);

		// ------------- TEST FLAG PLUS ZERO SPACE MINUS

		ft_printf("\n\nTEST FLAG PLUS ZERO SPACE MINUS\n"), F;
		ft_printf("f- plus et minus seuls            /%+-d/\n", t_d);
		ft_printf("f- plus et minus avec size        /%+-10d/\n", t_d);
		ft_printf("f- plus et minus avec accu        /%+-.5d/\n", t_d);
		ft_printf("f- plus et minus avec size > accu /%+-10.5d/\n", t_d);
		ft_printf("f- plus et minus avec size < accu /%+-5.10d/\n", t_d);
		ft_printf("f- plus et minus avec size = accu /%+-10.10d/\n", t_d);

		ft_printf("\n2 by 2 ==> PLUS and ZERO\n"), F;
		ft_printf("f- plus et zero seuls            /%+0d/\n", t_d);
		ft_printf("f- plus et zero avec size        /%+010d/\n", t_d);
		ft_printf("f- plus et zero avec accu        /%+0.5d/\n", t_d);
		ft_printf("f- plus et zero avec size > accu /%+010.5d/\n", t_d);
		ft_printf("f- plus et zero avec size < accu /%+05.10d/\n", t_d);
		ft_printf("f- plus et zero avec size = accu /%+010.10d/\n", t_d);

		ft_printf("\n2 by 2 ==> MINUS and SPACE\n"), F;
		ft_printf("f- minus et space seuls            /%- d/\n", t_d);
		ft_printf("f- minus et space avec size        /%- 10d/\n", t_d);
		ft_printf("f- minus et space avec accu        /%- .5d/\n", t_d);
		ft_printf("f- minus et space avec size > accu /%- 10.5d/\n", t_d);
		ft_printf("f- minus et space avec size < accu /%- 5.10d/\n", t_d);
		ft_printf("f- minus et space avec size = accu /%- 10.10d/\n", t_d);

		ft_printf("\n2 by 2 ==> SPACE and ZERO \n"), F;
		ft_printf("f- space et zero seuls            /% 0d/\n", t_d);
		ft_printf("f- space et zero avec size        /% 010d/\n", t_d);
		ft_printf("f- space et zero avec accu        /% 0.5d/\n", t_d);
		ft_printf("f- space et zero avec size > accu /% 010.5d/\n", t_d);
		ft_printf("f- space et zero avec size < accu /% 05.10d/\n", t_d);
		ft_printf("f- space et zero avec size = accu /% 010.10d/\n", t_d);

		// test sur les %u

		ft_printf("\n\n TEST DES %%u"), F;
		ft_printf("\n\nTEST SUR ZERO\n"), F;
		ft_printf("f- zero tout seul            /%0u/\n", t_u);
		ft_printf("f- zero avec size            /%010u/\n", t_u);
		ft_printf("f- zero avec accu            /%0.5u/\n", t_u);
		ft_printf("f- zero avec size > accu     /%010.5u/\n", t_u);
		ft_printf("f- zero avec size < accu     /%05.10u/\n", t_u);
		ft_printf("f- zero avec size = accu     /%010.10u/\n", t_u);

		ft_printf("\nTEST SUR MINUS\n"), F;
		ft_printf("f- minus tout seul            /%-u/\n", t_u);
		ft_printf("f- minus avec size            /%-10u/\n", t_u);
		ft_printf("f- minus avec accu            /%-.5u/\n", t_u);
		ft_printf("f- minus avec size > accu     /%-10.5u/\n", t_u);
		ft_printf("f- minus avec size < accu     /%-5.10u/\n", t_u);
		ft_printf("f- minus avec size = accu     /%-10.10u/\n", t_u);


		//  sur les %c

		// ------------- TEST FLAG MINUS ------------

		ft_printf("\n\nTest on %%c\n"), F;
		ft_printf("TEST FLAG MINUS\n"), F;
		ft_printf("f- minus tout seul            /%-c/\n", t_c);
		ft_printf("f- minus avec size            /%-10c/\n", t_c);

		// sur les %s

		ft_printf("\n\nTest on %%s\n"), F;

		ft_printf("f- moins /%-s/\n", t_s);
		ft_printf("f- size /%20s/\n", t_s);
		ft_printf("f- accu /%.5s/\n", t_s);
		ft_printf("f- size > accu /%20.5s/\n", t_s);
		ft_printf("f- size < accu /%20.30s/\n", t_s);

		ft_printf("f- moins et size /%-20s/\n", t_s);
		ft_printf("f- moins et accu /%.5s/\n", t_s);
		ft_printf("f- moins et size > accu /%-20.5s/\n", t_s);
		ft_printf("f- moins et size < accu /%-20.30s/\n", t_s);

		ft_printf("123456789abcdefghijklmnopqrstuvwxyz");

		// RETURNED INT


		pointer_test = "bonjour";

		ft_printf("nombre rendu = |%d|\n", ft_printf("\n\nbonjour je rends un nombre %+d %+-d %10.5d hahahah\n", 42, 43, 44));


		ft_printf("%x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x \n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);
		ft_printf("test normaux, %% voila le %%d ->%d<- et le %%c ->%c<- et le %%s ->%s<- et le %%x ->%x<- et le %%p ->%p<- et le 0 ->%x<-\n", 42, 'A', "Coucou", 1024, pointer_test, 0);
		ft_printf("check des hexa sur 4 octets : %x /-/ %x /-/ %x\n", 1024, -1024, 2147483647);
		ft_printf("check des hexa plus dur : %x /-/ %x /-/ %lx /-/ %x\n", 2147483647, -2147483647, 2147483656, -1);


		ft_printf("\n\n Test on %%f\nTESTS FLAG HASH\n"), F;
		ft_printf("f- rien /%f/\n", t_fl);
		ft_printf("f- seul /%#f/\n", t_fl);
		ft_printf("f- avec size /%#10f/\n", t_fl);
		ft_printf("f- size > accu /%#10.5f/\n", t_fl);
		ft_printf("f- size < accu /%#5.10f/\n", t_fl);

		ft_printf("\n\n TESTS FLAG MINUS\n"), F;
		ft_printf("f- rien /%-f/\n", t_fl);
		ft_printf("f- seul /%-f/\n", t_fl);
		ft_printf("f- avec size /%-10f/\n", t_fl);
		ft_printf("f- size > accu /%-10.5f/\n", t_fl);
		ft_printf("f- size < accu /%-5.10f/\n", t_fl);

		ft_printf("\n\n TESTS FLAG MINUS AND HASH\n"), F;
		ft_printf("f- rien /%#-f/\n", t_fl);
		ft_printf("f- seul /%#-f/\n", t_fl);
		ft_printf("f- avec size /%#-10f/\n", t_fl);
		ft_printf("f- size > accu /%#-10.5f/\n", t_fl);
		ft_printf("f- size < accu /%#-5.10f/\n", t_fl);

		// ------------ TEST FLAG PLUS --------------

		ft_printf("\n\nTest on %%d\nTESTS FLAG PLUS\n"), F;
		ft_printf("f- plus tout seul        /%+f/\n", t_fl);
		ft_printf("f- plus avec size        /%+10f/\n", t_fl);
		ft_printf("f- plus avec accu        /%+.5f/\n", t_fl);
		ft_printf("f- plus avec size > accu /%+10.5f/\n", t_fl);
		ft_printf("f- plus avec size < accu /%+5.10f/\n", t_fl);
		ft_printf("f- plus avec size = accu /%+10.10f/\n", t_fl);

		// ------------ TEST FLAG ZERO --------------

		ft_printf("\n\nTEST FLAG ZERO\n"), F;
		ft_printf("f- zero tout seul            /%0f/\n", t_fl);
		ft_printf("f- zero avec size            /%010f/\n", t_fl);
		ft_printf("f- zero avec accu            /%0.5f/\n", t_fl);
		ft_printf("f- zero avec size > accu     /%010.5f/\n", t_fl);
		ft_printf("f- zero avec size < accu     /%05.10f/\n", t_fl);
		ft_printf("f- zero avec size = accu     /%010.10f/\n", t_fl);

		// ------------ TEST FLAG SPACE --------------

		ft_printf("\n\nTEST FLAG SPACE\n"), F;
		ft_printf("f- space tout seul            /% f/\n", t_fl);
		ft_printf("f- space avec size            /% 10f/\n", t_fl);
		ft_printf("f- space avec accu            /% .5f/\n", t_fl);
		ft_printf("f- space avec size > accu     /% 10.5f/\n", t_fl);
		ft_printf("f- space avec size < accu     /% 5.10f/\n", t_fl);
		ft_printf("f- space avec size = accu     /% 10.10f/\n", t_fl);

		// ------------- TEST FLAG MINUS ------------

		ft_printf("\n\nTEST FLAG MINUS\n"), F;
		ft_printf("f- minus tout seul            /%-f/\n", t_fl);
		ft_printf("f- minus avec size            /%-10f/\n", t_fl);
		ft_printf("f- minus avec accu            /%-.5f/\n", t_fl);
		ft_printf("f- minus avec size > accu     /%-10.5f/\n", t_fl);
		ft_printf("f- minus avec size < accu     /%-5.10f/\n", t_fl);
		ft_printf("f- minus avec size = accu     /%-10.10f/\n", t_fl);

		// ------------- TEST FLAG PLUS ZERO SPACE MINUS

		ft_printf("\n\nTEST FLAG PLUS ZERO SPACE MINUS\n"), F;
		ft_printf("f- plus et minus seuls            /%+-f/\n", t_fl);
		ft_printf("f- plus et minus avec size        /%+-10f/\n", t_fl);
		ft_printf("f- plus et minus avec accu        /%+-.5f/\n", t_fl);
		ft_printf("f- plus et minus avec size > accu /%+-10.5f/\n", t_fl);
		ft_printf("f- plus et minus avec size < accu /%+-5.10f/\n", t_fl);
		ft_printf("f- plus et minus avec size = accu /%+-10.10f/\n", t_fl);
		
		ft_printf("\n2 by 2 ==> PLUS and ZERO\n"), F;
		ft_printf("f- plus et zero seuls            /%+0f/\n", t_fl);
		ft_printf("f- plus et zero avec size        /%+010f/\n", t_fl);
		ft_printf("f- plus et zero avec accu        /%+0.5f/\n", t_fl);
		ft_printf("f- plus et zero avec size > accu /%+010.5f/\n", t_fl);
		ft_printf("f- plus et zero avec size < accu /%+05.10f/\n", t_fl);
		ft_printf("f- plus et zero avec size = accu /%+010.10f/\n", t_fl);

		ft_printf("\n2 by 2 ==> MINUS and SPACE\n"), F;
		ft_printf("f- minus et space seuls            /%- f/\n", t_fl);
		ft_printf("f- minus et space avec size        /%- 10f/\n", t_fl);
		ft_printf("f- minus et space avec accu        /%- .5f/\n", t_fl);
		ft_printf("f- minus et space avec size > accu /%- 10.5f/\n", t_fl);
		ft_printf("f- minus et space avec size < accu /%- 5.10f/\n", t_fl);
		ft_printf("f- minus et space avec size = accu /%- 10.10f/\n", t_fl);

		ft_printf("\n2 by 2 ==> SPACE and ZERO \n"), F;
		ft_printf("f- space et zero seuls            /% 0f/\n", t_fl);
		ft_printf("f- space et zero avec size        /% 010f/\n", t_fl);
		ft_printf("f- space et zero avec accu        /% 0.5f/\n", t_fl);
		ft_printf("f- space et zero avec size > accu /% 010.5f/\n", t_fl);
		ft_printf("f- space et zero avec size < accu /% 05.10f/\n", t_fl);
		ft_printf("f- space et zero avec size = accu /% 010.10f/\n", t_fl);
	}
	if (test_bonus == 1)
	{
		ft_printf("f - b = /%b/\n", 42);

		ft_printf("/%#llb/\n", 2147483647);
		ft_printf("/%#hhb/\n", 2147483647);
		ft_printf("/%#hb/\n", 2147483647);
		ft_printf("/%#lb/\n", 2147483647);
		ft_printf("/%#b/\n", 2147483647);
		ft_printf("/%#b/\n", -1);
		ft_printf("/%#b/\n", 42);

		ft_printf("/%llb/\n", 2147483647);
		ft_printf("/%hhb/\n", 2147483647);
		ft_printf("/%hb/\n", 2147483647);
		ft_printf("/%lb/\n", 2147483647);
		ft_printf("/%b/\n", 2147483647);
		ft_printf("/%b/\n", -1);
		ft_printf("/%b/\n", 42);

		fill_tab = -1;
		int_tab = (int**)malloc(sizeof(int*) * 11);
		while (++fill_tab < 10)
			int_tab[fill_tab] = (int*)malloc(sizeof(int) * 10);
		fill_tab = -1;
		while (++fill_tab < 10)
		{
			fill_case = -1;
			while (++fill_case < 10)
			{
				int_tab[fill_tab][fill_case] = put_int;
				put_int *= 5;
			}
		}
		int_tab[10] = NULL;
		fill_tab = -1;
		ft_printf("=========\n"), fflush(stdout);
		while (++fill_tab < 10)
		{
			fill_case = -1;
			while (++fill_case < 10)
			{
				ft_printf("%d", int_tab[fill_tab][fill_case]), fflush(stdout);
				ft_putchar(' ');
			}
			ft_putchar('\n');
		}
		ft_printf("=========\n"), fflush(stdout);
		ft_printf("{B.T.white.S.blue.}%3.1t{eoc}\n", int_tab, 10, 10);
		ft_printf("=========\n"), fflush(stdout);
		fill_tab = -1;
		while (++fill_tab < 10)
			free(int_tab[fill_tab]);
		free(int_tab);

		tab2 = malloc(sizeof(char *) * 10), fflush(stdout);
		while (++i2 < 9)
			tab2[i2] = malloc(sizeof(char) * 10), fflush(stdout);
		i2 = -1;
		while (++i2 < 9)
		{
			j2 = -1;
			while (++j2 < 9)
			{
				tab2[i2][j2] = c2;
				c2++;
			}
			tab2[i2][j2] = '\0';
		}
		tab2[i2] = NULL;
		i2 = -1;
		ft_printf("=========\n"), fflush(stdout);
		while (tab2[++i2])
			ft_putendl(tab2[i2]), fflush(stdout);
		ft_printf("=========\n"), fflush(stdout);
		ft_printf("=========\n"), fflush(stdout);
		ft_printf("{B.F.T.white.S.blue.}%3.1T{eoc}\n", tab2), fflush(stdout);
		ft_printf("=========\n"), fflush(stdout);
		i2 = -1;
		while (tab2[++i2])
			free(tab2[i2]), fflush(stdout);
		free(tab2), fflush(stdout);

		ft_putstr("\033[32;41;5m		texte qui clignote !!!			\033[0m\n");

example_triple = (char***)malloc(sizeof(char**) * 7);
	example_triple[0] = ft_strsplit("voici la premiere ligne a imprimer", ' ');
	example_triple[1] = ft_strsplit("la deuxieme ligne est un peu plus longue a ecrire", ' ');
	example_triple[2] = ft_strsplit("la troisieme beauuuucoup moins", ' ');
	example_triple[3] = ft_strsplit("4 eme plus de cases que les 3 d'avant mais ca marche un peu quand meme", ' ');
	example_triple[4] = ft_strsplit("fin . . . . . . . . . . .", ' ');
	example_triple[5] = ft_strsplit("-", ' ');
	example_triple[6] = NULL;

	printf("============== TRIPLE TAB =============\n");
	while (example_triple[++m])
	{
		n = -1;
		while (example_triple[m][++n])
		{
			o = -1;
			while (example_triple[m][n][++o])
				ft_putchar(example_triple[m][n][o]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	printf("=======================================\n");

	m = -1;
	while (example_triple[++m])
	{
		n = -1;
		while (example_triple[m][++n])
			free(example_triple[m][n]);
		free(example_triple[m]);
	}
	free(example_triple);

	}
	return (0);
}
