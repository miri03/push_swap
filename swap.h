/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:47:58 by meharit           #+#    #+#             */
/*   Updated: 2022/12/17 19:53:17 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

typedef	struct	s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

int			is_valide(char **s, int argc);
int			check_error(char *s);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_isdigit(int c);
int			ft_size(char const *s, char c);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			check_doubles(t_list *stack_a);

#endif
