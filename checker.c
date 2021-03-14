/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:48:13 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/14 19:07:21 by ereynier         ###   ########lyon.fr   */
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
	else if (ft_strcomp(in, "rb"))
		rb(st);
	else if (ft_strcomp(in, "rr"))
		rr(st);
	else if (ft_strcomp(in, "rra"))
		rra(st);
	else if (ft_strcomp(in, "rrb"))
		rrb(st);
	else if (ft_strcomp(in, "rrr"))
		rrr(st);
	else
		ft_free(st, in);
}

void	checker(t_stacks *st)
{
	char *in;

	in = malloc(4);
	while (in[0] != '\0')
	{
		read(0, in, 4);
		exec(in, st);
	}
}

int	main(int ac, char **av)
{
	t_stacks st;
	int	i;

	i = 1;
	if (ac < 2)
		ft_error();
	while (av[i])
		if (check_num(av[i++]))
			ft_error();
	i = 1;
	st.a = malloc(ac - 1);
	st.b = malloc(ac - 1);
	if (st.a == NULL || st.b == NULL)
		ft_error();
	st.size = ac - 1;
	st.size_a = st.size;
	st.size_b = 0;
	while (av[i])
	{
		st.a[i] = ft_atoi(av[i]);
		i++;
	}
	checker(&st);
	return (0);
}
