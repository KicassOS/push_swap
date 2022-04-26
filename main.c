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

char	arguments_valid(int	argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[j])
		{
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (!arguments_valid(argc, argv))
		return (-1);
	
	return (0);
}
