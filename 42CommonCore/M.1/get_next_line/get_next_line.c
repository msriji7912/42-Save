/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:40:37 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/17 08:21:28 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	search_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r;

	while (1)
	{
		r = read (fd, buf, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r == -1)
		{
			free(*stash);
			*stash = NULL;
			break ;
		}
		buf[r] = '\0';
		if (!*stash)
			*stash = ft_strdup(buf);
		else
		{
			*tmp = ft_strjoin(*stash, buf);
			free (*stash);
			*stash = *tmp;
		}
		if (search_n(*stash) != -1)
			break ;
	}
}

char	*build_line(char **stash)
{
	ssize_t	len;
	char	*line;
	char	*tmp;

	len = search_n(*stash);
	if (len != -1)
	{
		line = ft_substr(*stash, 0, (len + 1));
		tmp = ft_strdup(*stash + len + 1);
		free (*stash);
		*stash = tmp;
		return (line);
	}
	line = ft_strdup (*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	static char	*stash;
	char		*final_line;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	search_line (&stash, buf, &tmp, fd);
	free(buf);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	final_line = build_line(&stash);
	return (final_line);
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/