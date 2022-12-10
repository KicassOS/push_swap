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
		ft_print_error_exit();
}

t_stack	*ft_parse_argstring(char **argv)
{
	
}

t_stack	*ft_arg_parse(int argc, char **argv)
{
	t_stack	*a;
	int	i;
	int	j;

	i = 1;
	a = NULL;
	if (argc == 2)
		a = ft_parse_argstring(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	ft_handle_no_arg(argc, argv);
	a = ft_arg_parse(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free_stack(&a);
		ft_print_error_exit();
	}
	if (!ft_stack_is_sorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
