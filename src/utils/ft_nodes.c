/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:50:58 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/01 19:20:12 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

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

int	ft_stack_clear(t_stack *a)
{
	t_node	*tmp;

	tmp = a->first;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
		tmp->prev = NULL;
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (0);
}
