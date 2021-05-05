/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:48:29 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 06:24:12 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recursive_clear(t_list *lst, void (*del)(void*))
{
	if (lst->next == NULL)
	{
		del(lst->content);
		free(lst);
		return ;
	}
	recursive_clear(lst->next, del);
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !*lst)
		return ;
	recursive_clear(*lst, del);
	*lst = 0;
}
