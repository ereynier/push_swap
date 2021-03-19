/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:30:36 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/19 12:20:48 by ereynier         ###   ########lyon.fr   */
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

void sort_3(t_stacks *st)
{
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