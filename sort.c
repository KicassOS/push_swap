/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:37:01 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/15 06:00:04 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  This function pushes elements from a to b until 3 elements are left in a
  Makes sure that b is sorted while pushing
  Calls ft_sort_three function to sort remaining elements in a
*/
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stacksize(*stack_a) > 3 && !ft_stack_is_sorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_stacksize(*stack_a) > 3 && !ft_stack_is_sorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_stacksize(*stack_a) > 3 && !ft_stack_is_sorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!ft_stack_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

/*
  This function pushes elements from b to a until b is empty
*/
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp->nbr, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

void	ft_sort_b_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (ft_stacksize(*stack_a) > 3 && !ft_stack_is_sorted(*stack_a))
	{
		temp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp->nbr, 'a');
			else
				temp = temp->next;
		}
	}
}

/*
  Main sort function
  Pushes all nbrs to stack b, until only 3 nbrs are left in stack a
  while still making sure that stack b is sorted
  Depending on the position of the minimum in a, rotates a to keep
  it sorted 
*/
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_stacksize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_stacksize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_rra(stack_a, 0);
		}
	}
}
