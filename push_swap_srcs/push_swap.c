/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:11 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/20 20:23:54 by ereynier         ###   ########lyon.fr   */
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

void sort(t_stacks *st)
{
	int i = 0;
    while (i++ < 1)
	{
		if (check_a(st))
			break;
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