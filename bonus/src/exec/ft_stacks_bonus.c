/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:34:15 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/23 18:45:39 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

int	ft_init_stacks(t_stack *a, t_stack *b, char **input)
{
	t_node	*first_n;

	a->size = 0;
	first_n = ft_new_node(ft_atoi(input[a->size]));
	if (!first_n)
		return (0);
	a->first = first_n;
	while (input[++(a->size)])
	{
		first_n->next = ft_new_node(ft_atoi(input[a->size]));
		if (!first_n->next)
			return (ft_stack_clear(a));
		first_n->next->prev = first_n;
		first_n = first_n->next;
	}
	a->last = first_n;
	b->first = NULL;
	b->last = NULL;
	b->size = 0;
	return (1);
}

t_node	*ft_new_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->val = num;
	return (new);
}

int	ft_stack_clear(t_stack *s)
{
	t_node	*tmp;

	if (!s)
		return (0);
	while (s->first)
	{
		tmp = s->first->next;
		free(s->first);
		s->first = NULL;
		s->first = tmp;
	}
	return (0);
}
