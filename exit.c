/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 05:31:21 by pszleper          #+#    #+#             */
/*   Updated: 2023/01/01 01:19:12 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_program(t_program *program, char is_error)
{
	if (program->stack_mallocd == TRUE)
		ft_free_stack(program->stack_a, program);
	if (program->split_mallocd == TRUE)
	{
		ft_free_split(program->temp, program);
		free(program->temp);
	}
	if (is_error == TRUE)
		ft_print_error_exit();
	exit(EXIT_SUCCESS);
}
