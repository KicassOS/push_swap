/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 05:31:21 by pszleper          #+#    #+#             */
/*   Updated: 2022/12/15 07:23:39 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_program(t_program *program, char is_error)
{
	if (program->stack_mallocd == TRUE)
		ft_free_stack(program->stack_a, program);
	if (program->split_mallocd == TRUE)
		ft_free_split(program->temp, program);
	if (is_error == TRUE)
		ft_print_error_exit();
	exit(EXIT_SUCCESS);
}
