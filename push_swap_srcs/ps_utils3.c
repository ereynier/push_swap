/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:29:18 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/23 16:06:37 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stacks *st)
{
	int	i;
	int	min;
	int	j;

	if (check_a(st))
		return ;
	while (st->size_a > 3)
		action(st, "pb");
	sort_3(st);
	min = st->size_a - 1;
	while (st->size_b > 0)
	{
		j = 0;
		i = (min + 1) % st->size_a;
		while (st->a[i] > st->b[st->size_b - 1] && j++ < st->size_a)
			i = (i + 1) % st->size_a;
		get_pos(st, i);
		action(st, "pa");
		min = ((min - i) % st->size_a);
		if (min < 0)
			min = st->size_a + min - 1;
		if (st->a[min] > st->a[(min + 1) % st->size_a])
			min = (min + 1) % st->size_a;
	}
	rotate(st);
}

int	pour_la_norme(t_stacks *st)
{
	int	i;
	int	j;
	int	max;

	j = 0;
	i = 0;
	pb_100(st);
	max = st->b[0];
	while (i > st->size_b)
	{
		if (st->b[i] > max)
		{
			max = st->b[i];
			j = i;
		}
		i++;
	}
	get_num_b(st, j);
	return (st->size_a - 1);
}

void	sort_100(t_stacks *st)
{
	int	min;

	if (check_a(st))
		return ;
	min = pour_la_norme(st);
	(void)min;
	while (st->size_b > 0)
		action(st, "pa");
	rotate(st);
}

void	pb_100_bis2(t_stacks *st, int *i, int *m, int use_i)
{
	if (use_i == 1)
	{
		get_num(st, (*i));
		*m = pb_100_insert_b(st, (*m));
		*i = -1;
	}
	else
	{
		get_num(st, st->size_a - (*i));
		*m = pb_100_insert_b(st, (*m));
		*i = -1;
	}
}
