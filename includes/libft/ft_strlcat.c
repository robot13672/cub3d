/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:50:58 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/04 13:12:40 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	res;

	s = (char *)src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	res = 0;
	if (size > dst_len)
		res = src_len + dst_len;
	else
		res = src_len + size;
	while (s[i] && (dst_len + 1) < size)
	{
		dst[dst_len] = s[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (res);
}
