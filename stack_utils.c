/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:37:16 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/15 06:07:43 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  returns last node of stack
*/
t_stack	*ft_stacklast(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

/*
  returns the index(position) of number nbr in a given stack
*/
int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

/*
  this function calculates the correct place of the number nbr_push
  in stack_b and returns it
*/
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_stacklast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->nbr < nbr_push || temp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

/*
  this function calculates the correct place of the number nbr_push
  in stack_a and returns it
*/
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_stacklast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->nbr > nbr_push || temp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}
