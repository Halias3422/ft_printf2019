/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 19:51:31 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 14:13:39 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

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
	long long		nb_int;
	char			*num;
//	char			*tmp;
	long double		nb_float;
	size_t			left_length;
}					t_float;

/*
**		FT_PRINTF.C
*/

int					ft_printf(const char * restrict format, ...);
int					crossing_pourcent(char *format, char **output, int i, va_list va);
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
void				init_data(t_data *data);

/*
**		ADD_CONVERSION.C
*/

char				*add_conversion_output(t_data data, char *output, va_list va);
char				*conversion_type(t_data data, va_list va);

/*
**		CONVERSION_TYPE.C 1 && 2
*/

char				*c_conv(va_list va, t_data data);
char				*s_conv(va_list va, t_data data);
char				*p_conv(va_list va, t_data data);
char				*f_conv(va_list va, t_data data);
char				*d_conv(va_list va, t_data data);
char				*o_conv(va_list va, t_data data);
char				*u_conv(va_list va, t_data data);
char				*x_conv(va_list va, t_data data);
char				*X_conv(va_list va, t_data data);

/*
**		ADD_FLAGS.C
*/

char				*add_flag_to_conv(t_data data, char *arg);
char				*flag_diez(t_data data, char *arg);
char				*flag_minus(t_data data, char *arg);
char				*flag_zero(t_data data, char *arg);

/*
**		HANDLE_FLOAT.C
*/

void				fill_num(t_float *flt);
int					change_round_num(t_float *flt, int i);
char				*round_num(t_float flt);
char				*handle_float(long double nb, t_data data);
int					determ_prec(t_data data);

/*
**		HANDLE_PREC_AND_WIDTH
*/

char				*add_prec_to_string(t_data data, char *arg);
char				*add_prec_to_pointer(t_data data, char *arg);
char				*handle_prec_and_width(t_data data, char *arg);

/*
**		FREE.C
*/

void				free_data(t_data data);

#endif
