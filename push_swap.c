/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:57:28 by pszleper          #+#    #+#             */
/*   Updated: 2022/04/05 21:57:28 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle_no_arg(int argc, char **argv)
{
	if (argc == 1 || ft_is_only_whitespace(argv[1]))
		exit(0);
}

/*
  This function gets called when argc == 2 (the list of ints is passed
  between quotes)
*/
t_stack	*ft_parse_argstring(char **argv, t_program *program)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	temp = ft_split_whitespace2(argv[1]);
	program->temp = temp;
	program->split_mallocd = TRUE;
	while (temp[i])
	{
		j = ft_atoi2(temp[i], program);
		ft_stack_add_back(program->stack_a, ft_stack_new(j, program));
		i++;
	}
	ft_free_split(temp, program);
	free(temp);
	return ((*program->stack_a));
}

t_stack	*ft_arg_parse(int argc, char **argv, t_program *program)
{
	int		i;
	int		j;

	i = 1;
	if (argc == 2)
		(*program->stack_a) = ft_parse_argstring(argv, program);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i], program);
			ft_stack_add_back(program->stack_a, ft_stack_new(j, program));
			i++;
		}
	}
	return ((*program->stack_a));
}

char	ft_stack_is_sorted(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (0);
		i = a->nbr;
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_program	program;

	a = NULL;
	ft_init_program(&program, &a);
	ft_handle_no_arg(argc, argv);
	a = ft_arg_parse(argc, argv, &program);
	if (!a || ft_check_duplicates(a))
		ft_exit_program(&program, TRUE);
	if (!ft_stack_is_sorted(a))
		ft_sort(&a);
	ft_exit_program(&program, FALSE);
	return (0);
}
