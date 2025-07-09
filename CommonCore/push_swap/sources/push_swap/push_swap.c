/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:48:13 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/08 16:21:31 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	free_argv(char **argv, int argc)
{
	int	i;

	if (argc != 2)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char	**parse_args(int argc, char **argv)
{
	if (argc == 2)
		return (split(argv[1], ' '));
	return (argv);
}

void	init_and_sort_stacks(t_stack_node **a, t_stack_node **b, char **argv,
		int original_argc)
{
	if (original_argc == 2)
		init_stack_a(a, argv, original_argc);
	else
		init_stack_a(a, argv + 1, original_argc);
	free_argv(argv, original_argc);
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

void	clean_exit(t_stack_node **a, char **argv, int original_argc)
{
	free_stack(a);
	free_argv(argv, original_argc);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				original_argc;

	a = NULL;
	b = NULL;
	original_argc = argc;
	if (argc == 1)
		return (1);
	if ((argc == 2 && !argv[1][0]))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_and_sort_stacks(&a, &b, argv, original_argc);
	free_stack(&a);
	return (0);
}
