/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:47:58 by meharit           #+#    #+#             */
/*   Updated: 2022/12/12 01:05:12 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include<unistd.h>
# include<stdlib.h>

typedef	struct	list
{
	void		*content;
	struct list	*next;
}				stk_list;

#endif
