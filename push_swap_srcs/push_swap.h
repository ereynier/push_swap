/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:32:14 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/19 12:07:44 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stacks
{
    int *a;
    int *b;
    int size_a;
    int size_b;
    int size;
}               t_stacks;

int		ft_strlen(char *str);
void	ft_error(void);
int		check_num(char *str);
int		ft_atoi(char* str);
void	ft_free(t_stacks *st);
void	check_dup(t_stacks *st);
int     ft_strcomp(const char *s1, const char *s2);
void    sort_3(t_stacks *st);
int		check_a(t_stacks *st);
void	action(t_stacks *st, char *s);
void	sort(t_stacks *st);
void	pb(t_stacks *st);
void	pa(t_stacks *st);
void	sa(t_stacks *st);
void	sb(t_stacks *st);
void	ss(t_stacks *st);
void	ra(t_stacks *st);
void	ra(t_stacks *st);
void	rb(t_stacks *st);
void	rr(t_stacks *st);
void	rra(t_stacks *st);
void	rrb(t_stacks *st);
void	rrr(t_stacks *st);

#endif