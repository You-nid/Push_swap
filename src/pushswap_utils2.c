/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:32:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/11 10:40:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_isdigit_str(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != TRUE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_reverse_stack(t_stack **top)
{
	t_stack	*prev;
	t_stack	*next;
	t_stack	*curr;

	curr = (*top);
	prev = NULL;
	next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	(*top) = prev;
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	ft_issorted(t_stack *top)
{
	t_stack	*node;

	if (ft_isempty(top))
		return (0);
	node = top;
	while (node->next != NULL)
	{
		if (node->num > node->next->num)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}
