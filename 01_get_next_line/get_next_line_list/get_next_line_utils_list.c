/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:46:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/01/11 14:46:10 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_list.h"

void	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1_len;
	size_t	i;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	ptr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

t_list	*ft_lstnew(int fd)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (!lst)
		return (NULL);
	lst->fd = fd;
	lst->backup = NULL;
	lst->next = NULL;
	return (lst);
}
