/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:57:31 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/15 14:07:36 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PUSH_SWAP_ERROR 42
# define FALSE 0
# define TRUE 1
# include "libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_program
{
	char	split_mallocd;
	char	stack_mallocd;
	t_stack	**stack_a;
	char	**temp;
}	t_program;

t_stack	*ft_stack_new(int number, t_program *program);
void	ft_stack_add_back(t_stack **stack, t_stack *stack_new);

void	ft_free_split(char **temp, t_program *program);
void	ft_free_stack(t_stack **a, t_program *program);
char	ft_is_only_whitespace(char *str);
void	ft_print_error_exit(void);
char	ft_check_duplicates(t_stack *a);
void	ft_exit_program(t_program *prog, char is_error);
void	ft_init_program(t_program *program, t_stack **stack_a);
char	**ft_split_whitespace2(char *s);

t_stack	*ft_stacklast(t_stack *a);
char	ft_stack_is_sorted(t_stack *a);
int		ft_stacksize(t_stack *a);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_find_index(t_stack *a, int nbr);
int		ft_max(t_stack *a);
int		ft_min(t_stack *a);

void	ft_sort_b_until_three(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_last_three(t_stack **stack_a);
void	ft_sort(t_stack **stack_a);
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_sort_b(t_stack **stack_a);

int		ft_rotate_type_ba(t_stack *a, t_stack *b);
int		ft_rotate_type_ab(t_stack *a, t_stack *b);

int		ft_case_rarb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarb(t_stack *a, t_stack *b, int c);
int		ft_case_rarrb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarrb(t_stack *a, t_stack *b, int c);

int		ft_case_rarb_a(t_stack *a, t_stack *b, int j);
int		ft_case_rrarrb_a(t_stack *a, t_stack *b, int j);
int		ft_case_rarrb_a(t_stack *a, t_stack *b, int j);
int		ft_case_rrarb_a(t_stack *a, t_stack *b, int j);
int		ft_atoi2(char *str);
void	ft_check_atoi2(char *str);
long	ft_loop_rest(char *str, long neg, long i);

void	ft_sa(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b, int i);
void	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_ra(t_stack **a, int i);
void	ft_rb(t_stack **b, int i);
void	ft_rr(t_stack **a, t_stack **b, int i);
void	ft_rra(t_stack **a, int i);
void	ft_rrb(t_stack **b, int i);
void	ft_rrr_two(t_stack **b, int i);
void	ft_rrr(t_stack **a, t_stack **b, int i);

int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);

#endif
