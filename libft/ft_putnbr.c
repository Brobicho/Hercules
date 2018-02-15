/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 03:19:56 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 03:19:56 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int i;

	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	i = n % 10;
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	if (n != -2147483648)
		ft_putchar(i + 48);
}
