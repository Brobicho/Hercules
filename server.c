/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:35:47 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 20:47:50 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

int		main(int ac, char **av)
{
	int					listen_fd;
	int					client_fd;
	struct sockaddr_in	serv_addr;
	char				buff[256];
	int					port;

	if (ac != 2)
	{
		write(1, "Usage : ./server [port]\n", 25);
		return (0);
	}
	port = ft_atoi(av[1]);
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	ft_bzero(&serv_addr, sizeof(serv_addr));
	ft_bzero(buff, sizeof(buff));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	bind(listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	listen(listen_fd, 10);
	client_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
	while (1)
	{
		ft_bzero(buff, 256);
		read(client_fd, buff, 256);
		if (!ft_strncmp(buff, "ping", 4))
			write(client_fd, "pong pong\n", 10);
		if (!ft_strncmp(buff, "quit", 4))
		{
			write(client_fd, "Server closed\n", 14);
			break ;
		}
	}
	close(client_fd);
	return (0);
}
