/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:54:46 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/22 12:28:27 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action(t_stacks *st, char *s)
{
	if (ft_strcomp(s, "sa"))
		sa(st);
	else if (ft_strcomp(s, "sb"))
		sb(st);
	else if (ft_strcomp(s, "ss"))
		ss(st);
	else if (ft_strcomp(s, "rb"))
		rb(st);
	else if (ft_strcomp(s, "ra"))
		ra(st);
	else if (ft_strcomp(s, "rr"))
		rr(st);
	else if (ft_strcomp(s, "rra"))
		rra(st);
	else if (ft_strcomp(s, "rrb"))
		rrb(st);
	else if (ft_strcomp(s, "rrr"))
		rrr(st);
	else if (ft_strcomp(s, "pa"))
		pa(st);
	else if (ft_strcomp(s, "pb"))
		pb(st);
	printf("%s\n", s);
}
