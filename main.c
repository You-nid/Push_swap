/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:11:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/11 14:55:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

//KEYWORDS - Find the shortes path / Algorithm validation /  
//REVIEW - https://www.computerscienceai.com/2019/04/c-program-for-binary-search.html
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	time_t	rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	ft_printf("Time [%d:%d]\n", timeinfo->tm_min, timeinfo->tm_sec);
	if (ac > 4 && ac < ARG_MAX)
	{
		stack_a = ft_create_stack();
		stack_b = ft_create_stack();
		ft_initiatestack(&stack_a, av, ac);
		if (ft_checkduplicates(stack_a) != FALSE)
		{
			ft_putstr_fd("Error", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		ft_sortstacks(&stack_a, &stack_b);
		ft_free(&stack_a, &stack_b);
	}
	else
	{
		ft_putstr_fd("Minimum 4 arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	timeinfo = localtime(&rawtime);
	ft_printf("Time [%d:%d]\n", timeinfo->tm_min, timeinfo->tm_sec);
	//system("leaks push_swap");
	return (EXIT_SUCCESS);
}
