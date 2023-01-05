/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:12:04 by meharit           #+#    #+#             */
/*   Updated: 2023/01/05 22:16:36 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_BONUS_H
# define SWAP_BONUS_H

# include<unistd.h>
# include<stdlib.h>

t_list	*make_stack(char **arg, int arg);
int		is_valide(char **s, int argc);
char	**ft_split(char const *s, char c);

