/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 19:51:31 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 17:45:40 by vde-sain    ###    #+. /#+    ###.fr     */
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
	int				prec_dot;
	char			*tmp_prec;
	int				prec;
	char			*length;
}					t_data;

typedef struct		s_length
{
	char			*flags;
	char			*nb;
	char			*length;
	char			*conv;
}					t_length;

typedef struct		s_float
{
	int				nb_int;
	char			*num;
//	char			*tmp;
	double			nb_float;
	size_t			left_length;
}					t_float;

/*
**		FT_PRINTF.C
*/

int					ft_printf(const char *restrict format, ...);
char				*fill_string_output(char *format, char *output, int i);
int					is_contained_in(char *format, char *compare, int i);
int					count_all_datas(char *format, int i);

/*
**		DETERM_DATA.C
*/

char				*determ_data(char *format, char *output, va_list va, int i);
char				determ_conv(t_data *data, char conv, char *format, int i);
char				*add_char_end_string(char *dest, char *lett, int i);
char				*add_char_begin_string(char *dest, char *lett);

/*
**		ADD_CONVERSION.C
*/

char				*add_conversion_output(t_data data, char *output, va_list va);
char				*conversion_type(int conv_type, va_list va);

/*
**		CONVERSION_TYPE.C 1 && 2
*/

char				*c_conv(va_list va);
char				*s_conv(va_list va);
char				*p_conv(va_list va);
char				*f_conv(va_list va, t_data data);
char				*d_conv(va_list va);
char				*o_conv(va_list va);
char				*u_conv(va_list va);
char				*x_conv(va_list va);
char				*X_conv(va_list va);

/*
**		ADD_FLAGS.C
*/

char				*add_flag_to_conv(t_data data, char *arg);
char				*flag_diez(t_data data, char *arg);
char				*flag_minus(t_data data, char *arg);

/*
**		HANDLE_FLOAT.C
*/

char				*handle_float(double nb, t_data data);
size_t				check_left_num_length(int nb);
char				*join_num(char *join1, char *join2);
int					determ_prec(t_data data);

/*
**		FREE.C
*/

void				free_data(t_data data);

#endif
