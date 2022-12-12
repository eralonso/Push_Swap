/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:39:09 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/10 09:42:59 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b->first)
		return ;
	tmp = a->first;
	if (tmp)
		a->first->prev = b->first;
	else
		a->last = b->first;
	a->first = b->first;
	b->first = b->first->next;
	a->first->next = tmp;
	b->size--;
	a->size++;
	if (b->size)
		b->first->prev = NULL;
	else
		b->last = NULL;
	ft_print_move(a, b, "pa");
	ft_index(a);
	ft_index(b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a->first)
		return ;
	tmp = b->first;
	if (tmp)
		b->first->prev = a->first;
	else
		b->last = a->first;
	b->first = a->first;
	a->first = a->first->next;
	b->first->next = tmp;
	a->size--;
	b->size++;
	if (a->size)
		a->first->prev = NULL;
	else
		a->last = NULL;
	ft_print_move(a, b, "pb");
}

void	ft_sn(t_stack *s, t_stack *o, char *str)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->first->val;
	s->first->val = s->first->next->val;
	s->first->next->val = tmp;
	ft_print_move(s, o, str);
}

void	ft_rn(t_stack *s, t_stack *o, char *str)
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
	ft_print_move(s, o, str);
}

void	ft_rrn(t_stack *s, t_stack *o, char *str)
{
	t_node	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->last;
	s->last = s->last->prev;
	s->last->next = NULL;
	tmp->next = s->first;
	s->first->prev = tmp;
	s->first = tmp;
	tmp->prev = NULL;
	ft_print_move(s, o, str);
}
