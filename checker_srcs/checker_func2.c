/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:35:57 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/16 18:53:06 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void rra(t_stacks *st)
{
    int i;
    int tmp;
    int tmp2;

    i = 0;
    while (i < st->size_a && st->size_a >= 2)
    {
        if (i == 0)
        {
            tmp2 = st->a[i];
            st->a[i] = st->a[st->size_a - 1];
        }
        else
        {
            tmp2 = st->a[i];
            st->a[i] = tmp;
        }
        tmp = tmp2;
        i++;
    }
}

void rrb(t_stacks *st)
{
    int i;
    int tmp;
    int tmp2;

    i = 0;
    while (i < st->size_b && st->size_b >= 2)
    {
        if (i == 0)
        {
            tmp2 = st->b[i];
            st->b[i] = st->b[st->size_b - 1];
        }
        else
        {
            tmp2 = st->b[i];
            st->b[i] = tmp;
        }
        tmp = tmp2;
        i++;
    }
}

void rrr(t_stacks *st)
{
    ra(st);
    rb(st);
}
