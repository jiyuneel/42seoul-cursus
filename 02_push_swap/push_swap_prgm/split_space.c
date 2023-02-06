/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:12:53 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/05 18:39:29 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_word(char const *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			cnt++;
			while (*s && *s != ' ')
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

int	wrdlen(char const *s)
{
	int	len;

	len = 0;
	while (*s && *s != ' ')
	{
		len++;
		s++;
	}
	return (len);
}

char	**split_space(char const *s)
{
	char	**arr;
	int		idx;
	int		len;

	arr = (char **)malloc(sizeof(char *) * (count_word(s) + 1));
	if (!arr)
		return (NULL);
	idx = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			len = wrdlen(s);
			arr[idx] = (char *)malloc(sizeof(char) * (len + 1));
			if (!arr[idx])
				return (free_arr(arr));
			ft_strncpy(arr[idx++], s, len);
			s += len;
		}
		else
			s++;
	}
	arr[idx] = NULL;
	return (arr);
}
