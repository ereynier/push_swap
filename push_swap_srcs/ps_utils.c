/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:30:36 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/21 13:55:56 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_a(t_stacks *st)
{
    int i;
    
    i = st->size_a - 1;
    if (st->size_a == st->size)
    {
        while (i > 0)
        {
            if (st->a[i] > st->a[i - 1])
                return (0);
            i--;
        }
    }
    else
        return (0);
    return (1);
}

void rotate(t_stacks *st)
{
    int i;

    i = 0;
    if (check_a(st))
        return ;
    while (i < st->size_a && st->a[i] > st->a[i + 1])
        i++;
    get_pos(st, i + 1);
}

void get_pos(t_stacks *st, int i)
{
    if (i > st->size_a / 2)
    {
        i = st->size_a - i;
        while (i-- > 0)
            action(st, "ra");
    }
    else
    {
        while (i-- > 0)
            action(st, "rra");
    }
}

void sort_3(t_stacks *st)
{
    if (check_a(st))
        return ;
    if (st->size_a == 2 && st->a[0] < st->a[1])
        action(st, "sa");
    if (st->size_a == 3)
    {
        if (st->a[2] > st->a[1] && st->a[2] < st->a[0])
            action(st, "sa");
        else if (st->a[0] > st->a[1] && st->a[0] < st->a[2])
            action(st, "ra");
        else if (st->a[2] > st->a[0] && st->a[2] < st->a[1])
            action(st, "rra");
        else if (st->a[0] < st->a[1] && st->a[0] > st->a[2])
        {
            action(st, "sa");
            action(st, "ra");
        }
        else if (st->a[1] > st->a[0] && st->a[1] < st->a[2])
        {
            action(st, "sa");
            action(st, "rra");
        }
    }
}

void sort_5(t_stacks *st)
{
    int i;
    int min;
	int j;

    if (check_a(st))
        return ;
    while(st->size_a > 3)
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