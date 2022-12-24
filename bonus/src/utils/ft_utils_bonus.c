/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_cntl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:06 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/23 19:01:57 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

void	ft_exit(int num, t_stack *a, t_stack *b)
{
	if (num == 1)
		ft_printf(2, "Error\n");
	if (a && a->first)
		ft_stack_clear(a);
	if (b && b->first)
		ft_stack_clear(b);
	exit(num);
}

int	ft_issorted(t_node *n, int size)
{
	t_node	*tmp;

	if (!n)
		return (0);
	tmp = n;
	while (tmp->next && size > 0)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
		size--;
	}
	return (1);
}
