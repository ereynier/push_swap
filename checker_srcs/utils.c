/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynier <ereynier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:51:27 by ereynier          #+#    #+#             */
/*   Updated: 2021/03/20 15:06:08 by ereynier         ###   ########lyon.fr   */
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

void ft_free(t_stacks *st)
{
	free(st->a);
	free(st->b);
	ft_error();
}

int ft_strcomp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
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

int		ft_atoi(char *str, t_stacks *st)
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
