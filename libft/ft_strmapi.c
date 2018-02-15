/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 03:19:59 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 03:19:59 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	if (!(res = malloc((sizeof(char) * ft_strlen(s) + 1))))
		return (NULL);
	while (*s)
		res[i++] = f(j++, *s++);
	res[i] = '\0';
	return (res);
}
