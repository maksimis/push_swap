/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/23 16:15:37 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
							size_t dstsize)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;
	size_t	result;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	result = 0;
	if (dstsize > dst_length)
		result = src_length + dst_length;
	else
		result = src_length + dstsize;
	i = 0;
	while (dstsize != 0 && src[i] != '\0' && (dst_length) < (dstsize - 1))
	{
		dst[dst_length] = src[i];
		i++;
		dst_length++;
	}
	if (dstsize != 0)
		dst[dst_length] = '\0';
	return (result);
}
