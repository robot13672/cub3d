/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:08:36 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/10 00:18:00 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_chr(long value)
{
	size_t	size;

	size = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		value *= -1;
	while (value > 0)
	{
		value = value / 10;
		size++;
	}
	return (size);
}

void	ft_fillnumb(char *ptr, int size, long value)
{
	ptr[size] = '\0';
	if (value < 0)
		value *= -1;
	if (value == 0)
		ptr[--size] = 48;
	while (value > 0)
	{
		ptr[--size] = value % 10 + 48;
		value /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*ptr;
	int		sign;
	long	value;

	sign = 0;
	value = n;
	if (n < 0)
		sign = -1;
	size = ft_count_chr(value);
	if (sign < 0)
	{
		ptr = malloc(size + 2);
		if (!ptr)
			return (NULL);
		*ptr = '-';
		size += 1;
	}
	else
		ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_fillnumb(ptr, size, value);
	return (ptr);
}

// int main()
// {
// 	int value = -2147483648LL;
// 	char *ptr = ft_itoa(value);
// 	printf("%s", ptr);
// }