/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:55 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/22 16:55:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include	"../../lib/libft/libft.h"
# include	"../../lib/ft_printf/inc/ft_printf.h"

typedef struct s_node {
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_stack {
	t_node	*first;
	t_node	*last;
	int		size;
}		t_stack;

//ERR CONTROL
void		ft_exit(int num, t_stack *a, t_stack *b);

//UTILS
int			ft_issorted(t_node *n, int size);

//CHECK INPUT
int			ft_check_input(char **input);
int			ft_isnum(char *input);
int			ft_isint(char *num);
long long	ft_atoll(char *str);
int			ft_isdup(char **input, int num, int index);

//STACKS AND NODE
int			ft_init_stacks(t_stack *a, t_stack *b, char **input);
t_node		*ft_new_node(int num);
int			ft_stack_clear(t_stack *a);

//MOVEMENTS
void		ft_sn(t_stack *s);
void		ft_rn(t_stack *s);
void		ft_rrn(t_stack *s);
void		ft_pn(t_stack *a, t_stack *b);

////COMBS
void		ft_ss(t_stack *a, t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);

//MOVE CHOOSER
void		ft_swap(char *move, t_stack *a, t_stack *b);
void		ft_rotate(char *move, t_stack *a, t_stack *b);
void		ft_revrot(char *move, t_stack *a, t_stack *b);
void		ft_push(char *move, t_stack *a, t_stack *b);

//CHECK MOVES
void		ft_checking(t_stack *a, t_stack *b);
int			ft_check_move(char *str, t_stack *a, t_stack *b);
void		ft_process_move(char *str, t_stack *a, t_stack *b);
int			ft_number_moves(t_stack *a, int c_moves);

#endif
