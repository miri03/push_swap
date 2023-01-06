/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2lib.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:40:08 by meharit           #+#    #+#             */
/*   Updated: 2023/01/05 21:27:06 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "swap_bonus.h"

int	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_error(char *s)
{
	int	i;

	i = 0;
	if (only_space(s))
		return (0);
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == ' ')
			&& (s[i] == '-' || s[i] == '+') && s[i + 1] != ' ')
			i++;
		if (ft_isdigit(s[i]) || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

void	int_max(unsigned int result, int sign)
{
	if (result > INT_MAX)
	{
		if (result == 2147483648 && sign < 0)
			return ;
		error();
	}
}

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				i;
	int				sign;

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
	t_list	*b;

	while (stack_a->next != NULL)
	{
		b = stack_a->next;
		while (b != NULL)
		{
			if (stack_a->content == b->content)
				return (0);
			b = b->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
