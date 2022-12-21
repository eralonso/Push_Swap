/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_management_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:16:54 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/21 13:29:36 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_node	*ft_find_x_node(t_stack *s, int pos, char idx)
{
	t_node	*tmp;

	tmp = NULL;
	if (!s || !s->first || pos >= s->size || pos < 0)
		return (NULL);
	tmp = s->first;
	if (idx == 'g')
		while (tmp->dst_idx != pos)
			tmp = tmp->next;
	else if (idx == 's')
		while (tmp->dst_stk_idx != pos)
			tmp = tmp->next;
	return (tmp);
}

int	ft_push_x_node(t_stack *dst, t_stack *org, int pos, int sort)
{
	t_node	*ntp;
	int		size;

	size = org->size;
	ntp = ft_find_x_node(org, pos, 's');
	while (org->size == size)
	{
		if (sort && ft_semisorted(org, dst))
			return (1);
		if (sort && ntp->index == 1 && ntp->next->dst_stk_idx
			!= ntp->dst_stk_idx + 1
			&& ntp->next->dst_stk_idx != org->size - 1)
			ft_sn(org, dst, 0);
		else if (ntp->index > size / 2)
			ft_rrn(org, dst, 0);
		else if (ntp->index != 0)
			ft_rn(org, dst, 0);
		else
			ft_pn(dst, org);
		ft_dest_stack_index(org);
	}
	return (0);
}
