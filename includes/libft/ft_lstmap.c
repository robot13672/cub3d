/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:36:54 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/12 20:01:07 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;

	if (!lst)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			del(new);
		}
		ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}

// int main()
// {
// 	t_list *list;
// 	t_list *second;

// 	 list = ft_lstnew((void *)"char");
// 	second = ft_lstnew((void *)"int");
// 	ft_lstadd_back(&list, second);
// 	ft_lstmap(list, )
// }