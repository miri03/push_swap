/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2lib.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:40:08 by meharit           #+#    #+#             */
/*   Updated: 2022/12/17 18:33:59 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include <limits.h>
	
void	int_max(unsigned int result, int sign)
{
	if (result > INT_MAX)
	{
		if (result == 2147483648 && sign < 0)
			return ;
		write (1, "Error\n", 6);
		exit (0);
	}
}

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		int_max(result, sign);
		i++;
	}
	return (((int)result * sign));
}

int	check_doubles(t_list *stack_a)
{
	t_list	*B;

	while (stack_a->next != NULL)
	{
		B = stack_a->next;
	//	printf("test\n");
		while (B->next != NULL)
		{
			if (stack_a->content == B->content)
				return (0);
			B = B->next;
		}
		stack_a = stack_a->next;
		//printf("yes\n");
	}
	return (1);
}
