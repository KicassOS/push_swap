/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:57:31 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/11 06:17:15 by pszleper         ###   ########.fr       */
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
	t_stack	*stack_a;
	char	**temp;
}	t_program;

void	ft_print_error_exit(void);
void	ft_free_stack(t_stack **a, t_program *program);
void	ft_free_split(char **temp, t_program *program);
int		ft_atoi2(char *str);
char	ft_is_only_whitespace(char *str);
void	ft_stack_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stacklast(t_stack *a);
char	ft_check_duplicates(t_stack *a);
void	ft_exit_program(t_program *prog,char is_error);
void	ft_init_program(t_program *program, t_stack *stack_a);

#endif
