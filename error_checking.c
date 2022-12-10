/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:55:23 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/10 02:46:38 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_only_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}
