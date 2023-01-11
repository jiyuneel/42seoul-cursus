/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:46:23 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/01/11 14:46:00 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_list.h"

static char	*free_node(t_list *node, t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	if (node == *head)
		*head = node->next;
	else
	{
		while (tmp->next && tmp->next != node)
			tmp = tmp->next;
		tmp->next = node->next;
	}
	free(node->backup);
	free(node);
	return (NULL);
}

static char	*read_line(t_list *node)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	ssize_t	read_byte;

	while (!ft_strchr(node->backup, '\n'))
	{
		read_byte = read(node->fd, buff, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		buff[read_byte] = 0;
		if (!node->backup)
			node->backup = ft_strdup("");
		tmp = node->backup;
		node->backup = ft_strjoin(node->backup, buff);
		free(tmp);
		if (!node->backup)
			return (NULL);
	}
	if (read_byte < 0)
		return (NULL);
	return (node->backup);
}

static char	*split_line(t_list *node, t_list **head, size_t i)
{
	char	*line;
	char	*tmp;

	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free_node(node, head));
	ft_strlcpy(line, node->backup, i + 1);
	tmp = node->backup;
	node->backup = ft_strdup(&node->backup[i]);
	free(tmp);
	if (!node->backup)
	{
		free(line);
		return (free_node(node, head));
	}
	if (!node->backup[0])
		free_node(node, head);
	return (line);
}

static t_list	*find_node(int fd, t_list **head)
{
	t_list	*tmp;

	if (!*head)
		*head = ft_lstnew(fd);
	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (!tmp->next)
			tmp->next = ft_lstnew(fd);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;
	size_t			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_node(fd, &head);
	if (!node)
		return (NULL);
	if (!read_line(node))
		return (free_node(node, &head));
	i = 0;
	while (node->backup[i] && node->backup[i] != '\n')
		i++;
	if (node->backup[i] == '\n')
		return (split_line(node, &head, i + 1));
	else
	{
		line = ft_strdup(node->backup);
		free_node(node, &head);
		if (!line)
			return (NULL);
		return (line);
	}
}
