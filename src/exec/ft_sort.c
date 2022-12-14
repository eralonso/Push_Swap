/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:21:50 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/14 19:17:54 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (ft_issorted(a->first, a->size - 1))
		return ;
	if (a->size == 2)
		ft_sn(a, b, "sa");
	else if (a->size == 3)
		ft_sort_three(a, b);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else if (a->size <= 100)
		return ;
}

void	ft_sort_three(t_stack *a, t_stack *b)
{
	if (ft_issorted(a->first, a->size - 1))
		return ;
	if (a->first->val < a->first->next->val)
		ft_rrn(a, b, "rra");
	else if (a->first->val > a->last->val)
		ft_rn(a, b, "ra");
	if (!ft_issorted(a->first, a->size - 1))
		ft_sn(a, b, "sa");
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	t_node	*ntp;

	if (ft_issorted(a->first, a->size - 1))
		return ;
	ntp = ft_find_x_node(a, 0, 's');
	if (ntp->index == 2)
	{
		ntp = ft_find_x_node(a, 1, 's');
		if (ntp->index != 0 && ntp->index != 1)
			ntp = ft_find_x_node(a, a->size - 1, 's');
	}
	if (ft_push_x_node(a, b, ntp->dst_stk_idx))
		return ;
	ft_sort_three(a, b);
	ft_pa(a, b);
	ft_semisorted(a, b);
	ft_dest_stack_index(a);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	if (ft_push_x_node(a, b, 0))
		return ;
	if (ft_push_x_node(a, b, 1))
		ft_pa(a, b);
	else
	{
		if (a->first->val < a->first->next->val)
			ft_rrn(a, b, "rra");
		else if (a->first->val > a->last->val)
			ft_rn(a, b, "ra");
		if (!ft_issorted(a->first, a->size - 1) && ft_issorted(b->first, 1))
			ft_ss(a, b);
		else if (!ft_issorted(a->first, a->size - 1))
			ft_sn(a, b, "sa");
		else if (ft_issorted(b->first, 1))
			ft_sn(b, a, "sb");
		ft_pa(a, b);
		ft_pa(a, b);
		ft_dest_stack_index(a);
		ft_dest_stack_index(b);
	}
}
