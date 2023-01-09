/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:49 by pszleper          #+#    #+#             */
/*   Updated: 2023/01/08 04:06:44 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// This function is the second part of the ft_check function.
void	ft_check_sub(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

// This function reads the line and checks if the command is valid.
// If it is, it executes the command.
char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else
		ft_error_ch();
	return (get_next_line(STDIN_FILENO));
}

// This function checks the validity of the commands and stack.
// If it is valid, and the stack_a is sorted, the program prints "OK". 
void	ft_checker_sub(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(STDOUT_FILENO, "KO\n", 3);
	else if (!ft_checksorted(*a))
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;
	t_program	program;

	b = NULL;
	a = ft_arg_parse(argc, argv, program);
	if (!a || ft_checkdup(a))
	{
		ft_free (&a);
		ft_checker_error();
	}
	line = get_next_line(STDIN_FILENO);
	if (!line && !ft_checksorted(a))
		write(STDOUT_FILENO, "KO\n", 3);
	else if (!line && ft_checksorted(a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		ft_checker_sub(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}
