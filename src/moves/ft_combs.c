/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:05:25 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/03 13:36:04 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sn(a, b, NULL);
	ft_sn(b, a, NULL);
	if (ft_printf("ss\n") == -1)
	{
		ft_stack_clear(a);
		ft_stack_clear(b);
		ft_exit(1);
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rn(a, b, NULL);
	ft_rn(b, a, NULL);
	if (ft_printf("rr\n") == -1)
	{
		ft_stack_clear(a);
		ft_stack_clear(b);
		ft_exit(1);
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rrn(a, b, NULL);
	ft_rrn(b, a, NULL);
	if (ft_printf("rrr\n") == -1)
	{
		ft_stack_clear(a);
		ft_stack_clear(b);
		ft_exit(1);
	}
}
