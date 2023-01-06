/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:12:04 by meharit           #+#    #+#             */
/*   Updated: 2023/01/06 11:23:00 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_BONUS_H
# define SWAP_BONUS_H

# include<unistd.h>
# include<stdlib.h>

t_list	*make_stack(char **args, int argc);
int		is_valide(char **s, int argc);
char	**ft_split(char const *s, char c);
int	check_error(char *s);
int	ft_isdigit(int c);
void	add_in_stack(t_list **stack_a, char **str);
void	error(void);
int	check_doubles(t_list *stack_a);

#endif