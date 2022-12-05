/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:21:50 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/05 18:31:47 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ft_sn(a, b, "sa");
	else if (a->size == 3)
		ft_sort_three(a, b);
}

void	ft_sort_three(t_stack *a, t_stack *b)
{
	if (a->first->val < a->first->next->val)
		ft_rrn(a, b, "rra");
	else if (a->first->val > a->first->next->next->val)
		ft_rn(a, b, "ra");
	if (!ft_issorted(a))
		ft_sn(a, b, "sa");
}
