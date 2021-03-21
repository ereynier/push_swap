/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:11 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/21 13:53:42 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_dup(t_stacks *st)
{
	int i;
	int j;

	i = 0;
	while (i < st->size_a)
	{
		j = i + 1;
		while (j < st->size_a)
			if (st->a[i] == st->a[j++])
				ft_free(st);
		i++;
	}
}

void check_just_swap(t_stacks *st)
{
	if (st->size_a >= 2)
	{
		if (st->a[st->size_a - 1] > st->a[st->size_a - 2])
			action(st, "sa");
		if (st->a[0] < st->a[1])
		{
			action(st, "rra");
			action(st, "rra");
			action(st, "sa");
			action(st, "ra");
			action(st, "ra");
		}
	}
}

void sort(t_stacks *st)
{
    while (1)
	{
		if (check_a(st))
			break;
		check_just_swap(st);
		if (st->size_a <= 3)
			sort_3(st);
		if (st->size != 100 && st->size_a > 3)
			sort_5(st);
	}
}

int main(int ac, char **av)
{
    t_stacks st;
	char **lst;
	
	if (ac < 2)
		ft_error();
	lst = ft_split(av[1], ' ');
	if (lst[1])
		use_lst(lst, &st, 0);
	else
		use_lst(av, &st, 1);
	check_dup(&st);
	sort(&st);
	return (0);
}