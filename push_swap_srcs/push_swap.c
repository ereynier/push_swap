/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:11 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/25 17:31:20 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_stacks *st, char **lst)
{
	int	i;
	int	j;

	i = 0;
	while (i < st->size_a)
	{
		j = i + 1;
		while (j < st->size_a)
		{
			if (st->a[i] == st->a[j])
			{
				ft_free_lst(lst, 0);
				ft_free(st);
			}
			j++;
		}
		i++;
	}
}

void	check_just_swap2(t_stacks *st)
{
	int	i;
	int	j;

	if (st->a[0] < st->a[1])
	{
		i = 0;
		j = 0;
		while (++i < st->size_a - 1)
			if (st->a[i] < st->a[i + 1])
				j = 1;
		if (j == 0)
		{
			action(st, "rra");
			action(st, "rra");
			action(st, "sa");
			action(st, "ra");
			action(st, "ra");
		}
	}
}

void	check_just_swap(t_stacks *st)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	if (st->size_a > 3)
	{
		if (st->a[st->size_a - 1] > st->a[st->size_a - 2])
		{
			while (++i < st->size_a - 2)
				if (st->a[i] < st->a[i + 1])
					j = 1;
			if (j == 0)
				action(st, "sa");
		}
		check_just_swap2(st);
	}
}

void	sort(t_stacks *st)
{
	while (1)
	{
		if (check_a(st))
			break ;
		check_just_swap(st);
		if (st->size_a <= 3)
			sort_3(st);
		if (st->size <= 30 && st->size_a > 3)
			sort_5(st);
		if (st->size > 30 && st->size_a > 3)
			sort_100(st);
	}
}

int	main(int ac, char **av)
{
	t_stacks	st;
	char		**lst;

	if (ac < 2)
		ft_error();
	lst = ft_split(av[1], ' ');
	if (lst[1])
		use_lst(lst, &st, 0, lst);
	else
		use_lst(av, &st, 1, lst);
	check_dup(&st, lst);
	ft_free_lst(lst, 0);
	sort(&st);
	free(st.a);
	free(st.b);
	return (0);
}
