/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:35:20 by meharit           #+#    #+#             */
/*   Updated: 2022/12/15 23:29:22 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	is_numeric(char *s)
{
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if ((*s >= '0' && *s <= '9') || *s == ' ')
			s++;
		else
			return (0);
	}
	return (1);
}
t_list	*ft_lstnew(void *content)
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

int	ft_atoi(const char *str)
{
	unsigned long long	result;
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
		i++;
	}
	return (((int)result * sign));
}

static int	ft_size(char const *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static char	*ft_word(char const *s, int size)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (word == NULL)
		return (NULL);
	while (size > i)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	error_free(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
}

static void	ft_alloc(char **result, char const *s, char c, int size)
{
	int		alloc;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] && i < size)
	{
		alloc = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j + alloc] && s[j + alloc] != c)
			alloc++;
		result[i] = ft_word(&s[j], alloc);
		if (result[i] == NULL)
		{
			error_free(result, i);
			free(result);
			return ;
		}
		i++;
		j += alloc;
	}
	result[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (s == NULL)
		return (NULL);
	size = ft_size(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_alloc(result, s, c, size);
	return (result);
}

