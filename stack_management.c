/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:33:23 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/11 06:18:10 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Adds a new number (stack_new) to the back of the stack
*/
void	ft_stack_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stacklast(*stack))->next = stack_new;
}

int	ft_stacksize(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stack_new(int number, t_program *program)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		ft_exit_program(program, TRUE);
	program->stack_mallocd = TRUE;
	new->nbr = number;
	new->next = NULL;
	return (new);
}
