/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:33:30 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/10 20:02:29 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (ptr);
}

// int main () {
//    int len;
//    const char str[] = "http://www.tutorialspoint.com";
//    int c = 119;
//    char *ret;

//    ret = ft_strrchr(str, c);

//    printf("String after |%c| is - |%s|\n", c, ret);

//    return(0);
// }