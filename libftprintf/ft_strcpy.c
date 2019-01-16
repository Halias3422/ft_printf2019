/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:44:17 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:04:04 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		b;

	b = 0;
	printf("len src = %zu\n", ft_strlen(src)), fflush(stdout);
	while (src[b])
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (dst);
}
