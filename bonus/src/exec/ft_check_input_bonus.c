/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:03:46 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/12 11:53:34 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

int	ft_check_input(char **input)
{
	int	i;
	int	tmp;

	i = -1;
	while (input[++i])
	{
		if (!ft_isnum(input[i]) || !ft_isint(input[i]))
			return (0);
		tmp = ft_atoi(input[i]);
		if (!ft_isdup(input, tmp, i))
			return (0);
	}
	return (1);
}

int	ft_isnum(char *input)
{
	int	i;

	i = 0;
	if (ft_strchr("+-", input[0]) && ft_strchr("+-", input[1]))
		return (0);
	if (ft_strchr("+-", input[i]))
		i++;
	if (!input[i])
		return (0);
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isint(char *num)
{
	int			i;
	long long	tmp;

	i = 0;
	if (ft_strchr("+-", num[i]))
		i++;
	while (num[i] && num[i] == '0')
		i++;
	if (!num[i])
		i--;
	if (ft_strlen(&num[i]) > ft_nbr_size(INT_MAX, 10))
		return (0);
	tmp = ft_atoll(num);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (0);
	return (1);
}

long long	ft_atoll(char *str)
{
	long long	neg;
	long long	res;

	neg = 1;
	res = 0;
	while (*str && ft_strchr("\t \n", *str))
		str++;
	if (*str && *str == '-')
		neg = -1;
	if (*str && ft_strchr("+-", *str))
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	return (res * neg);
}

int	ft_isdup(char **input, int num, int index)
{
	int	i;

	i = -1;
	while (++i < index)
	{
		if (num == ft_atoi(input[i]))
			return (0);
	}
	return (1);
}
