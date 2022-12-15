/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_calculation_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:01:01 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/15 07:11:50 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  The following functions calculate the cost of each combination of rotations
  for all 4 possible cases, rarb, rrarb, rarrb, rrarrb
  These functions are called when pushing from a to b
  Stacks are being rotated together to minimize ops
*/
int	ft_case_rarb(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = ft_find_place_b(b, j);
	if (i < ft_find_index(a, j))
		i = ft_find_index(a, j);
	return (i);
}

int	ft_case_rrarb(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = 0;
	if (ft_find_index(a, j))
		i = ft_stacksize(a) - ft_find_index(a, j);
	i = ft_find_place_b(b, j) + i;
	return (i);
}

int	ft_case_rarrb(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, j))
		i = ft_stacksize(b) - ft_find_place_b(b, j);
	i = ft_find_index(a, j) + i;
	return (i);
}

int	ft_case_rrarrb(t_stack *a, t_stack *b, int j)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, j))
		i = ft_stacksize(b) - ft_find_place_b(b, j);
	if ((i < (ft_stacksize(a) - ft_find_index(a, j))) && ft_find_index(a, j))
		i = ft_stacksize(a) - ft_find_index(a, j);
	return (i);
}
