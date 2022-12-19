/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_massive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:38:55 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/19 18:39:12 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort_massive(t_stack *a, t_stack *b)
{
	int	n_chunks;
	int	s_chunks;

	if (a->size >= 6 && a->size <= 200)
		n_chunks = 4;
	else if (a->size > 200)
		n_chuks = 9;
	s_chunks = a->size / n_chunks + (a->size % 4 != 0);
}
