/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 14:59:20 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 18:23:32 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

static void		ft_client_start(int server_fd)
{
	char buff[256];

	while (1)
	{
		ft_bzero(buff, 256);
		read(0, buff, 256);
		if (!ft_strncmp("close\n", buff, 6) || !ft_strncmp("close\r\n", buff, 7))
			break ;
		send(server_fd, &buff, 256, 0);
		ft_bzero(buff, 256);
		recv(server_fd, &buff, 256, 0);
		write(1, &buff, 256);
	}
}

static void		ft_init_struct(struct sockaddr_in *serv_addr, int port)
{
	serv_addr->sin_family = AF_INET;
	serv_addr->sin_port = htons(port);
	serv_addr->sin_addr.s_addr = INADDR_ANY;
}

int				main(int ac, char **av)
{
	int					server_fd;
	int					ret;
	struct sockaddr_in	serv_addr;

	if (ac != 2)
	{
		ft_putendl("Usage : ./client [port]");
		return (0);
	}
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	ft_init_struct(&serv_addr, ft_atoi(av[1]));
	ret = connect(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if (ret == -1)
	{
		ft_putendl("Connection failed");
		return (0);
	}
	ft_client_start(server_fd);
	close(server_fd);
	return (0);
}
