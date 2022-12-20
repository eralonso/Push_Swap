/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:39:09 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/20 19:41:49 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_pn(t_stack *dst, t_stack *org)
{
	t_node	*tmp;
	char	*str;

	if (!org->first)
		return ;
	tmp = dst->first;
	if (tmp)
		org->first->prev = dst->first;
	else
		dst->last = org->first;
	dst->first = org->first;
	org->first = org->first->next;
	dst->first->next = tmp;
	org->size--;
	dst->size++;
	if (org->size)
		org->first->prev = NULL;
	else
		org->last = NULL;
	str = "pb";
	if (dst->id == 'a')
		str = "pa";
	ft_print_move(dst, org, str);
	ft_dest_stack_index(dst);
	ft_dest_stack_index(org);
}

void	ft_sn(t_stack *s, t_stack *o, int rep)
{
	t_node	*tmp;
	char	*str;

	if (s->size < 2)
		return ;
	tmp = s->first;
	s->first = s->first->next;
	tmp->prev = s->first;
	tmp->next = s->first->next;
	tmp->next->prev = tmp;
	s->first->next = tmp;
	s->first->prev = NULL;
	str = "sa";
	if (s->id == 'b')
		str = "sb";
	if (rep)
		str = "NULL";
	ft_print_move(s, o, str);
	ft_dest_stack_index(s);
}

void	ft_rn(t_stack *s, t_stack *o, int rep)
{
	t_node	*tmp;
	char	*str;

	if (s->size < 2)
		return ;
	tmp = s->first;
	s->first = s->first->next;
	s->first->prev = NULL;
	tmp->prev = s->last;
	s->last->next = tmp;
	s->last = tmp;
	tmp->next = NULL;
	str = "ra";
	if (s->id == 'b')
		str = "rb";
	if (rep)
		str = "NULL";
	ft_print_move(s, o, str);
	ft_dest_stack_index(s);
}

void	ft_rrn(t_stack *s, t_stack *o, int rep)
{
	t_node	*tmp;
	char	*str;

	if (s->size < 2)
		return ;
	tmp = s->last;
	s->last = s->last->prev;
	s->last->next = NULL;
	tmp->next = s->first;
	s->first->prev = tmp;
	s->first = tmp;
	tmp->prev = NULL;
	str = "rra";
	if (s->id == 'b')
		str = "rrb";
	if (rep)
		str = "NULL";
	ft_print_move(s, o, str);
	ft_dest_stack_index(s);
}
