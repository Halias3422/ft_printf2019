/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itooct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 10:36:34 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 10:59:07 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			octlen(long long nb)
{
	size_t		i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 8;
		i++;
	}
	return (i);
}

char			*itooct_base(long long nb, long long i, char *oct
				, char *octbase)
{
	if (nb >= 8)
		oct[i] = octbase[nb % 8];
	else
		oct[i] = octbase[nb];
	return (oct);
}

char			*ft_itooct(long long nb)
{
	long long	i;
	char		*oct;
	char		*octbase;

	i = 0;
	octbase = ft_strdup("01234567");
	if (!(oct = (char*)malloc(sizeof(char) * octlen(nb) + 1)))
		return (NULL);
	if (!nb)
		while (i < 1)
			oct[i++] = '0';
	if (nb < 8 && nb != 0)
	{
		oct[i] = octbase[nb % 8];
		i++;
		nb = nb / 8;
	}
	while (nb != 0)
	{
		oct = itooct_base(nb, i++, oct, octbase);
		nb = nb / 8;
	}
	oct[i] = '\0';
	return (ft_strrev(oct));
}
