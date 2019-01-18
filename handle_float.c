/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_float.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 11:13:53 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 18:47:41 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				determ_prec(t_data data)
{
	if (ft_strlen(data.tmp_prec) == 0 && data.prec_dot == 0)
		return (6);
	else if ((ft_strlen(data.tmp_prec) == 0 && data.prec_dot == 1) || data.prec == 0)
		return (-1);
	else
		return (data.prec);
}

size_t			check_left_num_length(int nb)
{
	size_t		length;

	length = 0;
	while (nb >= 1 || nb <= -1)
	{
		nb = nb / 10;
		length++;
	}
	if (length == 0)
		return (1);
	return (length);
}

char			*join_num(char *join1, char *join2)
{
	char		*str;

	str = ft_strjoin(join1, join2);
	if (ft_strcmp(join1, "-") != 0 && ft_strcmp(join1, "0") != 0)
		free(join1);
	if (ft_strcmp(join2, ".") != 0 && ft_strcmp(join2, "0") != 0)
		free(join2);
	return (str);
}

char			*handle_float(double nb, t_data data)
{
	t_float		flt;
	int			prec;

	flt.left_length = check_left_num_length((int)nb);
	prec = determ_prec(data);
	flt.num = ft_strnew(0);
	flt.nb_int = 0;
	if (nb < 0)
		flt.nb_float = -nb;
	else
		flt.nb_float = nb;
	while (ft_strlen(flt.num) <= (prec + flt.left_length))
	{
		flt.nb_int = flt.nb_float;
		flt.nb_float = flt.nb_float - flt.nb_int;
		flt.nb_float = flt.nb_float * 10;
		if (ft_strlen(flt.num) == flt.left_length)
			flt.num = join_num(flt.num, ".");
		flt.num = join_num(flt.num, ft_itoa(flt.nb_int));
	}
	if (flt.num[0] == '.')
		ft_swap_let_string(flt.num, 0, 1);
	if (nb < 0)
		flt.num = join_num("-", flt.num);
	return (flt.num);
}
