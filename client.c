/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clitest.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 14:59:20 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 16:38:55 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

void	ft_init_struct(struct sockaddr_in *serv_addr)
{
	serv_addr->sin_family = AF_INET;
	serv_addr->sin_port = htons(25565);
	serv_addr->sin_addr.s_addr = INADDR_ANY;
}

int		main(void)
{
	int					server_fd;
	int					ret;
	struct sockaddr_in	serv_addr;
	char				buff[256];

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	ft_init_struct(&serv_addr);
	ret = connect(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if (ret == -1)
	{
		ft_putendl("Connection failed");
		return (0);
	}
	while (1)
	{
		bzero(buff, 256);
		read(0, buff, 256);
		if (!strncmp("close", buff, 5))
			break ;
		send(server_fd, &buff, 256, 0);
		bzero(buff, 256);
		recv(server_fd, &buff, 256, 0);
		ft_putstr(buff);
	}
	return (0);
}
