#include	"checker_bonus.h"

void	ft_swap(char *move, t_stack *a, t_stack *b)
{
	if (move[1] == 'a')
		ft_sn(a);
	else if (move[1] == 'b')
		ft_sn(b);
	else
		ft_ss(a, b);
}

void	ft_rotate(char *move, t_stack *a, t_stack *b)
{
	if (move[1] == 'a')
		ft_rn(a);
	else if (move[1] == 'b')
		ft_rn(b);
	else
		ft_rr(a, b);
}

void	ft_revrot(char *move, t_stack *a, t_stack *b)
{
	if (move[2] == 'a')
		ft_rrn(a);
	else if (move[2] == 'b')
		ft_rrn(b);
	else
		ft_rrr(a, b);
}

void	ft_push(char *move, t_stack *a, t_stack *b)
{
	if (move[1] == 'a')
		ft_pn(a, b);
	else
		ft_pn(b, a);
}
