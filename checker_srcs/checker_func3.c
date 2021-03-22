/* ************************************************************************** */
/*																		    */
/*                                                        :::      ::::::::   */
/*   checker_fun3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:28:24 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/22 12:22:47 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stacks *st)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = st->size_a - 1;
	while (i >= 0 && st->size_a >= 2)
	{
		if (i == st->size_a - 1)
		{
			tmp2 = st->a[st->size_a - 1];
			st->a[st->size_a - 1] = st->a[0];
		}
		else
		{
			tmp2 = st->a[i];
			st->a[i] = tmp;
		}
		tmp = tmp2;
		i--;
	}
}

void	rrb(t_stacks *st)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = st->size_b - 1;
	while (i >= 0 && st->size_b >= 2)
	{
		if (i == st->size_b - 1)
		{
			tmp2 = st->b[st->size_b - 1];
			st->b[st->size_b - 1] = st->b[0];
		}
		else
		{
			tmp2 = st->b[i];
			st->b[i] = tmp;
		}
		tmp = tmp2;
		i--;
	}
}

void	rrr(t_stacks *st)
{
	rra(st);
	rrb(st);
}

void	ko_ok(t_stacks *st, char *s)
{
	write(2, s, ft_strlen(s));
	free(st->a);
	free(st->b);
	exit(1);
}

void	exec2(char *in, t_stacks *st)
{
	if (ft_strcomp(in, "rb"))
		rb(st);
	else if (ft_strcomp(in, "rr"))
		rr(st);
	else if (ft_strcomp(in, "rra"))
		rra(st);
	else if (ft_strcomp(in, "rrb"))
		rrb(st);
	else if (ft_strcomp(in, "rrr"))
		rrr(st);
	else
		ft_free(st);
}
