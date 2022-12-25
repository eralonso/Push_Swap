/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:39:09 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/23 19:00:40 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

void	ft_pn(t_stack *dst, t_stack *org)
{
	t_node	*tmp;

	if (!org->first)
		return ;
	tmp = dst->first;
	if (tmp)
		tmp->prev = org->first;
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
}

void	ft_sn(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->first;
	s->first = s->first->next;
	tmp->prev = s->first;
	tmp->next = s->first->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	s->first->next = tmp;
	s->first->prev = NULL;
	if (s->size == 2)
	{
		s->last = tmp;
		tmp->next = NULL;
	}
}

void	ft_rn(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->first;
	s->first = s->first->next;
	s->first->prev = NULL;
	tmp->prev = s->last;
	s->last->next = tmp;
	s->last = tmp;
	tmp->next = NULL;
}

void	ft_rrn(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->last;
	s->last = tmp->prev;
	s->last->next = NULL;
	tmp->next = s->first;
	s->first->prev = tmp;
	s->first = tmp;
	tmp->prev = NULL;
}
