/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:36:01 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/22 14:48:01 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos_b(t_stacks *st, int i)
{
	if (i > st->size_b / 2)
	{
		i = st->size_b - i;
		while (i-- > 0)
			action(st, "rb");
	}
	else
	{
		while (i-- > 0)
			action(st, "rrb");
	}
}

void	get_num_b(t_stacks *st, int i)
{
	if (i > st->size_b / 2)
	{
		i = st->size_b - i;
		while (i-- > 0)
			action(st, "rb");
	}
	else
	{
		while (i-- >= 0)
			action(st, "rrb");
	}
}

int	pb_100_insert_b(t_stacks *st, int min)
{
	int	j;
	int	i;
	int	m;

	j = 0;
	i = (min + 1) % st->size_b;
	if (st->size_b > 0)
	{
		while (st->b[i] < st->a[st->size_a - 1] && j++ < st->size_b)
			i = (i + 1) % st->size_b;
		get_pos_b(st, i);
	}
	action(st, "pb");
	min = ((min - i) % st->size_b);
	if (min < 0)
		min = st->size_b + min - 1;
	m = min - 1;
	if (m < 0)
		m = st->size_b - 1;
	if (st->size_b > 1 && st->b[min] > st->b[(m) % st->size_b])
		min = (m) % st->size_b;
	return (min);
}

void	pb_100_bis(t_stacks *st, int chunk, int min)
{
	int	n;
	int	i;
	int	m;

	n = 0;
	m = 0;
	while (st->size_a > 0)
	{
		i = 0;
		while (i < st->size_a && st->size_a > 0)
		{
			if (st->a[i] >= min + n * chunk && st->a[i] < min + (n + 1) * chunk)
			{
				get_num(st, i);
				m = pb_100_insert_b(st, m);
				i = 0;
			}
			else if (st->a[st->size_a - 1 - i] >= min + n * chunk
				&& st->a[st->size_a - 1 - i] < min + (n + 1) * chunk)
			{
				get_num(st, st->size_a - 1 - i);
				m = pb_100_insert_b(st, m);
				i = 0;
			}
			else
				i++;
		}
		n++;
		if (n > 13)
			n = 13;
	}
}

void	pb_100(t_stacks *st)
{
	int	min;
	int	max;
	int	i;
	int	chunk;

	i = 0;
	min = st->a[0];
	max = st->a[0];
	while (i < st->size_a)
	{
		if (max < st->a[i])
			max = st->a[i];
		if (min > st->a[i])
			min = st->a[i];
		i++;
	}
	chunk = (max - min) / 13;
	pb_100_bis(st, chunk, min);
}
