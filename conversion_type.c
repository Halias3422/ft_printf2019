/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_type.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:52:33 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 15:47:56 by vde-sain    ###    #+. /#+    ###.fr     */
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

	string = va_arg(va, char*);
	printf("str : /%s/\n", string), fflush(stdout);
	return (string);
}

char		*p_conv(va_list va)
{
	void	*address;

	address = va_arg(va, char*);
	address = ft_itoh((long long)address);
	address = ft_strjoin("0x", address);
	printf("address = %s\n", address), fflush(stdout);
	return(address);
}
/*
char		*f_conv(char *output, va_list va)
{

	return(output);
}

char		*d_conv(char *output, va_list va)
{

	return(output);
}*/
