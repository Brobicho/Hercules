/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 03:02:36 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/10 13:34:54 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *mem, size_t size)
{
	void		*mem_cpy;

	if (!mem || !size || !(mem_cpy = ft_strnew(size)))
		return (NULL);
	ft_strcpy(mem_cpy, mem);
	free(mem);
	return (mem_cpy);
}
