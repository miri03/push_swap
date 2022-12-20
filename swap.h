/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:47:58 by meharit           #+#    #+#             */
/*   Updated: 2022/12/20 02:21:23 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>

typedef	struct	s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

void printList(t_list *head); //
int			is_valide(char **s, int argc);
int			check_error(char *s);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_isdigit(int c);
int			ft_size(char const *s, char c);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			check_doubles(t_list *stack_a);
int			ft_lstsize(t_list *lst);
//void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst);
//void		del(int content);
t_list		*ft_lstnew(int content);

void		swap_a(t_list *stack_a);
void		swap_b(t_list *stack_b);
void		swap_a_b(t_list *stack_a, t_list *stack_b);
void		push_b(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_a, t_list **stack_b);


#endif
