/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:18:42 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/16 08:14:58 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	search_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r;

	while (1)
	{
		r = read (fd, buf, BUFFER_SIZE);
		if (r == -1) 
		{
			free(*stash);
			*stash == NULL;
			break;
		}
		if (r == 0)
			break;
		buf[r] = '\0';
		if (!*stash)
			*stash = strdup(buf);
		else
		{
			*tmp = ft_strjoin(*stash, buf);
			free(*stash);
			*stash = *tmp;
		}
		if (search_n(*stash) != -1)
			break;
		}
}

char	*build_line(char **stash)
{
	size_t	len;
	char	*tmp;
	char	*line;

	len = search_n(*stash);
	if (len != -1)
	{
		line = ft_substr(*stash, 0, (len + 1));
		tmp = ft_strdup(*stash + len + 1);
		*stash = tmp;
		return (line);
	}
	line = ft_strdup(*stash);
	free(stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*buf;
	char		*tmp;
	char		*line;

	tmp = NULL 
	if (fd < 0 || BUFFER_SIZE == 0 || fd >= 4096)
		return (NULL); 
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	search_line (&stash, buf, &tmp, fd) //adresse de tmp for him to figure things out 
	free (buf);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = build_line(&stash[fd]); 
	return (line);
}
