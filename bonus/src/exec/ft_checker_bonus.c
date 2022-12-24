#include	"checker_bonus.h"

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
	ft_checking(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}

void	ft_checking(t_stack *a, t_stack *b)
{
	char	*str;
	int	c_moves;
	char	*res;

	res = "OK";
	c_moves = 0;
	str = get_next_line(0);
	while (str)
	{
		if (!ft_check_move(str, a, b))
			ft_exit(1, a, b);
		ft_free(&str, 2);
		c_moves++;
		str = get_next_line(0);
	}
	ft_free(&str, 2);
	if (b->size || !ft_issorted(a->first, a->size - 1)
		|| !ft_number_moves(a, c_moves))
		res = "KO";
	if (ft_printf(1, "\033[0;9%im%s\033[0m\n"
		, (res[0] == 'O') + 1, res) == -1)
		ft_exit(1, a, b);
}

int	ft_check_move(char *str, t_stack *a, t_stack *b)
{
	char	**lst_mv;
	char	*moves;

	moves = "sa\n sb\n ss\n ra\n rb\n rr\n pa\n pb\n rra\n rrb\n rrr\n";
	lst_mv = ft_split(moves, ' ');
	if (!lst_mv)
		ft_exit(1, a, b);
	while (*lst_mv)
	{
		if (!ft_strncmp(str, *lst_mv, ft_strlen(str)))
		{
			ft_process_move(*lst_mv, a, b);
			return (1);
		}
		lst_mv++;
	}
	return (0);
}

void	ft_process_move(char *move, t_stack *a, t_stack *b)
{
	if (ft_strlen(move) > 3)
		ft_revrot(move, a, b);
	else if (move[0] == 's')
		ft_swap(move, a, b);
	else if (move[0] == 'r')
		ft_rotate(move, a, b);
	else if (move[0] == 'p')
		ft_push(move, a, b);
}

int	ft_number_moves(t_stack *a, int c_moves)
{
	if (a->size == 2 && c_moves > 1)
		return (0);
	else if (a->size == 3 && c_moves > 3)
		return (0);
	else if (a->size < 6 && c_moves > 12)
		return (0);
	else if (a->size <= 100 && c_moves >= 1500)
		return (0);
	else if (a->size <= 500 && c_moves >= 11500)
		return (0);
	return (1);
}
