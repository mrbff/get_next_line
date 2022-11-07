/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:02:49 by mabaffo           #+#    #+#             */
/*   Updated: 2022/11/01 21:50:52 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
/*
typedef struct s_buff
{
	static	unsigned long	i;
	static	char	*buff;
	static	long long	finish;
}	t_buff;
*/
char	*get_next_line(int fd);
void    *ft_realloc(void *ptr, size_t plus);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    *ft_memmove(void *dest, const void *src, size_t n);
size_t  ft_strlen(const char *s);

#endif
