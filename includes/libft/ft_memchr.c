/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:23:57 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/11 14:32:43 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	needle;

	i = 0;
	str = (unsigned char *)s;
	needle = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == needle)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
