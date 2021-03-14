/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:40:00 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/14 17:53:23 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str);
void ft_error(void);
int check_num(char *str);
int ft_atoi(char* str);

#endif