/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:48:13 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/16 19:24:42 by ereynier         ###   ########lyon.fr   */
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
		ft_free(st);
}

void	checker(t_stacks *st)
{
	char in[2];
	char str[256];
	int i;

	i = 0;
	while (i < 256)
		str[i++] = 0;
	i = 0;
	while (read(0, in, 1) > 0)
	{
		str[i] = in[0];
		if (str[i] == '\n')
		{
			str[i] = 0;
			exec(str, st);
			while(i >= 0)
				str[i--] = 0;
		}
		i++;
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
	checker(&st);
	return (0);
}
