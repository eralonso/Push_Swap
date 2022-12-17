/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_management_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:16:54 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/17 17:54:14 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_node	*ft_find_x_node(t_stack *s, int pos, char idx)
{
	t_node	*tmp;

	tmp = NULL;
	if (!s || !s->first || pos >= s->size)
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

int	ft_push_x_node(t_stack *a, t_stack *b, int pos)
{
	t_node	*ntp;
	int		size;

	size = a->size;
	ntp = ft_find_x_node(a, pos, 's');
	//ft_printf(1, "ntp->val = %i\n", ntp->val);
	while (a->size == size)
	{
		//ft_printf(1, "ntp->val == %i\n", ntp->val);
		//ft_printf(1, "ntp->index == %i\n", ntp->index);
		//ft_printf(1, "ntp->dst_idx == %i\n", ntp->dst_idx);
		//ft_printf(1, "ntp->dst_stk_idx == %i\n", ntp->dst_stk_idx);
		if (ft_semisorted(a, b))
			return (1);
		if (ntp->index == 1 && ntp->next->dst_stk_idx != ntp->dst_stk_idx + 1\
				&& ntp->next->dst_stk_idx != a->size - 1)
			ft_sn(a, b, "sa");
		else if (ntp->index > a->size / 2)
			ft_rrn(a, b, "rra");
		else if (ntp->index != 0)
			ft_rn(a, b, "ra");
		else
			ft_pb(a, b);
		ft_dest_stack_index(a);
	}
	return (0);
}
