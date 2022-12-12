/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_management_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:16:54 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/12 09:57:51 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_node	*ft_find_x_node(t_stack *s, int pos)
{
	t_node	*tmp;

	tmp = s->first;
	while (tmp->dst_idx != pos)
		tmp = tmp->next;
	return (tmp);
}

void	ft_push_x_node(t_stack *a, t_stack *b, int pos)
{
	t_node	*ntp;
	int		size;

	size = a->size;
	tmp = ft_find_x_node(a, pos);
	while (a->size == size)
	{
		if (ntp->index > a->size / 2)
			ft_rrn(a, b, "rra");
		else if (ntp->index != 0)
			ft_rn(a, b, "ra");
		else
			ft_pb(a, b);
		ft_index(a);
	}
}
