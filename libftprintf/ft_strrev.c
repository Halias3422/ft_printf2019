/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strerev.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:14:46 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:23:24 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	*dest;
	int		i;
	size_t	j;

	i = ft_strlen(str) - 1;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	while (j < ft_strlen(str))
		dest[j++] = str[i--];
	dest[j] = '\0';
	return (dest);
}
