/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:11:11 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/14 19:14:37 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../lib/libft/libft.h"
# include	"../lib/ft_printf/inc/ft_printf.h"

typedef struct s_node {
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	int				dst_idx;
	int				dst_stk_idx;
}				t_node;

typedef struct s_stack {
	t_node	*first;
	t_node	*last;
	int		size;
}				t_stack;

//ERR CONTROL
void		ft_exit(int num, t_stack *a, t_stack *b);
void		ft_print_move(t_stack *a, t_stack *b, char *str);

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

//INDEXERS
void		ft_dest_stack_index(t_stack *s);
void		ft_dest_index(t_stack *s);

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

//UTILS
int			ft_issorted(t_node *n, int size);
int			ft_semisorted(t_stack *a, t_stack *b);
t_node		*ft_find_x_node(t_stack *s, int pos, char idx);
int			ft_push_x_node(t_stack *a, t_stack *b, int pos);

//SORTING
void		ft_sort(t_stack *a, t_stack *b);
void		ft_sort_three(t_stack *a, t_stack *b);
void		ft_sort_four(t_stack *a, t_stack *b);
void		ft_sort_five(t_stack *a, t_stack *b);

#endif
