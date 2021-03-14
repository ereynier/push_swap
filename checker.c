/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:48:13 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/14 17:55:13 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	i;

	i = 1;
	if (ac < 2)
		ft_error();
	while (av[i])
		if (check_num(av[i++]))
			ft_error();
	i = 1;
	a = malloc(ac - 1);
	b = malloc(ac - 1);
	if (a == NULL || b == NULL)
		ft_error();
	while (av[i])
	{
		a[i] = ft_atoi(av[i]);
		i++;
	}
	return (0);
}
