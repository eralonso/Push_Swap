/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:24:31 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/20 20:00:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
/*
void	ft_test_move(t_stack a, t_stack b)
{
	if (a.first)
	{
		ft_printf(1, "a.first->val == %i\n", a.first->val);
		if (a.first->next)
			ft_printf(1, "a.first->next->val == %i\n", a.first->next->val);
		else
			ft_printf(1, "a.first->next == %s\n", a.first->next);
		if (a.first->prev)
			ft_printf(1, "a.first->prev->val == %i\n", a.first->prev->val);
		else
			ft_printf(1, "a.first->prev == %s\n", a.first->prev);
		ft_printf(1, "a.last->val == %i\n", a.last->val);
		ft_printf(1, "a.size == %i\n", a.size);
	}
	if (b.first)
	{
		ft_printf(1, "b.first->val == %i\n", b.first->val);
		if (b.first->next)
			ft_printf(1, "b.first->next->val == %i\n", b.first->next->val);
		else
			ft_printf(1, "b.first->next == %s\n", b.first->next);
		if (b.first->prev)
			ft_printf(1, "b.first->prev->val == %i\n", b.first->prev->val);
		else
			ft_printf(1, "b.first->prev == %s\n", b.first->prev);
		ft_printf(1, "b.last->val == %i\n", b.last->val);
		ft_printf(1, "b.size == %i\n", b.size);
	}
}
*/

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
	/*
	if (ft_issorted(a.first, a.size - 1))
		ft_printf(1, "%10\033[1;92mEstá ordenado\033[0m\n");
	else
		ft_printf(1, "%10\033[1;91mNo está ordenado\033[0m\n");
		*/
	/*
	ft_printf(1, "a.first->val == %i\n", a.first->val);
	ft_printf(1, "a.first->next->val == %i\n", a.first->next->val);
	ft_printf(1, "a.last->val == %i\n", a.last->val);
	ft_printf(1, "\nPrimera prueba: PB\n\n");
	ft_pn(&b, &a);
	ft_test_move(a, b);
	ft_printf(1, "\nSegunda prueba: PB\n\n");
	ft_pn(&b, &a);
	ft_test_move(a, b);
	ft_pn(&b, &a);
	ft_test_move(a, b);
	ft_rn(&a, &b, 0);
	ft_test_move(a, b);
	ft_pn(&b, &a);
	ft_test_move(a, b);
	ft_rn(&b, &a, 0);
	ft_test_move(a, b);
	ft_rr(&b, &a);
	ft_test_move(a, b);
	*/
// python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
// python3 pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`
