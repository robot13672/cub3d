/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:46:52 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/11 00:58:02 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	size_t	j;
	int		count;

	j = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			j++;
			count = 1;
		}
		else if (*s == c)
		{
			count = 0;
		}
		s++;
	}
	return (j);
}

char	*word_lenght(char const *s, char del, int *len)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i + *len] != del)
	{
		if (s[i + *len] == '\0')
			break ;
		i++;
	}
	res = ft_substr(s, *len, i);
	*len += i + 1;
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		i;
	char	**res;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) *(word_count(s, c) + 1));
	if (!res)
		return (NULL);
	while (i != word_count(s, c))
	{
		if (s[len] == c)
			len++;
		else
			res[i++] = word_lenght(s, c, &len);
	}
	res[i] = 0;
	return (res);
}

// int main()
// {
// 	char	**ptr;
// 	ptr = ft_split("Hello World", ' ');
// }