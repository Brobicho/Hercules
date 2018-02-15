/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 03:20:00 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 03:20:00 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_words(const char *str, char c)
{
	int		wcount;
	int		i;

	wcount = 0;
	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] >= 33 && str[i] <= 126)
			wcount++;
		while (str[i] != c && str[i])
			i++;
	}
	return (wcount);
}

static int		ft_lcount(const char *str, char c)
{
	int		nb;

	nb = 0;
	while (str[nb] != c && str[nb])
		nb++;
	return (nb);
}

static void		ft_ezcpy(const char *src, char *dest, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	int		wcount;
	char	**res;
	int		i;
	int		j;
	int		lcount;

	i = 0;
	j = 0;
	if (s)
		wcount = ft_nbr_words(s, c);
	if (!s || !(res = (char**)malloc(sizeof(char*) * wcount + 1)))
		return (NULL);
	while (j < wcount)
	{
		while (s[i] == c)
			i++;
		lcount = ft_lcount(s + i, c);
		if (!(res[j] = (char *)malloc(sizeof(*res) * (lcount + 1))))
			return (NULL);
		ft_ezcpy(s + i, res[j], lcount);
		i = i + lcount;
		j++;
	}
	res[j] = 0;
	return (res);
}
