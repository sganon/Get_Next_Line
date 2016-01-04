/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:22:41 by sganon            #+#    #+#             */
/*   Updated: 2016/01/04 14:47:46 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*random;
	int		i;
	int		ret;

	(void)argc;
	i = 0;
	random = NULL;
	if ( 1 > (fd = open(argv[1], O_RDONLY)))
		fd = 0;
	while (42)
	{
		ret = get_next_line(fd, &random);
		if (ret == 1)
		{
			ft_putnbr(i);
			ft_putstr(" : ");
			ft_putendl(random);
			free(random);
			i++;
		}
		else if (ret == -1)
		{
			ft_putendl("error");
			break ;
		}
		else
			break ;
	}
	ft_putendl("Bisous");
	return (0);
}
