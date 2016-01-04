/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:15:51 by sganon            #+#    #+#             */
/*   Updated: 2016/01/04 16:16:08 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*read_til_n(int const fd, char *buf, char *ret)
{
	int			i;
	int			j;

	i = 0;
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		j = 0;
		buf[i] = 0;
		if (ret)
			ret = ft_strjoin(ret, buf); 
		else
			ret = ft_strdup(buf);
		while (buf[j])
		{
			if (buf[j] == '\n')
				return (ret);
			j++;
		}
	}
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	static char	*reste = NULL;
	char		*buf;
	int			i;

	i = 0;
	if (!reste)
		reste = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	write(1, "d1\n", 3);
	buf = read_til_n(fd, buf, reste);
	write(1, "d2\n", 3);
	while (buf[i] && buf[i] != '\n')
		i++;
	write(1, "d3\n", 3);
	reste = i > 0 ? ft_strsub(buf, (i + 1), ft_strlen(buf)) : NULL;
	write(1, "d4\n", 3);
	*line = ft_strsub(buf, 0, i);
	write(1, "d5\n", 3);
	if (i > 0)
		return (1);
	return (0);
}
