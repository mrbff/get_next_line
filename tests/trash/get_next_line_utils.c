/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:20:05 by mabaffo           #+#    #+#             */
/*   Updated: 2022/11/01 20:54:31 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_realloc(void *ptr, size_t plus)
{
        void	*p;
	size_t	ptrlen;

	if (!ptr)
	{
		p = malloc(plus + 1);
                if (!p)
                        return (NULL);
		((char *)p)[0] = '\0';
	}
	else if (*((char *)ptr))
        {
		ptrlen = ft_strlen(ptr);
                p = malloc(ptrlen + plus + 1);
                if (!p)
                        return (NULL);
                ft_memmove(p, ptr, ptrlen);
		((char *)p)[ptrlen + plus] = '\0';
		((char *)p)[ptrlen] = '\0';
                free(ptr);
        }
        return (p);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *substr;
        size_t  i;

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

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

void    *ft_memmove(void *dest, const void *src, size_t n)
{
        if (!dest && !src)
                return (0);
        while (n--)
                ((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
        return (dest);
}
