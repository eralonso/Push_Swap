/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_massive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:38:55 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/23 18:47:02 by eralonso         ###   ########.fr       */
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
		while (a->first && !(a->first->dst_idx >= s_chunks * i
				&& a->first->dst_idx < s_chunks * (i + 1)))
			ft_rn(a, b, 0);
		ft_to_b(a, b, s_chunks, i);
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
	t_node	*big;
	t_node	*sbig;
	t_node	*tbig;
	int		flag;

	while (b->size > 2)
	{
		flag = 1;
		big = ft_find_x_node(b, b->size - 1, 's');
		sbig = ft_find_x_node(b, b->size - 2, 's');
		tbig = ft_find_x_node(b, b->size - 3, 's');
		ft_calc_mtp(big, b->size);
		ft_calc_mtp(sbig, b->size);
		ft_calc_mtp(tbig, b->size);
		if (sbig->mtp < big->mtp && sbig->mtp <= tbig->mtp)
			flag = 2;
		else if (tbig->mtp < big->mtp && tbig->mtp <= sbig->mtp)
			flag = 3;
		ft_push_x_node(a, b, b->size - flag, 0);
		ft_push_optim(a, b, flag);
	}
	while (b->size)
		ft_push_x_node(a, b, b->size - 1, 0);
}

void	ft_push_optim(t_stack *a, t_stack *b, int flag)
{
	t_node	*big;
	t_node	*sbig;

	big = ft_find_x_node(b, b->size - 1, 's');
	sbig = ft_find_x_node(b, b->size - 2, 's');
	ft_calc_mtp(big, b->size);
	ft_calc_mtp(sbig, b->size);
	if (flag == 3)
		ft_rn(a, b, 0);
	ft_push_x_node(a, b, (b->size - 1) - (big->mtp > sbig->mtp), 0);
	if (flag == 2 && big->mtp <= sbig->mtp)
		ft_sn(a, b, 0);
	else if (flag == 2 && big->mtp > sbig->mtp)
		ft_rn(a, b, 0);
	ft_push_x_node(a, b, b->size - 1, 0);
	if (big->mtp > sbig->mtp)
		ft_sn(a, b, 0);
	if ((flag == 2 && big->mtp > sbig->mtp) || flag == 3)
		ft_rrn(a, b, 0);
}
