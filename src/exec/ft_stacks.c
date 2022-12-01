/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:34:15 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/01 19:22:08 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_init_stacks(t_stack *a, t_stack *b, char **input)
{
	int		i;
	t_node	*first_n;
	t_node	*tmp;

	i = 0;
	first_n = ft_new_node(ft_atoi(input[i]));
	if (!first_n)
		return (0);
	a->first = first_n;
	a->size = 1;
	tmp = first_n;
	while (input[++i])
	{
		tmp->next = ft_new_node(ft_atoi(input[i]));
		if (!tmp->next)
			return (ft_stack_clear(a));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		(a->size)++;
	}
	b->first = NULL;
	b->last = NULL;
	b->size = 0;
	return (1);
}
