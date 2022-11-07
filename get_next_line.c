/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:57:22 by mabaffo           #+#    #+#             */
/*   Updated: 2022/11/07 19:44:57 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_buff roba;
	long long int j;
	int tmp;

	while (!(roba.finish))
	{
		ft_realloc(&(roba.buf), &(roba.dim));
		if (!(roba.buf))
			return (NULL);
	/*	j = 0;
		while (((roba.buf)[(roba.i) + j]) && (roba.buf)[(roba.i) + j] != '\n')
			j++;
		j += ((roba.buf)[(roba.i) + j] == '\n');
		if ((roba.buf)[(roba.i) + j - 1] == '\n' && j != 0)
		{
			roba.i += j;
			return (ft_substr(roba.buf, roba.i - j, j));
		}*/
		if (ft_line(roba.buf, &(roba.i), &j) == 1)
			return (ft_substr(roba.buf, roba.i - j, j));
		tmp = read(fd, &((roba.buf)[(roba.dim) - BUFFER_SIZE]), BUFFER_SIZE);
		if (tmp == -1)
			return (NULL);
		if (!tmp && !roba.finish)
		{
			roba.finish = 1;
			return (ft_substr(roba.buf, roba.i - j, j));
		}
		(roba.dim) += BUFFER_SIZE;
		roba.buf[(roba.dim) + 1] = '\0';
	}
	return (NULL);
}
