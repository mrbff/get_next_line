/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:57:22 by mabaffo           #+#    #+#             */
/*   Updated: 2022/11/11 15:39:17 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buff	roba;
	long long int	j;
	int				tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (!(roba.finish))
	{
		ft_realloc(&(roba.buf), &(roba.dim));
		if (!(roba.buf))
			return (NULL);
		if (ft_line(roba.buf, &(roba.i), &j) == 1)
			return (ft_substr(roba.buf, roba.i - j, j));
		tmp = read(fd, &((roba.buf)[(roba.dim) - BUFFER_SIZE]), BUFFER_SIZE);
		if (!tmp)
		{
			free(roba.buf);
			roba.finish = 1;
			return (NULL);
		}
		(roba.dim) += BUFFER_SIZE;
		roba.buf[ft_strlen(roba.buf)] = '\0';
	}
	return (NULL);
}
