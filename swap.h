/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:47:58 by meharit           #+#    #+#             */
/*   Updated: 2023/01/06 16:58:25 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>

typedef struct variable_list
{
	int	size;
	int	middle;
	int	offset;
	int	start;
	int	end;
}			t_var_li;

typedef struct variables
{
	int	max;
	int	i;
	int	index;
}			t_v_li;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(int content);
t_list		*ft_newlast(t_list *stack);

void		add_in_stack(t_list **stack_a, char **str);
int			is_valide(char **s, int argc);
int			check_error(char *s);

int			ft_isdigit(int c);
int			ft_size(char const *s, char c);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			check_doubles(t_list *stack_a);

void		error(void);
void		free_str(char **str);

void		swap_a(t_list **stack_a, int ss);
void		swap_b(t_list **stack_b, int ss);
void		swap_a_b(t_list *stack_a, t_list *stack_b, int ss);
void		push_b(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_a, t_list **stack_b);
void		rotate_a(t_list **stack_a, int rr);
void		rotate_b(t_list **stack_b, int rr);
void		rotate_a_b(t_list **stack_a, t_list **stack_b, int rr);
void		rev_rotate_a(t_list **stack_a, int rrr);
void		rev_rotate_b(t_list **stack_b, int rrr);
void		rev_rotate(t_list **stack_a, t_list **stack_b, int rrr);

void		sort_list(t_list **stack_a, t_list **stack_b);
void		sort_three(t_list **stack_a);
int			is_sorted(t_list *stack);
void		sort_three_s(t_list *first, t_list *second, t_list **stack_a);
void		utiliti(t_list **stack_a, t_list **stack_b);
int			min_value(t_list *head);
int			ft_check_pb(t_list **stack_a, t_list **stack_b);

int			*array_sort(t_list *stack_a);
int			is_rev_sorted(t_list *stack);
int			ft_n(t_list *stack_a);
int			max_value(t_list *stack);
int			chunk(t_list **stack_a, t_list **stack_b, t_var_li var, int *array);
void		sort_b(t_list **stack_a, t_list **stack_b, int nb, int middle);

int			is_sa(t_list **stack_a, t_list **stack_b, int *array, t_v_li vrb);
int			sa_rev_or_rotate(t_list **stack_a, t_list **stack_b, t_v_li vrb,
				int *array);
void		push_to_a(t_list **stack_a, t_list **stack_b, t_var_li var,
				int *array);

char		*ft_read(char *string, int fd);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			new_line(char *str);
size_t		ft_strlen(const char *s);
char		*ft_remain(char *s);
char		*ft_line(char *s);
char		*ft_strdup(const char *s1);

int			ft_strcmp(char *s1, char *s2);

void		push_a_bonus(t_list **stack_a, t_list **stack_b, int pa);
void		push_b_bonus(t_list **stack_a, t_list **stack_b, int pb);

#endif
