#include "ft_printf.h"
#include <stdio.h>

/*
 ** affiche les parametres des flags -->	printf("\nles valeurs retenues sont :\n conversion = %c\n hh  = %d\n h   = %d\n ll  = %d\n l   = %d\n L   = %d\n #   = %d\n -   = %d\n +   = %d\n ' ' = %d\n .   = %d\n 0   = %d\n size = %d\n accu = %d \n nb_zero = %d \n bad_conv = %d\n", d->conv, d->hh, d->h, d->ll, d->l, d->lf, d->hash, d->minus, d->plus, d->space, d->point, d->zero, d->size, d->accu, d->nb_zero, d->bad_conv);
 */
#include <math.h>
#include <limits.h>

#define F fflush(stdout)

int		main(void)
{
	char **tab;
	int i = -1;
	int j;
	char c = 33;
	char	*p1;
	char *string = NULL;
		short	zeroshort = 0;
		short	short1 = 15;
		short	short2 = -15;
		short	short_max = 32767;
		short	short_min = -32767;
		int	zeroint = 0;
		int int1 = 25;
		int	int2 = -25;
		int	int_max = 2147483647;
		int	int_min = -2147483648;
		long	zerolong = 0;
		long	long1 = 35;
		long	long2 = -35;
		long	long_max = 9223372036854775807;
		long	long_min = -9223372036854775807;
		long long	zerolonglong = 0;
		long long	longlong1 = 45;
		long long	longlong2 = -45;
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
		int t_X = 15;
		int t_d = 42;
		unsigned int t_u = 52;
		char t_c = '*';
		char	*pointer_test;
		char *t_s = "    123456789     ";


	// TEST FLAGS l ll h hh L

	// sur les %d
		//  ------------------------ ANCIENNE PARTIE 1 ------------------------------------

		ft_printf("lalalalala %d\n", 10);
				printf("v- /%5%/\n"), F;
		ft_printf("f- /%5%/\n");
		printf("v- /%-5%/\n"), F;
		ft_printf("f- /%-5%/\n");
		printf("v- /%.0%/\n"), F;
		ft_printf("f- /%.0%/\n");
		printf("v- /%   %/\n", "test"), F;
		ft_printf("f- /%   %/\n", "test");
		printf("v- /%#x/ /%#x/\n", 0, 5), F;
		ft_printf("f- /%#x/ /%#x/\n", 0, 5);
		printf("v- /%#04x/\n", 42), F;
		ft_printf("f- /%#04x/\n", 42);
		printf("v- /%#-08x/\n", 42), F;
		ft_printf("f- /%#-08x/\n", 42);
		printf("v- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0);
		printf("v- /@moulitest: /%.x/ /%.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.x/ /%.0x/\n", 0, 0);
		printf("v- /@moulitest: /%5.x/ /%5.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%5.x/ /%5.0x/\n", 0, 0);
		printf("v- /@moulitest: /%s/\n", NULL), F;
		ft_printf("f- /@moulitest: /%s/\n", NULL);
		printf("v- /%.2c/\n", NULL), F;
		ft_printf("f- /%.2c/\n", NULL);
		printf("v- /%s %s/\n", NULL, string), F;
		ft_printf("f- /%s %s/\n", NULL, string);
		printf("v- /@moulitest: /%c//\n", 0), F;
		ft_printf("f- /@moulitest: /%c//\n", 0);
		printf("v- /%2c/\n", 0), F;
		ft_printf("f- /%2c/\n", 0);
		printf("v- /null %c and text/\n", 0), F;
		ft_printf("f- /null %c and text/\n", 0);
		printf("v- /% c/\n", 0), F;
		ft_printf("f- /% c/\n", 0);
		printf("v- /%-05o/\n", 2500), F;
		ft_printf("f- /%-05o/\n", 2500);
		printf("v- /@moulitest: /%.o/ /%.0o/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.o/ /%.0o/\n", 0, 0);
		printf("v- /@moulitest: /%5.o/ /%5.0o/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%5.o/ /%5.0o/\n", 0, 0);
		printf("v- /@moulitest: /%#.o/ /%#.0o/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%#.o/ /%#.0o/\n", 0, 0);
		printf("v- /@moulitest: /%.x/ /%.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.x/ /%.0x/\n", 0, 0);
		printf("v- /@moulitest: /%5.x/ /%5.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%5.x/ /%5.0x/\n", 0, 0);
		printf("v- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0);
		printf("v- /% d/\n", -42), F;
		ft_printf("f- /% d/\n", -42);
		printf("v- /%05d/\n", -42), F;
		ft_printf("f- /%05d/\n", -42);
		printf("v- /%0+5d/\n", -42), F;
		ft_printf("f- /%0+5d/\n", -42);
		printf("v- /%-05d/\n", 42), F;
		ft_printf("f- /%-05d/\n", 42);
		printf("v- /%-05d/\n", -42), F;
		ft_printf("f- /%-05d/\n", -42);
		printf("v- /%hd/\n", 32768), F;
		ft_printf("f- /%hd/\n", 32768);
		printf("v- /%hhd/\n", 128), F;
		ft_printf("f- /%hhd/\n", 128);
		printf("v- /%hhd/\n", -129), F;
		ft_printf("f- /%hhd/\n", -129);
		printf("v- /%lld/\n", -9223372036854775808), F;
		ft_printf("f- /%lld/\n", -9223372036854775808);
		printf("v- /%03.2d/\n", -1), F;
		ft_printf("f- /%03.2d/\n", -1);
		printf("v- /@moulitest: %.10d/\n", -42), F;
		ft_printf("f- /@moulitest: %.10d/\n", -42);
		printf("v- /@moulitest: /%.d/ /%.0d/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.d/ /%.0d/\n", 0, 0);
		printf("v- /@moulitest: /%5.d/ /%5.0d/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%5.d/ /%5.0d/\n", 0, 0);
		printf("v- /% u/\n", 4294967295), F;
		ft_printf("f- /% u/\n", 4294967295);
		printf("v- /%+u/\n", 4294967295), F;
		ft_printf("f- /%+u/\n", 4294967295);

		printf("-->"), F;
		printf(" ==> [%d] ", printf("%")), F;
		printf("<--\n"), F;
		printf("-->"), F;
		printf(" ==> [%d] ", ft_printf("%")), F;
		printf("<--\n"), F;

		printf("v - {%c}\n", 0), F;
		ft_printf("f - {%c}\n", 0);
		printf("v- {%3c}\n", 0), F;
		ft_printf("f- {%3c}\n", 0);
		printf("v- {%03c}\n", 0), F;
		ft_printf("f- {%03c}\n", 0);
		printf("v- {%+c}\n", 0), F;
		ft_printf("f- {%+c}\n", 0);
		printf("v- {% c}\n", 0), F;
		ft_printf("f- {% c}\n", 0);
		printf("v - {%05.c}\n", 0), F;
		ft_printf("f - {%05.c}\n", 0);

	printf("v - bonjour /%c/ ca va /%c/ ?\n", 0, 0), F;
	ft_printf("f - bonjour /%c/ ca va /%c/ ?\n", 0, 0);

		printf(" --> [%d]\n", printf("v - {%c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f - {%c}", 0));
		printf(" --> [%d]\n", printf("v- {%3c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {%3c}", 0));
		printf(" --> [%d]\n", printf("v- {%03c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {%03c}", 0));
		printf(" --> [%d]\n", printf("v- {%+c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {%+c}", 0));
		printf(" --> [%d]\n", printf("v- {% c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {% c}", 0));
		printf(" --> [%d]\n", printf("v - {%05.c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f - {%05.c}", 0));

		printf("v- %o, %ho, %hho\n", -42, -42, -42), F;
		ft_printf("f- %o, %ho, %hho\n", -42, -42, -42);

		printf("v- /%4.s/\n", "42"), F;
		ft_printf("f- /%4.s/\n", "42");

		printf("v- %+- Z0#10.50hhd\n", 42),fflush(stdout);
		ft_printf("f- %+- Z0#10.50hhd\n", 42);
		printf("v - /% +10.5hZhdoooo/\n", 42), fflush(stdout);
		ft_printf("f - /% +10.5hZhdoooo/\n", 42);

		printf("valeur de retour = %d\n", printf("@moulitest: ->%.o<- ->%.0o<-/\n", 0, 0)), F;
		ft_putstr("1er\n");
		ft_printf("%.o", 0);
		ft_putstr("\n2 eme \n");
		ft_printf("%.0o",0);
		ft_putstr("\nfin\n");
		ft_printf("valeur de retour = %d\n", ft_printf("@moulitest: ->%.o<- ->%.0o<-/\n", 0, 0));

		printf("v- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- \n/%lf/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.0), F;
		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- \n/%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.0);


		printf("@moulitest: /%.d/ /%.0d/\n", 0, 0), F;
		ft_printf("@moulitest: /%.d/ /%.0d/\n", 0, 0);

//	-------------------- ANCIENNE PARTIE 2 ------------------------------------


		// test des limites 

		printf("-v UCHAR_MAX = %d\n", UCHAR_MAX), F;
		ft_printf("-f UCHAR_MAX = %d\n", UCHAR_MAX);

		printf("-v USHRT_MAX = %d\n", USHRT_MAX), F;
		ft_printf("-f USHRT_MAX = %d\n", USHRT_MAX);

		printf("v- The number of bits in a byte %d\n", CHAR_BIT), F;
		ft_printf("f- The number of bits in a byte %d\n", CHAR_BIT);

		printf("v- The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN), F;
		ft_printf("f- The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
		printf("v- The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX), F;
		ft_printf("f- The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
		printf("v- The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX), F;
		ft_printf("f- The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

		printf("v- The minimum value of SHORT INT = %d\n", SHRT_MIN), F;
		ft_printf("f- The minimum value of SHORT INT = %d\n", SHRT_MIN);
		printf("v- The maximum value of SHORT INT = %d\n", SHRT_MAX), F; 
		ft_printf("f- The maximum value of SHORT INT = %d\n", SHRT_MAX);

		printf("v- The minimum value of INT = %d\n", INT_MIN), F;
		ft_printf("f- The minimum value of INT = %d\n", INT_MIN);
		printf("v- The maximum value of INT = %d\n", INT_MAX), F;
		ft_printf("f- The maximum value of INT = %d\n", INT_MAX);

		printf("v- The minimum value of CHAR = %d\n", CHAR_MIN), F;
		ft_printf("f- The minimum value of CHAR = %d\n", CHAR_MIN);
		printf("v- The maximum value of CHAR = %d\n", CHAR_MAX), F;
		ft_printf("f- The maximum value of CHAR = %d\n", CHAR_MAX);

		printf("v- The minimum value of LONG = %ld\n", LONG_MIN), F;
		ft_printf("f- The minimum value of LONG = %ld\n", LONG_MIN);
		printf("v- The maximum value of LONG = %ld\n", LONG_MAX), F;
		ft_printf("f- The maximum value of LONG = %ld\n", LONG_MAX);

		//TEST DES H L LL

		// sur les %d
		printf("\n\nTEST DES H L LL\n"), F;
		printf("\n\nSUR LES d\n"), F;
		printf("TEST VALEUR SHORT\n"), F;
		printf("zeroshort = %hd // short1 = %hd // short2 = %hd // short_max = %hd // short_min = %hd\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %hd // short1 = %hd // short2 = %hd // short_max = %hd // short_min = %hd\n", zeroshort, short1, short2, short_max, short_min);

		printf("TEST VALEUR INT\n"), F;
		printf("zeroint = %d // int1 = %d // int2 = %d // int_max = %d // int_min = %d\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %d // int1 = %d // int2 = %d // int_max = %d // int_min = %d\n", zeroint, int1, int2, int_max, int_min);

		printf("TEST VALEUR LONG\n"), F;
		printf("zerolong = %ld // long1 = %ld // long2 = %ld // long_max = %ld // long_min = %ld\n", zerolong, long1, long2, long_max, long_min);
		ft_printf("zerolong = %ld // long1 = %ld // long2 = %ld // long_max = %ld // long_min = %ld\n", zerolong, long1, long2, long_max, long_min);

		printf("TEST VALEUR LONG LONG\n"), F;
		printf("zerolonglong = %lld // longlong1 = %lld // longlong2 = %lld // longlong_max = %lld // longlong_min = %lld\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %lld // longlong1 = %lld // longlong2 = %lld // longlong_max = %lld // longlong_min = %lld\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %o


		printf("\n\nSUR LES o\n"), F;
		printf("\nTEST VALEUR SHORT SUR CONVERSION o\n"), F;
		printf("zeroshort = %ho // short1 = %ho // short2 = %ho // short_max = %ho // short_min = %ho\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %ho // short1 = %ho // short2 = %ho // short_max = %ho // short_min = %ho\n", zeroshort, short1, short2, short_max, short_min);

		printf("\nTEST VALEUR INT SUR CONVERSION o\n"), F;
		printf("zeroint = %o // int1 = %o // int2 = %o // int_max = %o // int_min = %o\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %o // int1 = %o // int2 = %o // int_max = %o // int_min = %o\n", zeroint, int1, int2, int_max, int_min);

		printf("\nTEST VALEUR LONG SUR CONVERSION o\n"), F;
		printf("zerolong = %lo // long1 = %lo // long2 = %lo // long_max = %lo // long_min = %lo\n", zerolong, long1, long2, long_max, long_min), F;
//		ft_printf("zerolong = %lo // long1 = %lo // long2 = %lo // long_max = %lo // long_min = %lo\n", zerolong, long1, long2, long_max, long_min);
//		ft_printf("zerolong = %lo\n", zerolong);
//		ft_printf("long1 = %lo\n", long1);
		printf("v - long2 = %lo\n", (long)-35), F;
		ft_printf("f - long2 = %lo\n", (long)-35);
//		ft_printf("long_max = %lo\n", long_max);
//		ft_printf("long_min = %lo\n", long_min);

/*		printf("\nTEST VALEUR LONG LONG SUR CONVERSION o\n"), F;
		printf("zerolonglong = %llo // longlong1 = %llo // longlong2 = %llo // longlong_max = %llo // longlong_min = %llo\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %llo // longlong1 = %llo // longlong2 = %llo // longlong_max = %llo // longlong_min = %llo\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);
*/
		// sur les %x

		printf("\n\nSUR LES x\n"), F;
		printf("\nTEST VALEUR SHORT SUR CONVERSION x\n"), F;
		printf("zeroshort = %hx // short1 = %hx // short2 = %hx // short_max = %hx // short_min = %hx\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %hx // short1 = %hx // short2 = %hx // short_max = %hx // short_min = %hx\n", zeroshort, short1, short2, short_max, short_min);

		printf("\nTEST VALEUR INT	SUR CONVERSION x\n"), F;
		printf("zeroint = %x // int1 = %x // int2 = %x // int_max = %x // int_min = %x\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %x // int1 = %x // int2 = %x // int_max = %x // int_min = %x\n", zeroint, int1, int2, int_max, int_min);

/*		printf("\nTEST VALEUR LONG SUR CONVERSION x\n"), F;
		printf("zerolong = %lx // long1 = %lx // long2 = %lx // long_max = %lx // long_min = %lx\n", zerolong, long1, long2, long_max, long_min), F;
		ft_printf("zerolong = %lx // long1 = %lx // long2 = %lx // long_max = %lx // long_min = %lx\n", zerolong, long1, long2, long_max, long_min);

		printf("\nTEST VALEUR LONG LONG SUR CONVERSION x\n"), F;
		printf("zerolonglong = %llx // longlong1 = %llx // longlong2 = %llx // longlong_max = %llx // longlong_min = %llx\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %llx // longlong1 = %llx // longlong2 = %llx // longlong_max = %llx // longlong_min = %llx\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);
*/
		// sur les %u


		printf("\n\nSUR LES u\n"), F;
		printf("\nTEST VALEUR SHORT SUR CONVERSION u\n"), F;
		printf("zeroshort = %hu // short1 = %hu // short2 = %hu // short_max = %hu // short_min = %hu\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %hu // short1 = %hu // short2 = %hu // short_max = %hu // short_min = %hu\n", zeroshort, short1, short2, short_max, short_min);

		printf("\nTEST VALEUR INT SUR CONVERSION u\n"), F;
		printf("zeroint = %u // int1 = %u // int2 = %u // int_max = %u // int_min = %u\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %u // int1 = %u // int2 = %u // int_max = %u // int_min = %u\n", zeroint, int1, int2, int_max, int_min);

		printf("\nTEST VALEUR LONG SUR CONVERSION u\n"), F;
		printf("zerolong = %lu // long1 = %lu // long2 = %lu // long_max = %lu // long_min = %lu\n", zerolong, long1, long2, long_max, long_min), F;
		ft_printf("zerolong = %lu // long1 = %lu // long2 = %lu // long_max = %lu // long_min = %lu\n", zerolong, long1, long2, long_max, long_min);

		printf("\nTEST VALEUR LONG LONG SUR CONVERSION u\n"), F;
		printf("zerolonglong = %llu // longlong1 = %llu // longlong2 = %llu // longlong_max = %llu // longlong_min = %llu\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %llu // longlong1 = %llu // longlong2 = %llu // longlong_max = %llu // longlong_min = %llu\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %f

		printf("\n\nSUR LES f\n"), F;


		printf("valeur ==>[%d] -- \n", printf("/%-+10F/", crash_float)), F;
		printf("valeur ==>[%d] -- \n", ft_printf("/%-+10F/", crash_float)), F;
		printf("valeur ==>[%d] -- \n", printf("/%-+10F/", crash_float2)), F;
		printf("valeur ==>[%d] -- \n", ft_printf("/%-+10F/", crash_float2)), F;
		// sur les %f	

		printf("v- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", t_f1, t_f2, t_f3, t_f4, t_f5, t_f6, t_f7, -5.6), F;
		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", t_f1, t_f2, t_f3, t_f4, t_f5, t_f6, t_f7, -5.6);

		printf("v- /%.9Lf/\n", t_f), F;
		ft_printf("f- /%.9Lf/\n", t_f);

		printf("v- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.123456789), F;
		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.123456789);

		printf("v - /%x/ -- /%#x/ \n", t_bit, t_bit), F;
		ft_printf("f - /%x/ -- /%#x/ \n", t_bit, t_bit);
		ft_printf("f - /%#.Lf/\n", t_f8);
		printf("v - /%#.Lf/\n", t_f8), F;


		// TEST DES HH


		printf("\n\nTEST DES HH\n"), F;
		printf("/%hhd/ -- /%hho/ -- /%hhu/ -- /%hhx/\n", hh_test, hh_test, hh_test, hh_test), F;
		ft_printf("/%hhd/ -- /%hho/ -- /%hhu/ -- /%hhx/\n", hh_test, hh_test, hh_test, hh_test);


		//  TEST FLAGS 0 + - ' ' #


		printf("\n\nTEST SUR LES FLAGS 0 ' ' + _ #\n"), F;
		// sur les %o

		// ----------- TEST FLAG HASH -----------

		printf("\n\n Test on %%o\nTESTS FLAG HASH\n"), F;
		printf("v- rien /%o/\n", t_o), F;
		ft_printf("f- rien /%o/\n", t_o);
		printf("v- seul /%#o/\n", t_o), F;
		ft_printf("f- seul /%#o/\n", t_o);
		printf("v- avec size /%#10o/\n", t_o), F;
		ft_printf("f- avec size /%#10o/\n", t_o);
		printf("v- size > accu /%#10.5o/\n", t_o), F;
		ft_printf("f- size > accu /%#10.5o/\n", t_o);
		printf("v- size < accu /%#5.10o/\n", t_o), F;
		ft_printf("f- size < accu /%#5.10o/\n", t_o);

		printf("\n\n TESTS FLAG MINUS\n"), F;
		printf("v- rien /%-o/\n", t_o), F;
		ft_printf("f- rien /%-o/\n", t_o);
		printf("v- seul /%-o/\n", t_o), F;
		ft_printf("f- seul /%-o/\n", t_o);
		printf("v- avec size /%-10o/\n", t_o), F;
		ft_printf("f- avec size /%-10o/\n", t_o);
		printf("v- size > accu /%o/ /%-o/ /%-10o/ /%-10.o/ /%-10.5o/\n", t_o, t_o, t_o, t_o, t_o), F;
		ft_printf("f- size > accu /%o/ /%-o/ /%-10o/ /%-10.o/ /%-10.5o/\n", t_o, t_o, t_o, t_o, t_o);
		printf("v- size < accu /%o/ /%-o/ /%-5o/ /%-5.o/ /%-5.10o/\n", t_o, t_o, t_o, t_o, t_o), F;
		ft_printf("f- size < accu /%o/ /%-o/ /%-5o/ /%-5.o/ /%-5.10o/\n", t_o, t_o, t_o, t_o, t_o);


		printf("\n\n TESTS FLAG MINUS AND HASH\n"), F;
		printf("v- rien /%#-o/\n", t_o), F;
		ft_printf("f- rien /%#-o/\n", t_o);
		printf("v- seul /%#-o/\n", t_o), F;
		ft_printf("f- seul /%#-o/\n", t_o);
		printf("v- avec size /%#-10o/\n", t_o), F;
		ft_printf("f- avec size /%#-10o/\n", t_o);
		printf("v- size > accu /%#-10.5o/\n", t_o), F;
		ft_printf("f- size > accu /%#-10.5o/\n", t_o);
		printf("v- size < accu /%#-5.10o/\n", t_o), F;
		ft_printf("f- size < accu /%#-5.10o/\n", t_o);

		//	sur les %x

		// ----------- TEST FLAG HASH -----------


		printf("\n\n Test on %%x\nTESTS FLAG HASH\n"), F;
		printf("v- rien /%x/\n", t_x), F;
		ft_printf("f- rien /%x/\n", t_x);
		printf("v- seul /%#x/\n", t_x), F;
		ft_printf("f- seul /%#x/\n", t_x);
		printf("v- avec size /%#10x/\n", t_x), F;
		ft_printf("f- avec size /%#10x/\n", t_x);
		printf("v- size > accu /%#10.5x/\n", t_x), F;
		ft_printf("f- size > accu /%#10.5x/\n", t_x);
		printf("v- size < accu /%#5.10x/\n", t_x), F;
		ft_printf("f- size < accu /%#5.10x/\n", t_x);
		printf("v- rien /%-x/\n", t_x), F;
		ft_printf("f- rien /%-x/\n", t_x);
		printf("v- seul /%-x/\n", t_x), F;
		ft_printf("f- seul /%-x/\n", t_x);
		printf("v- avec size /%-10x/\n", t_x), F;
		ft_printf("f- avec size /%-10x/\n", t_x);
		printf("v- size > accu /%-10.5x/\n", t_x), F;
		ft_printf("f- size > accu /%-10.5x/\n", t_x);
		printf("v- size < accu /%-5.10x/\n", t_x), F;
		ft_printf("f- size < accu /%-5.10x/\n", t_x);
		printf("v- rien /%#-x/\n", t_x), F;
		ft_printf("f- rien /%#-x/\n", t_x);
		printf("v- seul /%#-x/\n", t_x), F;
		ft_printf("f- seul /%#-x/\n", t_x);
		printf("v- avec size /%#-10x/\n", t_x), F;
		ft_printf("f- avec size /%#-10x/\n", t_x);
		printf("v- size > accu /%#-10.5x/\n", t_x), F;
		ft_printf("f- size > accu /%#-10.5x/\n", t_x);
		printf("v- size < accu /%#-5.10x/\n", t_x), F;
		ft_printf("f- size < accu /%#-5.10x/\n", t_x);

		//	sur les %X

		// ----------- TEST FLAG HASH -----------


		printf("\n\n Test on %%X\nTESTS FLAG HASH\n"), F;
		printf("v- rien /%X/\n", t_X), F;
		ft_printf("f- rien /%X/\n", t_X);
		printf("v- seul /%#X/\n", t_X), F;
		ft_printf("f- seul /%#X/\n", t_X);
		printf("v- avec size /%#10X/\n", t_X), F;
		ft_printf("f- avec size /%#10X/\n", t_X);
		printf("v- size > accu /%#10.5X/\n", t_X), F;
		ft_printf("f- size > accu /%#10.5X/\n", t_X);
		printf("v- size < accu /%#5.10X/\n", t_X), F;
		ft_printf("f- size < accu /%#5.10X/\n", t_X);
		printf("v- rien /%-X/\n", t_X), F;
		ft_printf("f- rien /%-X/\n", t_X);
		printf("v- seul /%-X/\n", t_X), F;
		ft_printf("f- seul /%-X/\n", t_X);
		printf("v- avec size /%-10X/\n", t_X), F;
		ft_printf("f- avec size /%-10X/\n", t_X);
		printf("v- size > accu /%-10.5X/\n", t_X), F;
		ft_printf("f- size > accu /%-10.5X/\n", t_X);
		printf("v- size < accu /%-5.10X/\n", t_X), F;
		ft_printf("f- size < accu /%-5.10X/\n", t_X);
		printf("v- rien /%#-X/\n", t_X), F;
		ft_printf("f- rien /%#-X/\n", t_X);
		printf("v- seul /%#-X/\n", t_X), F;
		ft_printf("f- seul /%#-X/\n", t_X);
		printf("v- avec size /%#-10X/\n", t_X), F;
		ft_printf("f- avec size /%#-10X/\n", t_X);
		printf("v- size > accu /%#-10.5X/\n", t_X), F;
		ft_printf("f- size > accu /%#-10.5X/\n", t_X);
		printf("v- size < accu /%#-5.10X/\n", t_X), F;
		ft_printf("f- size < accu /%#-5.10X/\n", t_X);
		printf("v- size = accu /%#-10.10X/\n", t_X), F;
		ft_printf("f- size = accu /%#-10.10X/\n", t_X);

		// sur les %d

		// ----------- TEST FLAG PLUS ------------

		printf("\n\nTest on %%d\nTESTS FLAG PLUS\n"), F;
		printf("v- plus tout seul        /%+d/\n", t_d), F;
		ft_printf("f- plus tout seul        /%+d/\n", t_d);
		printf("v- plus avec size        /%+10d/\n", t_d), F;
		ft_printf("f- plus avec size        /%+10d/\n", t_d);
		printf("v- plus avec accu        /%+.5d/\n", t_d), F;
		ft_printf("f- plus avec accu        /%+.5d/\n", t_d);
		printf("v- plus avec size > accu /%+10.5d/\n", t_d), F;
		ft_printf("f- plus avec size > accu /%+10.5d/\n", t_d);
		printf("v- plus avec size < accu /%+5.10d/\n", t_d), F;
		ft_printf("f- plus avec size < accu /%+5.10d/\n", t_d);
		printf("v- plus avec size = accu /%+10.10d/\n", t_d), F;
		ft_printf("f- plus avec size = accu /%+10.10d/\n", t_d);

		// ------------ TEST FLAG ZERO --------------

		printf("\n\nTEST FLAG ZERO\n"), F;
		printf("v- zero tout seul            /%0d/\n", t_d), F;
		ft_printf("f- zero tout seul            /%0d/\n", t_d);
		printf("v- zero avec size            /%010d/\n", t_d), F;
		ft_printf("f- zero avec size            /%010d/\n", t_d);
		printf("v- zero avec accu            /%0.5d/\n", t_d), F;
		ft_printf("f- zero avec accu            /%0.5d/\n", t_d);
		printf("v- zero avec size > accu     /%010.5d/\n", t_d), F;
		ft_printf("f- zero avec size > accu     /%010.5d/\n", t_d);
		printf("v- zero avec size < accu     /%05.10d/\n", t_d), F;
		ft_printf("f- zero avec size < accu     /%05.10d/\n", t_d);
		printf("v- zero avec size = accu     /%010.10d/\n", t_d), F;
		ft_printf("f- zero avec size = accu     /%010.10d/\n", t_d);

		// ------------ TEST FLAG SPACE --------------

		printf("\n\nTEST FLAG SPACE\n"), F;
		printf("v- space tout seul            /% d/\n", t_d), F;
		ft_printf("f- space tout seul            /% d/\n", t_d);
		printf("v- space avec size            /% 10d/\n", t_d), F;
		ft_printf("f- space avec size            /% 10d/\n", t_d);
		printf("v- space avec accu            /% .5d/\n", t_d), F;
		ft_printf("f- space avec accu            /% .5d/\n", t_d);
		printf("v- space avec size > accu     /% 10.5d/\n", t_d), F;
		ft_printf("f- space avec size > accu     /% 10.5d/\n", t_d);
		printf("v- space avec size < accu     /% 5.10d/\n", t_d), F;
		ft_printf("f- space avec size < accu     /% 5.10d/\n", t_d);
		printf("v- space avec size = accu     /% 10.10d/\n", t_d), F;
		ft_printf("f- space avec size = accu     /% 10.10d/\n", t_d);

		// ------------- TEST FLAG MINUS ------------

		printf("\n\nTEST FLAG MINUS\n"), F;
		printf("v- minus tout seul            /%-d/\n", t_d), F;
		ft_printf("f- minus tout seul            /%-d/\n", t_d);
		printf("v- minus avec size            /%-10d/\n", t_d), F;
		ft_printf("f- minus avec size            /%-10d/\n", t_d);
		printf("v- minus avec accu            /%-.5d/\n", t_d), F;
		ft_printf("f- minus avec accu            /%-.5d/\n", t_d);
		printf("v- minus avec size > accu     /%-10.5d/\n", t_d), F;
		ft_printf("f- minus avec size > accu     /%-10.5d/\n", t_d);
		printf("v- minus avec size < accu     /%-5.10d/\n", t_d), F;
		ft_printf("f- minus avec size < accu     /%-5.10d/\n", t_d);
		printf("v- minus avec size = accu     /%-10.10d/\n", t_d), F;
		ft_printf("f- minus avec size = accu     /%-10.10d/\n", t_d);

		// ------------- TEST FLAG PLUS ZERO SPACE MINUS

		printf("\n\nTEST FLAG PLUS ZERO SPACE MINUS\n"), F;
		printf("v- plus et minus seuls            /%+-d/\n", t_d), F;
		ft_printf("f- plus et minus seuls            /%+-d/\n", t_d);
		printf("v- plus et minus avec size        /%+-10d/\n", t_d), F;
		ft_printf("f- plus et minus avec size        /%+-10d/\n", t_d);
		printf("v- plus et minus avec accu        /%+-.5d/\n", t_d), F;
		ft_printf("f- plus et minus avec accu        /%+-.5d/\n", t_d);
		printf("v- plus et minus avec size > accu /%+-10.5d/\n", t_d), F;
		ft_printf("f- plus et minus avec size > accu /%+-10.5d/\n", t_d);
		printf("v- plus et minus avec size < accu /%+-5.10d/\n", t_d), F;
		ft_printf("f- plus et minus avec size < accu /%+-5.10d/\n", t_d);
		printf("v- plus et minus avec size = accu /%+-10.10d/\n", t_d), F;
		ft_printf("f- plus et minus avec size = accu /%+-10.10d/\n", t_d);

		printf("\n2 by 2 ==> PLUS and ZERO\n"), F;
		printf("v- plus et zero seuls            /%+0d/\n", t_d), F;
		ft_printf("f- plus et zero seuls            /%+0d/\n", t_d);
		printf("v- plus et zero avec size        /%+010d/\n", t_d), F;
		ft_printf("f- plus et zero avec size        /%+010d/\n", t_d);
		printf("v- plus et zero avec accu        /%+0.5d/\n", t_d), F;
		ft_printf("f- plus et zero avec accu        /%+0.5d/\n", t_d);
		printf("v- plus et zero avec size > accu /%+010.5d/\n", t_d), F;
		ft_printf("f- plus et zero avec size > accu /%+010.5d/\n", t_d);
		printf("v- plus et zero avec size < accu /%+05.10d/\n", t_d), F;
		ft_printf("f- plus et zero avec size < accu /%+05.10d/\n", t_d);
		printf("v- plus et zero avec size = accu /%+010.10d/\n", t_d), F;
		ft_printf("f- plus et zero avec size = accu /%+010.10d/\n", t_d);

		printf("\n2 by 2 ==> MINUS and SPACE\n"), F;
		printf("v- minus et space seuls            /%- d/\n", t_d), F;
		ft_printf("f- minus et space seuls            /%- d/\n", t_d);
		printf("v- minus et space avec size        /%- 10d/\n", t_d), F;
		ft_printf("f- minus et space avec size        /%- 10d/\n", t_d);
		printf("v- minus et space avec accu        /%- .5d/\n", t_d), F;
		ft_printf("f- minus et space avec accu        /%- .5d/\n", t_d);
		printf("v- minus et space avec size > accu /%- 10.5d/\n", t_d), F;
		ft_printf("f- minus et space avec size > accu /%- 10.5d/\n", t_d);
		printf("v- minus et space avec size < accu /%- 5.10d/\n", t_d), F;
		ft_printf("f- minus et space avec size < accu /%- 5.10d/\n", t_d);
		printf("v- minus et space avec size = accu /%- 10.10d/\n", t_d), F;
		ft_printf("f- minus et space avec size = accu /%- 10.10d/\n", t_d);

		printf("\n2 by 2 ==> SPACE and ZERO \n"), F;
		printf("v- space et zero seuls            /% 0d/\n", t_d), F;
		ft_printf("f- space et zero seuls            /% 0d/\n", t_d);
		printf("v- space et zero avec size        /% 010d/\n", t_d), F;
		ft_printf("f- space et zero avec size        /% 010d/\n", t_d);
		printf("v- space et zero avec accu        /% 0.5d/\n", t_d), F;
		ft_printf("f- space et zero avec accu        /% 0.5d/\n", t_d);
		printf("v- space et zero avec size > accu /% 010.5d/\n", t_d), F;
		ft_printf("f- space et zero avec size > accu /% 010.5d/\n", t_d);
		printf("v- space et zero avec size < accu /% 05.10d/\n", t_d), F;
		ft_printf("f- space et zero avec size < accu /% 05.10d/\n", t_d);
		printf("v- space et zero avec size = accu /% 010.10d/\n", t_d), F;
		ft_printf("f- space et zero avec size = accu /% 010.10d/\n", t_d);

		// test sur les %u

		printf("\n\n TEST DES %%u"), F;
		printf("\n\nTEST SUR ZERO\n"), F;
		printf("v- zero tout seul            /%0u/\n", t_u), F;
		ft_printf("f- zero tout seul            /%0u/\n", t_u);
		printf("v- zero avec size            /%010u/\n", t_u), F;
		ft_printf("f- zero avec size            /%010u/\n", t_u);
		printf("v- zero avec accu            /%0.5u/\n", t_u), F;
		ft_printf("f- zero avec accu            /%0.5u/\n", t_u);
		printf("v- zero avec size > accu     /%010.5u/\n", t_u), F;
		ft_printf("f- zero avec size > accu     /%010.5u/\n", t_u);
		printf("v- zero avec size < accu     /%05.10u/\n", t_u), F;
		ft_printf("f- zero avec size < accu     /%05.10u/\n", t_u);
		printf("v- zero avec size = accu     /%010.10u/\n", t_u), F;
		ft_printf("f- zero avec size = accu     /%010.10u/\n", t_u);

		printf("\nTEST SUR MINUS\n"), F;
		printf("v- minus tout seul            /%-u/\n", t_u), F;
		ft_printf("f- minus tout seul            /%-u/\n", t_u);
		printf("v- minus avec size            /%-10u/\n", t_u), F;
		ft_printf("f- minus avec size            /%-10u/\n", t_u);
		printf("v- minus avec accu            /%-.5u/\n", t_u), F;
		ft_printf("f- minus avec accu            /%-.5u/\n", t_u);
		printf("v- minus avec size > accu     /%-10.5u/\n", t_u), F;
		ft_printf("f- minus avec size > accu     /%-10.5u/\n", t_u);
		printf("v- minus avec size < accu     /%-5.10u/\n", t_u), F;
		ft_printf("f- minus avec size < accu     /%-5.10u/\n", t_u);
		printf("v- minus avec size = accu     /%-10.10u/\n", t_u), F;
		ft_printf("f- minus avec size = accu     /%-10.10u/\n", t_u);


		//  sur les %c

		// ------------- TEST FLAG MINUS ------------

		printf("\n\nTest on %%c\n"), F;
		printf("TEST FLAG MINUS\n"), F;
		printf("v- minus tout seul            /%-c/\n", t_c),F;
		ft_printf("f- minus tout seul            /%-c/\n", t_c);
		printf("v- minus avec size            /%-10c/\n", t_c), F;
		ft_printf("f- minus avec size            /%-10c/\n", t_c);

		// sur les %s

		printf("\n\nTest on %%s\n"), F;

		printf("v- moins /%-s/\n", t_s), F;
		ft_printf("f- moins /%-s/\n", t_s);
		printf("v- size /%20s/\n", t_s), F;
		ft_printf("f- size /%20s/\n", t_s);
		printf("v- accu /%.5s/\n", t_s), F;
		ft_printf("f- accu /%.5s/\n", t_s);
		printf("v- size > accu /%20.5s/\n", t_s), F;
		ft_printf("f- size > accu /%20.5s/\n", t_s);
		printf("v- size < accu /%20.30s/\n", t_s), F;
		ft_printf("f- size < accu /%20.30s/\n", t_s);

		printf("v- moins et size /%-20s/\n", t_s), F;
		ft_printf("f- moins et size /%-20s/\n", t_s);
		printf("v- moins et accu /%.5s/\n", t_s), F;
		ft_printf("f- moins et accu /%.5s/\n", t_s);
		printf("v- moins et size > accu /%-20.5s/\n", t_s), F;
		ft_printf("f- moins et size > accu /%-20.5s/\n", t_s);
		printf("v- moins et size < accu /%-20.30s/\n", t_s), F;
		ft_printf("f- moins et size < accu /%-20.30s/\n", t_s);

		ft_printf("123456789abcdefghijklmnopqrstuvwxyz");

		// RETURNED INT


		pointer_test = "bonjour";

		ft_printf("nombre rendu = |%d|\n", ft_printf("\n\nbonjour je rends un nombre %+d %+-d %10.5d hahahah\n", 42, 43, 44));
		printf("nombre rendu = |%d|\n", printf("\n\nbonjour je rends un nombre %+d %+-d %10.5d hahahah\n", 42, 43, 44)), F;


		ft_printf("%x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x \n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);
		printf("%x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x \n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18), F;
		ft_printf("test normaux, %% voila le %%d ->%d<- et le %%c ->%c<- et le %%s ->%s<- et le %%x ->%x<- et le %%p ->%p<- et le 0 ->%x<-\n", 42, 'A', "Coucou", 1024, pointer_test, 0);
		printf("test normaux, %% voila le %%d ->%d<- et le %%c ->%c<- et le %%s ->%s<- et le %%x ->%x<- et le %%p ->%p<- et le 0 ->%x<-\n", 42, 'A', "Coucou", 1024, pointer_test, 0), F;
		ft_printf("check des hexa sur 4 octets : %x /-/ %x /-/ %x\n", 1024, -1024, 2147483647);
		printf("check des hexa sur 4 octets : %x /-/ %x /-/ %x\n", 1024, -1024, 2147483647), F;
		ft_printf("check des hexa plus dur : %x /-/ %x /-/ %lx /-/ %x\n", 2147483647, -2147483647, 2147483656, -1);
		printf("check des hexa plus dur : %x /-/ %x /-/ %lx /-/ %x\n", 2147483647, -2147483647, 2147483656, -1), F;
	return (0);
}
