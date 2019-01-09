/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 19:51:31 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 15:25:12 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libftprintf/libft.h"

/*
** STRUCTURE CONTAINING ALL THE POSSIBLE ARGUMENTS OF PRINTF
*/

typedef struct		s_data
{
	char			*flag;
	char			conv;
	int				conv_type;
	char			*tmp_width;
	int				width;
	char			*tmp_prec;
	int				prec;
	char			*length;
}					t_data;



/*
**		FT_PRINTF.C
*/

int					ft_printf(const char * restrict format, ...);
char				*init_output(char *format, char *output);

/*
**		DETERM_DATA.C
*/

char				*determ_data(char *format, char *output, va_list va, int i);
char				determ_conv(t_data *data, char conv, char *format, int i);
char				*add_char_end_string(char *flag, char *format, int i);

/*
**		ADD_CONVERSION.C
*/

char				*add_conversion_output(t_data data, char *output, va_list va);
char				*conversion_type(int conv_type, char *output, va_list va);

/*
**		CONVERSION_TYPE.C
*/

char				*c_conv(char *output, va_list va);

/*
**		FREE.C
*/

void				free_data(t_data data);

#endif
