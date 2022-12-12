/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_management_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:16:54 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/12 11:03:08 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_node	*ft_find_x_node(t_stack *s, int pos)
{
	t_node	*tmp;

	if (!s || !s->first || pos >= s->size)
		return (NULL);
	tmp = s->first;
	while (tmp->dst_idx != pos)
		tmp = tmp->next;
	return (tmp);
}

int	ft_push_x_node(t_stack *a, t_stack *b, int pos)
{
	t_node	*ntp;
	int		size;

	size = a->size;
	ntp = ft_find_x_node(a, pos);
	while (a->size == size)
	{
		if (ntp->index > a->size / 2)
			ft_rrn(a, b, "rra");
		else if (ntp->index != 0)
			ft_rn(a, b, "ra");
		else
		{
			if (ft_issorted(a))
				return (1);
			ft_pb(a, b);
		}
		ft_index(a);
	}
	return (0);
}
