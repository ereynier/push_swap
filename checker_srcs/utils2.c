/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:51:27 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/22 12:26:43 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(char *str, t_stacks *st)
{
	long int	n;
	int			neg;
	int			i;

	i = 0;
	neg = 1;
	n = 0;
	if ((ft_strlen(str) > 0) && (str[0] == '-'))
		neg = -1;
	if (neg == -1)
		i++;
	while (str[i])
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n * neg > 2147483647 || n * neg < -2147483648)
		ft_free(st);
	return ((int)(n * neg));
}

int	z_to_o(int i)
{
	if (i == 0)
		return (1);
	else
		return (0);
}

void	use_lst(char **av, t_stacks *st, int d)
{
	int	i;
	int	ac;

	ac = 0;
	i = d;
	while (av[ac])
		ac++;
	while (av[i])
		if (check_num(av[i++]))
			ft_error();
	st->a = malloc(ac * sizeof(int));
	st->b = malloc(ac * sizeof(int));
	if (st->a == NULL || st->b == NULL)
		ft_error();
	i = ac - d;
	st->size = ac - d;
	st->size_a = st->size;
	st->size_b = 0;
	while (i > 0)
	{
		st->a[ac - d - i] = ft_atoi(av[i - (z_to_o(d))], st);
		i--;
	}
}

int	ft_abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}
