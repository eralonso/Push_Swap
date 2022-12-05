/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_cntl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:06 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/05 18:29:41 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_exit(int num)
{
	if (num == 1)
		write(2, "Error\n", ft_strlen("Error\n"));
	exit(num);
}

void	ft_print_move(t_stack *a, t_stack *b, char *str)
{
	if (str && ft_printf("%s\n", str) == -1)
	{
		ft_stack_clear(a);
		ft_stack_clear(b);
		ft_exit(1);
	}
}

int	ft_issorted(t_stack *s)
{
	t_node	*tmp;

	if (!s->first)
		return (0);
	tmp = s->first;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
