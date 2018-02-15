/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 03:19:55 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 03:19:55 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long			i;
	unsigned char			*source;
	unsigned char			*dest;
	unsigned char			c_cpy;

	source = (unsigned char*)src;
	dest = dst;
	c_cpy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if (dest[i] == c_cpy)
		{
			i++;
			return ((unsigned char*)dst + i);
		}
		i++;
	}
	return (0);
}
