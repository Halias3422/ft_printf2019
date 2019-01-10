/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_type.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:52:33 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 11:23:33 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	GETTING CHAR CONV
*/

char		*c_conv(va_list va)
{
	char	*letter;

	letter = ft_strnew(1);
	letter[0] = va_arg(va, int);
	letter[1] = '\0';
	return (letter);
}

char		*s_conv(va_list va)
{
	char	*string;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char*)va);
	if (!(string = (char*)malloc(sizeof(char) * len + 1)))
		exit (-1);
	string = (char*)va;
	return (string);
}

/*char		*p_conv(char *output, va_list va)
{

	return(output);
}

char		*f_conv(char *output, va_list va)
{

	return(output);
}

char		*d_conv(char *output, va_list va)
{

	return(output);
}*/
