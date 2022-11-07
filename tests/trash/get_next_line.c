/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:44 by mabaffo           #+#    #+#             */
/*   Updated: 2022/11/01 22:59:09 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUF_SIZE
#define BUF_SIZE 5
#endif
#include <stdio.h>
/*
typedef struct s_buff
{
        static  unsigned long   i;
        static  char    *buff;
        static  long long       finish;
}       t_buff;
*/
char	*get_next_line(int fd)
{	
	long long int tmp;
	size_t j;
	static  unsigned long   i;
        static  char    *buff;
        static  long long       finish;


	if (fd < 0 || BUF_SIZE < 1)
		return (NULL);
	while (!(finish))
	{
		if (buff)
			printf("%s\n", buff);
		printf("%d\n", i);
		j = 0;
		//write(1, "cazo\n", 5);
		if (buff)
		{
			while ((buff)[(i) + j] != '\n' && (buff)[(i) + j])
				j++;//(A.i)++;
			if(buff[i + j] == '\n')
			{
				tmp = i;
				i += j;
				return (ft_substr(buff, tmp, j + 1));
			}
			i += j;
		}
		if (!(finish))
		{
			buff = ft_realloc(buff, BUF_SIZE);
			if (!(buff))
				return (NULL);
		}
		tmp = read(fd, &((buff)[i]), BUF_SIZE);
		printf("tmp = %ld", tmp);
		if ((!tmp || tmp == -1) && !(finish))
		{
			finish = (tmp == 0);
			return (ft_substr(buff, (i), j + 1));
		}
		else if ((!tmp || tmp == -1) && finish)
				return (NULL);
	}
	return (NULL);
}
