/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:49:12 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/16 18:51:10 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void sa(t_stacks *st)
{
    int tmp;
    
    if (st->size_a >= 2)
    {
        tmp = st->a[st->size_a - 1];
        st->a[st->size_a - 1] = st->a[st->size_a - 2];
        st->a[st->size_a - 2] = tmp;
    }
}

void sb(t_stacks *st)
{
    int tmp;
    
    if (st->size_b >= 2)
    {
        tmp = st->b[st->size_b - 1];
        st->b[st->size_b - 1] = st->b[st->size_b - 2];
        st->b[st->size_b - 2] = tmp;
    }
}

void ss(t_stacks *st)
{
    sa(st);
    sb(st);
}

void pa(t_stacks *st)
{
    if (st->size_b >= 1)
    {
        st->a[st->size_a] = st->b[st->size_b - 1];
        st->size_b--;
        st->size_a++;
    }
}

void pb(t_stacks *st)
{
    if (st->size_a >= 1)
    {
        st->b[st->size_b] = st->a[st->size_a - 1];
        st->size_a--;
        st->size_b++;
    }
}