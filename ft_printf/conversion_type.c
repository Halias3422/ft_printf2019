/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_type.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:52:33 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 13:50:27 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	GETTING CHAR CONV
*/

char				*c_conv(va_list va)
{
	char			*letter;

	letter = ft_strnew(1);
	letter[0] = va_arg(va, int);
	letter[1] = '\0';
	return (letter);
}

char				*s_conv(va_list va)
{
	char			*string;
	char			*join;
	char			*tmp;

	join = ft_strnew(0);
	tmp = join;
	string = va_arg(va, char*);
	join = ft_strjoin(join, string);
	free (tmp);
	return (join);
}

char				*p_conv(va_list va)
{
	void			*address;
	char			*tmp;

	address = va_arg(va, char*);
	address = ft_itoh((long long)address);
	tmp = address;
	address = ft_strjoin("0x", address);
	free(tmp);
	return (address);
}

char		*d_conv(va_list va)
{
	int		nb;

	nb = va_arg(va, int);
	return (ft_itoa(nb));
}

char				*u_conv(va_list va)
{
	long long	nb;

	nb = va_arg(va, long long);
	return (ft_itoa(nb));
}
