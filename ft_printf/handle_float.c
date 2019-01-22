/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_float.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 11:13:53 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 15:15:59 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			determ_prec(t_data data)
{
	if (data.tmp_prec[0] == '\0' && data.prec_dot == 0)
		return (6);
	else if ((data.tmp_prec[0] == '\0' && data.prec_dot == 1) || data.prec == 0)
		return (-1);
	else
		return (data.prec);
}

void		fill_num(t_float *flt)
{
	char	*tmp;
	char	*tmp2;

		flt->nb_int = (long long)flt->nb_float;
		flt->nb_float = flt->nb_float - flt->nb_int;
		flt->nb_float = flt->nb_float * 10;
		if (ft_strlen(flt->num) == flt->left_length)
		{
			tmp = flt->num;
			flt->num = ft_strjoin(flt->num, ".");
			free(tmp);
		}
		tmp = flt->num;
		tmp2 = ft_itoa(flt->nb_int);
		flt->num = ft_strjoin(flt->num, tmp2);
		free(tmp);
		free(tmp2);
}

int			change_round_num(t_float *flt, int i)
{
		flt->num[i] = '0';
		if (flt->num[i - 1] != '.')
			flt->num[--i] += 1;
		else
		{
			i -= 2;
			flt->num[i] += 1;
		}
	return (i);
}

char			*round_num(t_float flt)
{
	int			i;

	i = ft_strlen(flt.num) - 1;
	if (flt.num[i] >= '5')
		i = change_round_num(&flt, i);
	while ((flt.num[i] > '9' && flt.num[i] < '0') || flt.num[i] == ':')
		i = change_round_num(&flt, i);
	flt.num[ft_strlen(flt.num) - 1] = '\0';
	if (flt.num[ft_strlen(flt.num) - 1] == '.')
		flt.num[ft_strlen(flt.num) - 1] = '\0';
	return (flt.num);
}

char			*handle_float(long double nb, t_data data)
{
	t_float		flt;
	int			prec;

	flt.left_length = check_num_length((long long)nb);
	prec = determ_prec(data);
	flt.num = ft_strnew(0);
	flt.nb_int = 0;
	if (nb < 0)
		flt.nb_float = -nb;
	else
		flt.nb_float = nb;
	while (ft_strlen(flt.num) <= (prec + flt.left_length + 1))
		fill_num(&flt);
	flt.num = round_num(flt);
	if (flt.num[0] == '.')
		ft_swap_let_string(flt.num, 0, 1);
	if (nb < 0)
		flt.num = add_char_begin_string(flt.num, "-");
	return (flt.num);
}
