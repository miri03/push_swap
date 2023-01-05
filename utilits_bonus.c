/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:04:32 by meharit           #+#    #+#             */
/*   Updated: 2023/01/05 22:11:54 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_bonus.h"

t_list	*make_stack(char **args, int argc)
{
	char	**str;
	t_list	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	if (is_valide(args, argc))
	{
		while (i <= argc)
		{
			str = ft_split(args[i], ' ');
			i++;
			add_in_stack(&stack_a, str);
		}
	}
	else
		error();
	return (stack_a);
}
