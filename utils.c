/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:54:10 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/10 02:58:26 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(PUSH_SWAP_ERROR);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*temp;

	if (!a)
		return ;
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

int	ft_atoi2(char *str)
{
	int			mod;
	long long	i;

	i = 0;
	mod = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_print_error_exit();
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_print_error_exit();
	return (mod * i);
}
