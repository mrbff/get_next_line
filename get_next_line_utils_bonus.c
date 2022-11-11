/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:58:26 by mabaffo           #+#    #+#             */
/*   Updated: 2022/11/11 15:58:49 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr[0] = '\0';
		return (substr);
	}
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	ft_scopy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_realloc(char **buf, size_t *dim)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(*buf))
	{
		*buf = malloc(BUFFER_SIZE + 1);
		if (!(*buf))
			return ;
		while (i <= BUFFER_SIZE)
			(*buf)[i++] = '\0';
		*dim = BUFFER_SIZE;
	}
	else
	{
		ptr = malloc(*dim + BUFFER_SIZE + 1);
		if (!ptr)
			return ;
		while (i <= *dim + BUFFER_SIZE)
			(ptr)[i++] = '\0';
		ft_scopy(ptr, *buf);
		free(*buf);
		*buf = ptr;
	}
	return ;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s || !(*s))
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_line(char *buf, size_t *i, long long int *j)
{
	*j = 0;
	while (buf[(*i) + (*j)] && buf[(*i) + (*j)] != '\n')
		(*j)++;
	if (buf[(*i) + (*j)] == '\n')
		(*j)++;
	if (!(*j))
		return (0);
	if (buf[(*i) + (*j) - 1] == '\n')
	{
		(*i) += (*j);
		return (1);
	}
	return (0);
}
