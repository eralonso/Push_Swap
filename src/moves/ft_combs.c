/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:05:25 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/07 18:30:53 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sn(a, b, NULL);
	ft_sn(b, a, NULL);
	ft_print_move(a, b, "ss");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rn(a, b, NULL);
	ft_rn(b, a, NULL);
	ft_print_move(a, b, "rr");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rrn(a, b, NULL);
	ft_rrn(b, a, NULL);
	ft_print_move(a, b, "rrr");
}
