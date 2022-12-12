/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:21:50 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/12 10:06:48 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (ft_issorted(a))
		return ;
	if (a->size == 2)
		ft_sn(a, b, "sa");
	else if (a->size == 3)
		ft_sort_three(a, b);
	else if (a->size == 4)
		ft_sort_three(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else if (a->size <= 100)
		return ;
}

void	ft_sort_three(t_stack *a, t_stack *b)
{
	if (ft_issorted(a))
		return ;
	if (a->first->val < a->first->next->val)
		ft_rrn(a, b, "rra");
	else if (a->first->val > a->first->next->next->val)
		ft_rn(a, b, "ra");
	if (!ft_issorted(a))
		ft_sn(a, b, "sa");
}

void	ft_sort_four(t_stack *a, t_stack *b)
{

	if (ft_issorted(a))
		return ;
	if ((ft_find_x_node(a, 0))->index != 2)
		tmp = ft_find_x_node(a, a->size - 1);
	ft_push_x_node();
}

void	ft_sort_five(t_stack *a, t_stack *b)
{

}
