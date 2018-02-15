/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 16:54:08 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 21:00:30 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

static int	ft_securelen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	int					client_fd;
	int					port;
	struct sockaddr_in	serv_addr;
	char				buff[256];

	port = ft_atoi(av[1]);
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	ft_bzero(&serv_addr, sizeof(serv_addr));

	serv_addr.sin_port = htons(port);
	serv_addr.sin_family = AF_INET;

	inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

	connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	while (1)
	{
		read(0, buff, 256);
		write(client_fd, &buff, 256);
		if (!(ft_strncmp(buff, "quit", 256)))
			break ;
		bzero(buff, 256);
		recv(client_fd, buff, 256, 0);
		ft_putstr(buff);
		bzero(buff, 256);
	}
	close(client_fd);
	return (0);
}
