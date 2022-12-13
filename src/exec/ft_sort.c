/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:21:50 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/13 13:47:15 by eralonso         ###   ########.fr       */
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
	else if (a->first->val > a->first->next->next->val)
		ft_rn(a, b, "ra");
	if (!ft_issorted(a->first, a->size - 1))
		ft_sn(a, b, "sa");
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	t_node	*ntp;

	if (ft_issorted(a->first, a->size - 1))
		return ;
	ntp = ft_find_x_node(a, 0);
	if (ntp->index == 2)
	{
		ntp = ft_find_x_node(a, 1);
		if (ntp->index != 0 && ntp->index != 1)
			ntp = ft_find_x_node(a, a->size - 1);
	}
	if (ft_push_x_node(a, b, ntp->dst_idx))
		return ;
	ft_sort_three(a, b);
	ft_pa(a, b);
	if (a->first->dst_idx == a->size - 1)
		ft_rn(a, b, "ra");
	else if (a->first->dst_idx == 1)
		ft_sn(a, b, "sa");
	ft_index(a);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	(void) a;
	(void) b;
}
