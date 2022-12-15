/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:51:25 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/15 06:54:23 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  This function calculates which rotation combo is best to sort the stack
  The following function is used during the push from b to a
*/
int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = b;
	i = ft_case_rrarrb_a(a, b, b->nbr);
	while (temp)
	{
		if (i > ft_case_rarb_a(a, b, temp->nbr))
			i = ft_case_rarb_a(a, b, temp->nbr);
		if (i > ft_case_rrarrb_a(a, b, temp->nbr))
			i = ft_case_rrarrb_a(a, b, temp->nbr);
		if (i > ft_case_rarrb_a(a, b, temp->nbr))
			i = ft_case_rarrb_a(a, b, temp->nbr);
		if (i > ft_case_rrarb_a(a, b, temp->nbr))
			i = ft_case_rrarb_a(a, b, temp->nbr);
		temp = temp->next;
	}
	return (i);
}

/*
  This function calculates which rotation combo is best to sort the stack
  The following function is used during the push from a to b
*/
int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = ft_case_rrarrb(a, b, a->nbr);
	while (temp)
	{
		if (i > ft_case_rarb(a, b, temp->nbr))
			i = ft_case_rarb(a, b, temp->nbr);
		if (i > ft_case_rrarrb(a, b, temp->nbr))
			i = ft_case_rrarrb(a, b, temp->nbr);
		if (i > ft_case_rarrb(a, b, temp->nbr))
			i = ft_case_rarrb(a, b, temp->nbr);
		if (i > ft_case_rrarb(a, b, temp->nbr))
			i = ft_case_rrarb(a, b, temp->nbr);
		temp = temp->next;
	}
	return (i);
}
