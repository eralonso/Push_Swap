/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:22:13 by eralonso          #+#    #+#             */
/*   Updated: 2022/09/29 10:10:06 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	size;

	size = len;
	while (len-- > 0)
		*((unsigned char *)(b++)) = (unsigned char)c;
	return (b - size);
}
