/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:24:31 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/21 17:38:15 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_test_sort(t_stack a, t_stack b)
{
	while (a.first)
	{
		ft_printf(1, "a.first->dst_idx = %d\n", a.first->dst_idx);
		a.first = a.first->next;
	}
	while (b.first)
	{
		ft_printf(1, "b.first->dst_idx = %d\n", b.first->dst_idx);
		b.first = b.first->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (!ft_check_input(&av[1]))
		ft_exit(1, NULL, NULL);
	if (ac <= 2)
		ft_exit(0, NULL, NULL);
	if (!ft_init_stacks(&a, &b, &av[1]))
		ft_exit(1, NULL, NULL);
	if (ft_issorted(a.first, a.size - 1))
		ft_exit(0, &a, &b);
	ft_sort(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}

// python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
// python3 pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`
