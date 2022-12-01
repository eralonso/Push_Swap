/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:24:31 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/01 19:22:20 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (!ft_check_input(&av[1]))
		ft_exit(1);
	if (ac <= 2)
		ft_exit(0);
	if (!ft_init_stacks(&a, &b, &av[1]))
		ft_exit(1);
	return (0);
}
