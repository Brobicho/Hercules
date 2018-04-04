/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/06 16:52:44 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 16:50:26 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(char **str, int fd)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	tmp = *str;
	*str = ft_strjoin(*str, buf);
	if (*tmp)
		free(tmp);
	return (ret);
}

static int	ft_getline(char **str, char **line, char *s)
{
	int		ret;
	char	*tmp;

	ret = 0;
	if (*s == '\n')
		ret = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	if (ret == 0 && ft_strlen(*str))
	{
		*str = ft_strnew(1);
		return (1);
	}
	else if (ret == 0 && !(ft_strlen(*str)))
		return (0);
	tmp = *str;
	*str = ft_strjoin(s + 1, "");
	free(tmp);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*tmp;
	static char	*str;

	if (!str)
		str = "";
	if (!line || BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (line)
	{
		tmp = str;
		while (*tmp || ret < BUFF_SIZE)
		{
			if (*tmp == '\n' || !*tmp || *tmp == -1)
				return (ft_getline(&str, line, tmp));
			tmp++;
		}
		ret = ft_read(&str, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
