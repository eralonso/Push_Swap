/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_move_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:12:29 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/28 12:34:51 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

void	ft_swap(char *move, t_stack *a, t_stack *b)
{
	if (ft_strchr("sa", move[1]))
		ft_sn(a);
	else if (ft_strchr("sb", move[1]))
		ft_sn(b);
}

void	ft_rotate(char *move, t_stack *a, t_stack *b)
{
	if (ft_strchr("ra", move[1]))
		ft_rn(a);
	else if (ft_strchr("rb", move[1]))
		ft_rn(b);
}

void	ft_revrot(char *move, t_stack *a, t_stack *b)
{
	if (ft_strchr("ra", move[1]))
		ft_rrn(a);
	else if (ft_strchr("rb", move[1]))
		ft_rrn(b);
}

void	ft_push(char *move, t_stack *a, t_stack *b)
{
	if (move[1] == 'a')
		ft_pn(a, b);
	else
		ft_pn(b, a);
}
