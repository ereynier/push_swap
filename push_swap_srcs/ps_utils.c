/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:30:36 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/20 15:01:18 by ereynier         ###   ########lyon.fr   */
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
    if (st->size_a == 2 && st->a[0] < st->b[1])
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

    while(st->size_a > 3)
        action(st, "pb");
    sort_3(st);
    while (st->size_b > 0)
    {
        i = 0;
        if (st->a[0] > st->a[st->size_a - 1])
        {
            while (i < st->size_a)
            {
                 if (st->b[st->size_b - 1] > st->a[i])
                    break;
                i++;
            }
            get_pos(st, i);
            action(st, "pa");
        }
        else
        {
            while(i < st->size_a)
            {
                if (i < st->size_a - 1 && st->b[st->size_b] > st->a[i] && st->a[i] > st->a[i + 1])
                    while (i < st->size_a - 1 && st->a[i] > st->a[i + 1])
                        i++;
                else if (i > 0 && st->b[st->size_b - 1] < st->a[i] && st->a[i] > st->a[i - 1])
                    break ;
                else if (st->b[st->size_b - 1] > st->a[i])
                    break ;
                i++;
            }
            get_pos(st, i);
            action(st, "pa");
        }
    }
    rotate(st);
}