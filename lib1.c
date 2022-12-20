/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:31:39 by meharit           #+#    #+#             */
/*   Updated: 2022/12/19 17:54:48 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

/*void ft_lstdelone(t_list **lst)
//void ft_lstdelone(t_list *lst, void (*del)(int))
{

	if (lst != NULL)
//	if (lst != NULL && del)
	{
//		*lst->next = NULL;

	//	del(lst->content);
	//	free(lst);
	}
}
*/
/*void	del(int content)
{
	content  =;
}
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

