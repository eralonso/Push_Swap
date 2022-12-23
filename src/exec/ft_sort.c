/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:21:50 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/23 18:01:33 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (ft_issorted(a->first, a->size - 1))
		return ;
	if (a->size == 2)
		ft_sn(a, b, 0);
	else if (a->size == 3)
		ft_sort_three(a, b);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else if (a->size >= 6)
		ft_sort_massive(a, b);
}

void	ft_sort_three(t_stack *a, t_stack *b)
{
	if (ft_issorted(a->first, a->size - 1))
		return ;
	if (a->first->val < a->first->next->val)
		ft_rrn(a, b, 0);
	else if (a->first->val > a->last->val)
		ft_rn(a, b, 0);
	if (!ft_issorted(a->first, a->size - 1)
		&& ft_issorted(b->first, b->size - 1))
		ft_ss(a, b);
	else if (!ft_issorted(a->first, a->size - 1))
		ft_sn(a, b, 0);
	else if (ft_issorted(b->first, b->size - 1))
		ft_sn(b, a, 0);
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
	if (ft_push_x_node(b, a, ntp->dst_stk_idx, 1))
		return ;
	ft_sort_three(a, b);
	ft_pn(a, b);
	ft_semisorted(a, b);
	ft_dest_stack_index(a);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*ntp;

	first = ft_find_x_node(a, 0, 's');
	ntp = ft_find_x_node(a, 1, 's');
	if (ntp->index > first->index && ntp->index > ft_find_x_node
		(a, a->size - 1, 's')->index)
		ntp = ft_find_x_node(a, a->size - 1, 's');
	if (ntp->index < first->index)
	{
		first = ntp;
		ntp = ft_find_x_node(a, 0, 's');
	}
	if (ft_push_x_node(b, a, first->dst_idx, 1) && first->dst_idx == 0)
		return ;
	if (ft_push_x_node(b, a, ntp->dst_stk_idx, 1))
		ft_pn(a, b);
	ft_sort_three(a, b);
	if (b->size)
		ft_pn(a, b);
	if (a->first->dst_stk_idx == a->size - 1)
		ft_rn(a, b, 0);
	ft_pn(a, b);
}
