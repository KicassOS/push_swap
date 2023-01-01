/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:29:52 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/30 02:29:32 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  handles edge case where there's a lone + or - sign in split string
*/
void	ft_check_atoi2(char *str, t_program *prog)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && !ft_isdigit(str[0]))
		ft_exit_program(prog, TRUE);
}

long	ft_loop_rest(char *str, long neg, long i, t_program *prog)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_exit_program(prog, TRUE);
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((neg * i) > 2147483647 || (neg * i) < -2147483648)
		ft_exit_program(prog, TRUE);
	return (neg * i);
}
