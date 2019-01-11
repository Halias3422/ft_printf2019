#include "libft.h"

static size_t	hexlen(long long nb)
{
	size_t	i;

	i = 1;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static char		*itoh_putbase(long long nb, long long i, char *ret, char *base)
{
	if (nb > 15)
		ret[i] = base[nb % 16];
	else
		ret[i] = base[nb];
	return (ret);
}

char			*ft_itoh(long long n)
{
	long long		i;
	char	*hex;
	char	*hbase;

	i = 0;
	hbase = ft_strdup("0123456789abcdef");
	hex = malloc(sizeof(char) * hexlen(n));
	if (!n)
		while (i < 1)
			hex[i++] = '0';
	if (n <= 15 && n != 0)
	{
		hex[i] = hbase[n % 16];
		i++;
		n /= 16;
	}
	while (n != 0)
	{
		hex = itoh_putbase(n, i++, hex, hbase);
		n /= 16;
	}
	hex[i] = '\0';
	return (ft_strrev(hex));
}
