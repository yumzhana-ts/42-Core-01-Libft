/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:57:58 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/03/31 07:07:39 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*savenode;
	t_list	*listnew;
	t_list	*newnode;

	savenode = lst;
	listnew = NULL;
	while (savenode)
	{
		newnode = ft_lstnew(f(savenode->content));
		if (newnode == NULL)
		{
			ft_lstclear(&listnew, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&listnew, newnode);
		savenode = savenode->next;
	}
	newnode = NULL;
	return (listnew);
}
