/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_massive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:38:55 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/21 14:03:01 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort_massive(t_stack *a, t_stack *b)
{
	int	n_chunks;
	int	s_chunks;
	int	i;
	int	size;

	n_chunks = 10;
	if (a->size >= 6 && a->size <= 30)
		n_chunks = 3;
	else if (a->size > 30 && a->size <= 180)
		n_chunks = 6;
	s_chunks = a->size / n_chunks + (a->size % 4 != 0);
	i = 0;
	size = a->size;
	while (a->first)
	{
		if (a->first->dst_idx >= s_chunks * i
			&& a->first->dst_idx < s_chunks * (i + 1))
			ft_to_b(a, b, s_chunks, i);
		else
			ft_rn(a, b, 0);
		if (a->size + (s_chunks * (i + 1)) == size)
			i++;
	}
	ft_to_a(a, b);
}
		//ft_printf(1, "n_chunks == %d\n", n_chunks);
		//ft_printf(1, "s_chunks == %d\n", s_chunks * i);
		//ft_printf(1, "a->first->dst_idx == %d\n", a->first->dst_idx);

void	ft_to_b(t_stack *a, t_stack *b, int s_chunks, int level)
{
	int	min;
	int	max;

	min = s_chunks * level;
	max = s_chunks * (level + 1);
	ft_pn(b, a);
	if (b->first->dst_idx >= (s_chunks / 2) + min)
	{
		if (a->size > 1 && (a->first->dst_idx < min
				|| a->first->dst_idx >= max))
			ft_rr(a, b);
		else
			ft_rn(b, a, 0);
	}
	//if (b->size > 2 && b->first->dst_idx <= (max / 4) + min)
	//	ft_sn(b, a, 0);
}

void	ft_to_a(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*ntp;
	int		flag;

	while (b->first)
	{
		flag = 0;
		first = ft_find_x_node(b, b->size - 1, 's');
		second = ft_find_x_node(b, b->size - 2, 's');
		ntp = first;
		if ((first->index > b->size / 2 && second->index > first->index)
			|| (first->index < b->size / 2 && second->index < first->index))
		{
			ntp = second;
			flag = 1;
		}
		ft_push_x_node(a, b, ntp->dst_stk_idx, 0);
		if (flag)
		{
			ft_push_x_node(a, b, b->size - 1, 0);
			ft_sn(a, b, 0);
		}
		//ft_test_sort(*a, *b);
	}
}
		/*if (b->first->dst_idx < b->last->dst_idx)
			ft_rrn(b, a, 0);
		if (a->first->dst_idx > a->last->dst_idx)
			ft_rn(a, b, 0);
		if (a->size > 2 && a->first->dst_idx > a->first->next->dst_idx)
			ft_sn(a, b, 0);*/
