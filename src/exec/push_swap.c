/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:24:31 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/05 19:37:42 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_test_move(t_stack a, t_stack b)
{
	if (a.first)
	{
		ft_printf("a.first->val == %i\n", a.first->val);
		if (a.first->next)
			ft_printf("a.first->next->val == %i\n", a.first->next->val);
		else
			ft_printf("a.first->next == %s\n", a.first->next);
		if (a.first->prev)
			ft_printf("a.first->prev->val == %i\n", a.first->prev->val);
		else
			ft_printf("a.first->prev == %s\n", a.first->prev);
		ft_printf("a.last->val == %i\n", a.last->val);
		ft_printf("a.size == %i\n", a.size);
	}
	if (b.first)
	{
		ft_printf("b.first->val == %i\n", b.first->val);
		if (b.first->next)
			ft_printf("b.first->next->val == %i\n", b.first->next->val);
		else
			ft_printf("b.first->next == %s\n", b.first->next);
		if (b.first->prev)
			ft_printf("b.first->prev->val == %i\n", b.first->prev->val);
		else
			ft_printf("b.first->prev == %s\n", b.first->prev);
		ft_printf("b.last->val == %i\n", b.last->val);
		ft_printf("b.size == %i\n", b.size);
	}
}

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
	if (ft_issorted(&a))
		ft_exit(0);
	ft_sort(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	ft_test_move(a, b);
	return (0);
}
	/*
	ft_printf("a.first->val == %i\n", a.first->val);
	ft_printf("a.first->next->val == %i\n", a.first->next->val);
	ft_printf("a.last->val == %i\n", a.last->val);
	ft_printf("\nPrimera prueba: PB\n\n");
	ft_pb(&a, &b);
	ft_test_move(a, b);
	ft_printf("\nSegunda prueba: PB\n\n");
	ft_pb(&a, &b);
	ft_test_move(a, b);
	ft_pb(&a, &b);
	ft_test_move(a, b);
	ft_rn(&a, &b, "ra");
	ft_test_move(a, b);
	ft_pb(&a, &b);
	ft_test_move(a, b);
	ft_rn(&b, &a, "rb");
	ft_test_move(a, b);
	ft_rr(&b, &a);
	ft_test_move(a, b);
	*/
