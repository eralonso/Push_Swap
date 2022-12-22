/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_massive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:38:55 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/22 14:45:06 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort_massive(t_stack *a, t_stack *b)
{
	int	n_chunks;
	int	s_chunks;
	int	i;
	int	size;

	n_chunks = 8;
	if (a->size >= 6 && a->size <= 20)
		n_chunks = 2;
	else if (a->size > 20 && a->size <= 150)
		n_chunks = 4;
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

void	ft_to_b(t_stack *a, t_stack *b, int s_chunks, int level)
{
	int	min;
	int	max;

	min = s_chunks * level;
	max = s_chunks * (level + 1);
	ft_pn(b, a);
	if (b->first->dst_idx <= (s_chunks / 2) + min)
	{
		if (a->size > 1 && (a->first->dst_idx < min
				|| a->first->dst_idx >= max))
			ft_rr(a, b);
		else
			ft_rn(b, a, 0);
	}
}

void	ft_to_a(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*ntp;
	int		flag;

	while (b->first)
	{
		if (b->size > 2)
			flag = ft_optimizer(a, b);
		if (flag)
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
			flag = 1;
		}
	}
}

void	ft_calc_mtp(t_node *node, int size)
{
	if (node->index > size)
		node->mtp = size - node->index;
	else
		node->mtp = node->index;
}

int	ft_optimizer(t_stack *a, t_stack *b)
{
	t_node	*big;
	t_node	*sbig;
	t_node	*tbig;
	int		flag;

	big = ft_find_x_node(b, b->size - 1, 's');
	sbig = ft_find_x_node(b, b->size - 2, 's');
	tbig = ft_find_x_node(b, b->size - 3, 's');
	ft_calc_mtp(big, b->size);
	ft_calc_mtp(sbig, b->size);
	ft_calc_mtp(tbig, b->size);
	flag = 0;
	if (big->mtp - 3 < sbig->mtp && big->mtp - 3 < tbig->mtp)
		flag = 1;
	else if (sbig->mtp < big->mtp + 3 && sbig->mtp < tbig->mtp)
		flag = 2;
	else if (tbig->mtp < big->mtp + 3 && tbig->mtp < sbig->mtp)
		flag = 3;
	if (flag != 0)
		ft_push_optim(a, b, ft_find_x_node(b, b->size - flag, 's'), flag);
	return (flag);
}

void	ft_push_optim(t_stack *a, t_stack *b, t_node *ntp, int flag)
{
	t_node	*big;
	t_node	*sbig;
	t_node	*tbig;

	big = ft_find_x_node(b, b->size - 1, 's');
	sbig = ft_find_x_node(b, b->size - 2, 's');
	tbig = ft_find_x_node(b, b->size - 3, 's');
	ft_push_x_node(a, b, ntp->dst_stk_idx, 0);
	if (flag == 1)
	{
		ft_calc_mtp(sbig, b->size);
		ft_calc_mtp(tbig, b->size);
		if (sbig->mtp < tbig->mtp)
		{
			ft_push_x_node(a, b, sbig->dst_stk_idx, 0);
			ft_push_x_node(a, b, tbig->dst_stk_idx, 0);
		}
		else
		{
			ft_push_x_node(a, b, tbig->dst_stk_idx, 0);
			ft_push_x_node(a, b, sbig->dst_stk_idx, 0);
			ft_sn(a, b, 0);
		}
	}
	if (flag == 2)
	{
		ft_calc_mtp(big, b->size);
		ft_calc_mtp(tbig, b->size);
		if (big->mtp < tbig->mtp)
		{
			ft_push_x_node(a, b, big->dst_stk_idx, 0);
			ft_sn(a, b, 0);
			ft_push_x_node(a, b, tbig->dst_stk_idx, 0);
		}
		else
		{
			ft_push_x_node(a, b, tbig->dst_stk_idx, 0);
			ft_rn(a, b, 0);
			ft_push_x_node(a, b, big->dst_stk_idx, 0);
			ft_sn(a, b, 0);
			ft_rrn(a, b, 0);
		}
	}
	if (flag == 3)
	{
		ft_calc_mtp(big, b->size);
		ft_calc_mtp(sbig, b->size);
		ft_rn(a, b, 0);
		if (big->mtp < sbig->mtp)
		{
			ft_push_x_node(a, b, big->dst_stk_idx, 0);
			ft_push_x_node(a, b, sbig->dst_stk_idx, 0);
		}
		else
		{
			ft_push_x_node(a, b, sbig->dst_stk_idx, 0);
			ft_push_x_node(a, b, big->dst_stk_idx, 0);
			ft_sn(a, b, 0);
		}
		ft_rrn(a, b, 0);
	}
}
