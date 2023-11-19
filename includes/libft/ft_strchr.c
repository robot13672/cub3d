/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:58:17 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/10 19:58:26 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (unsigned char) c)
		return ((char *) s);
	return (0);
}

// int main () {
//    const char str[] = "http://www.tutorialspoint.com";
//    int c = 119;
//    char *ret;

//    ret = ft_strchr(str, c);

//    printf("String after |%c| is - |%s|\n", c, ret);

//    return(0);
// }