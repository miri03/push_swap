/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:35:20 by meharit           #+#    #+#             */
/*   Updated: 2022/12/18 01:10:14 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	is_valide(char **s, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (check_error(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_error(char *s)
{
	int i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == ' ') &&
				(s[i] == '-' || s[i] == '+') && s[i + 1] != ' ')
			i++;
		if (ft_isdigit(s[i]) || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

