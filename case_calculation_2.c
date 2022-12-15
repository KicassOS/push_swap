/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_calculation_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:09:45 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/15 07:14:28 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  The following functions calculate the cost of each combination of rotations
  for all 4 possible cases, rarb, rrarb, rarrb, rrarrb
  These functions are called when pushing from b to a
  Stacks are being rotated together to minimize ops
*/
int	ft_case_rarb_a(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = ft_find_place_a(a, j);
	if (i < ft_find_index(b, j))
		i = ft_find_index(b, j);
	return (i);
}

int	ft_case_rrarb_a(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, j))
		i = ft_stacksize(a) - ft_find_place_a(a, j);
	i = ft_find_index(b, j) + i;
	return (i);
}

int	ft_case_rarrb_a(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = 0;
	if (ft_find_index(b, j))
		i = ft_stacksize(b) - ft_find_index(b, j);
	i = ft_find_place_a(a, j) + i;
	return (i);
}

int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, j))
		i = ft_stacksize(a) - ft_find_place_a(a, j);
	if ((i < (ft_stacksize(b) - ft_find_index(b, j))) && ft_find_index(b, j))
		i = ft_stacksize(b) - ft_find_index(b, j);
	return (i);
}
