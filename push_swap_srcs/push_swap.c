/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:11 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/19 12:25:46 by ereynier         ###   ########lyon.fr   */
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
    while (i++ < 5)
	{
		if (check_a(st))
			break;
		if (st->size_a <= 3)
			sort_3(st);
	}
}

int main(int ac, char **av)
{
    t_stacks st;
	int	i;

	i = 1;
	if (ac < 2)
		ft_error();
	while (av[i])
		if (check_num(av[i++]))
			ft_error();
	st.a = malloc(ac - 1);
	st.b = malloc(ac - 1);
	if (st.a == NULL || st.b == NULL)
		ft_error();
	i = ac - 1;
	st.size = ac - 1;
	st.size_a = st.size;
	st.size_b = 0;
	while (i > 0)
	{
		st.a[ac - 1 - i] = ft_atoi(av[i]);
		i--;
	}
	check_dup(&st);
	sort(&st);
	return (0);
}