/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:05:25 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/21 12:48:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sn(a, b, 1);
	ft_sn(b, a, 1);
	ft_print_move(a, b, "ss");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rn(a, b, 1);
	ft_rn(b, a, 1);
	ft_print_move(a, b, "rr");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rrn(a, b, 1);
	ft_rrn(b, a, 1);
	ft_print_move(a, b, "rrr");
}
