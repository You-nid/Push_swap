/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:10:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/15 10:38:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - SORT
//ANCHOR - First rotation
void	ft_sortloop(t_stack *stack_1, t_stack *stack_2, t_variables *vars)
{
	ft_checkpoint(stack_1, stack_2, vars);
	ft_checkmax(stack_1, stack_2, vars);
	ft_checkpoint(stack_1, stack_2, vars);
	ft_checkmin(stack_1, stack_2, vars);
	ft_checkpoint(stack_1, stack_2, vars);
	ft_checkrotate(stack_1, stack_2, vars);
	ft_checkpoint(stack_1, stack_2, vars);
	ft_checkreverse(stack_1, stack_2, vars);
	ft_checkpoint(stack_1, stack_2, vars);
	ft_checkswap(stack_1, stack_2, vars);
	if (ft_issorted(stack_1->stack, ASC) == TRUE)
		return ;
	else if (vars->size_a > 3 && vars->algo == FALSE)
		ft_printer(ft_swap_push(stack_2, stack_1));
}

//ANCHOR - Set variables
void	ft_checkpoint(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	vars->max_a = ft_getmax(stack_a->stack);
	vars->min_a = ft_getmin(stack_a->stack);
	vars->top_a = ft_gettop(stack_a->stack);
	vars->last_a = ft_getlast(stack_a->stack);
	vars->size_a = ft_lstsize(stack_a->stack);
	vars->revnext_a = ft_getnext(stack_a->stack, BACKWARD);
	vars->revnext_b = ft_getnext(stack_b->stack, BACKWARD);
	if (vars->size_a > 2)
		vars->next_a = ft_getnext(stack_a->stack, FORWARD);
	if (stack_b != NULL)
	{
		vars->max_b = ft_getmax(stack_b->stack);
		vars->min_b = ft_getmin(stack_b->stack);
		vars->top_b = ft_gettop(stack_b->stack);
		vars->last_b = ft_getlast(stack_b->stack);
		vars->next_b = ft_getnext(stack_b->stack, FORWARD);
		vars->size_b = ft_lstsize(stack_b->stack);
	}
}

//ANCHOR - Sort Stack
void	ft_sortstack(t_stack *stack_a, t_stack *stack_b)
{
	t_variables	*vars;
	int			i;

	i = 0;
	if (ft_isempty(stack_a->stack))
		return ;
	vars = ft_calloc(1, sizeof(t_variables));
	if (!vars)
		return ;
	vars->full_size = ft_lstsize(stack_a->stack);
	if (vars->full_size == 1)
		return ;
	while (i < 4)
	{
		while (ft_issorted(stack_a->stack, ASC) != TRUE)
			ft_sortloop(stack_a, stack_b, vars);
		while (ft_isempty(stack_b->stack) != TRUE)
			ft_printer(ft_swap_push(stack_a, stack_b));
		++i;
	}
	free(vars);
}
//!SECTION
