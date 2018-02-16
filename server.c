/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:35:47 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 16:31:40 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

static void		ft_server_start(char *buff, int client_fd)
{
	while (1)
	{
		ft_bzero(buff, 256);
		read(client_fd, buff, 256);
		if (!ft_strncmp(buff, "ping", 4) && !ft_isalnum(buff[4]))
			write(client_fd, "pong pong\n", 10);
		else if (!ft_strncmp(buff, "quit", 4) && !ft_isalnum(buff[4]))
		{
			ft_putendl_fd("Server closed", client_fd);
			break ;
		}
		else
			write(client_fd, "\0", 1);
	}
	close(client_fd);
}

static void		ft_init_struct(struct sockaddr_in *serv_addr, int port)
{
	serv_addr->sin_family = AF_INET;
	serv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr->sin_port = htons(port);
}

int				main(int ac, char **av)
{
	int					listen_fd;
	int					client_fd;
	struct sockaddr_in	serv_addr;
	char				buff[256];

	if (ac != 2)
	{
		write(1, "Usage : ./server [port]\n", 25);
		return (0);
	}
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	ft_bzero(&serv_addr, sizeof(serv_addr));
	ft_bzero(buff, sizeof(buff));
	ft_init_struct(&serv_addr, ft_atoi(av[1]));
	bind(listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	listen(listen_fd, 10);
	client_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
	ft_server_start(buff, client_fd);
	close(listen_fd);
	return (0);
}
