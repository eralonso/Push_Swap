/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_cntl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:06 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/14 19:23:40 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

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

void	ft_print_move(t_stack *a, t_stack *b, char *str)
{
	if (str && ft_printf(1, "%s\n", str) == -1)
		ft_exit(1, a, b);
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

int	ft_semisorted(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!a || !a->first)
		return (0);
	first = ft_find_x_node(a, 0, 's');
	second = ft_find_x_node(a, 1, 's');
	last = ft_find_x_node(a, a->size - 1, 's');
	if (second->index == 0 && ft_issorted(a->first->next, a->size - 2))
		ft_sn(a, b, "sa");
	else if (first->index == a->size - 1 && ft_issorted(a->first, a->size - 2))
		ft_rrn(a, b, "rra");
	else if (last->index == 0 && ft_issorted(a->first->next, a->size - 2))
		ft_rn(a, b, "ra");
	ft_dest_stack_index(a);
	ft_dest_stack_index(b);
	if (ft_issorted(a->first, a->size - 1))
		return (1);
	return (0);
}
