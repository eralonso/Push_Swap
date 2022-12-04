/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:11:11 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/04 14:25:55 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../ft_printf/bonus/inc/ft_printf_bonus.h"
# include	<limits.h>

typedef struct s_node {
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack {
	t_node	*first;
	t_node	*last;
	int		size;
}				t_stack;

void		ft_exit(int num);
void		ft_print_move(t_stack *a, t_stack *b, char *str);

int			ft_check_input(char **input);
int			ft_isnum(char *input);
int			ft_isint(char *num);
long long	ft_atoll(char *str);
int			ft_isdup(char **input, int num, int index);

int			ft_init_stacks(t_stack *a, t_stack *b, char **input);
t_node		*ft_new_node(int num);
int			ft_stack_clear(t_stack *a);

//MOVEMENTS
void		ft_sn(t_stack *s, t_stack *o, char *str);
void		ft_rn(t_stack *s, t_stack *o, char *str);
void		ft_rrn(t_stack *s, t_stack *o, char *str);

void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);

////COMBS
void		ft_ss(t_stack *a, t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);

#endif
