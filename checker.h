/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:40:00 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/14 19:07:18 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stacks
{
    int *a;
    int *b;
    int size_a;
    int size_b;
    int size;
}               t_stacks;

int     ft_strlen(char *str);
void    ft_error(void);
int     check_num(char *str);
int     ft_atoi(char* str);
void	checker(t_stacks *st);
void    ft_free(t_stacks *st, char *in);
void	exec(char *in, t_stacks *st);

#endif