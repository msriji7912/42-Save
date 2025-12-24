/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_try.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:36:42 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/16 12:17:40 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	search_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r; // ssize_t => is signed
	
	while (1)
	{
		r = read (fd, buf, BUFFER_SIZE); //don't forget it's **
		if (r == 0) // "!r" also works
			break; // not NULL because there could still be some data left in stash and there is just nothing to read anymore
		if (r == -1)
		{
			free(*stash);
			*stash = NULL; //we free stash since it's a static char so it might still have data to clean
		}
		buf[r] = '\0';
		if (!*stash)
			*stash = ft_strdup(buf);
		else
		{
			*tmp = ft_strjoin(*stash, buf);
			free (*stash);
			*stash = *tmp; // shouldn't free tmp bc *stash now points to the same memory as *tmp 
		}
		if (search_n(*stash) != -1)
			break;
	}
}

char	*build_line(char **stash)
{
	ssize_t	len;
	char	*line;
	char	*tmp;  // no need to use **?

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
    char		*buf; //no need to use ** since here buf is just a local buffer for reading
	static char	*stash; // has to be a static char!
	char		*final_line;

	tmp = NULL; //initialize the tmp !!
	if (fd < 0 || BUFFER_SIZE == 0) //why not '\0' => because buffer_size is a integer
		return (NULL);
	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	search_line (&stash, buf, &tmp, fd);
	free(buf); // not emptying it !
	if (!stash || (*stash == '\0')) //forgot the case of if there is nothing "!stash" 
	{
		free(stash); //at first I just returned NULL for this if but why fo we need to free AND say stash == NULL
		stash = NULL;
		return (NULL);
	}
	final_line = build_line(&stash); //put the adresse since it's not a **
	return (final_line);
} //not bad !