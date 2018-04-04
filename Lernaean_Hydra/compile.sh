# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    compile.sh                                       .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/16 17:25:53 by brobicho     #+#   ##    ##    #+#        #
#    Updated: 2018/02/16 19:16:33 by brobicho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

make -C ./libft/
gcc -Wall -Werror -Wextra -o server server.c libft/libft.a
gcc -Wall -Werror -Wextra -o client client.c libft/libft.a
echo ""
echo "\033[1;92mProject ready !\033[0m"
