/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:51:27 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/14 19:06:54 by ereynier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

void ft_free(t_stacks *st, char *in)
{
	if (st->a != NULL)
		free(st->a);
	if (st->b != NULL)
		free(st->b);
	if (in != NULL)
		free(in);
	ft_error();
}

int		check_num(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) > 0)
	{
		if (str[0] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i])
			return (1);
	}
	return (0);
}

int		ft_atoi(char *str)
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
	return ((int)(n * neg));
}
