/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:40:46 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/16 08:17:18 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	find_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r;

	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(*stash);
			*stash = NULL;
			break ;
		}
		buf[r] = '\0';
		if (r == 0)
			break ;
		if (!*stash)
			*stash = ft_strdup(buf);
		else
		{
			*tmp = ft_strjoin(*stash, buf);
			free(*stash);
			*stash = *tmp;
		}
		if (search_n(*stash) != -1)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	tmp = NULL;
	find_line(&stash, buf, &tmp, fd);
	free(buf);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line_from_stash(&stash);
	return (line);
}

char	*extract_line_from_stash(char **stash)
{
	int		len;
	char	*line;
	char	*tmp;

	len = search_n(*stash);
	if (len != -1)
	{
		line = ft_substr(*stash, 0, len + 1);
		tmp = ft_strdup(*stash + len + 1);
		free(*stash);
		*stash = tmp;
		return (line);
	}
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}
/*
int main(int ac, char **av)
{
    int     fd;
    char    *line;

    if (ac != 2)
    {
        printf("Usage: %s <file>\n", av[0]);
        return (1);
    }

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
*/