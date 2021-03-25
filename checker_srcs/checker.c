/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:48:13 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/25 17:30:34 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec(char *in, t_stacks *st)
{
	if (ft_strcomp(in, "sa"))
		sa(st);
	else if (ft_strcomp(in, "sb"))
		sb(st);
	else if (ft_strcomp(in, "ss"))
		ss(st);
	else if (ft_strcomp(in, "pa"))
		pa(st);
	else if (ft_strcomp(in, "pb"))
		pb(st);
	else if (ft_strcomp(in, "pa"))
		pa(st);
	else if (ft_strcomp(in, "ra"))
		ra(st);
	else
		exec2(in, st);
}

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

void	check_sort(t_stacks *st)
{
	int	i;

	i = 0;
	if (st->size_a == st->size && st->size_b == 0)
	{
		while (i < st->size_a - 1)
		{
			if (st->a[i] < st->a[i + 1])
				ko_ok(st, "KO\n");
			i++;
		}
		ko_ok(st, "OK\n");
		return ;
	}
	ko_ok(st, "KO\n");
}

void	checker(t_stacks *st)
{
	char	in[2];
	char	str[256];
	int		i;

	i = 0;
	while (i < 256)
		str[i++] = 0;
	i = 0;
	while (read(0, in, 1) > 0)
	{
		str[i] = in[0];
		if (str[i] == '\n' || i > 250)
		{
			str[i] = 0;
			exec(str, st);
			while (i >= 0)
				str[i--] = 0;
		}
		i++;
	}
	check_sort(st);
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
	checker(&st);
	return (0);
}
