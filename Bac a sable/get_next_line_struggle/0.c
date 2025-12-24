/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:18:42 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/16 08:14:04 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	search_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r;

	while (1)
	{
		r = read (fd, buf, BUFFER_SIZE); // on mets le read dans la boucle to keep reading bro
		if (r == -1) //1_pas negatif ptdrr
		{
			free(*stash); //2_On free et rend null stash pas r mdrr
			*stash == NULL;
			break;
		}
		if (r == 0)
			break;
		buf[r] = '\0'; // 1_r ducou prends une position la?
		if (!*stash)
			*stash = strdup(buf);
		else
		{
			*tmp = ft_strjoin(*stash, buf); //2_revoir les pointeurs de pointeurs
			free(*stash); //on free le stash pour le re-remplir dummy
			*stash = *tmp;
		}
		if (search_n(*stash) != -1) //bien revoir ce que fais search_n et est ce que mettre buf marche aussi?
			break; //juste break pas besoin de rediriger (fonction tool bro)
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
		tmp = ft_strdup(*stash + len + 1); // use exterenal fonctions bruh
		free (*stash);
		*stash = tmp;
		return (line);
	} // cas echeant: line takes stash bc there is just no '\n'
	line = ft_strdup(*stash);
	free(stash);
	*stash = NULL;
	return (line);
} // got lots of help on the other case

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*buf;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL); //forgot the first securite
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	search_line (&stash, buf, tmp, fd)
	//got some help here => needed to secure the result of the search_line
	if (!stash[fd] || stash[fd] == '\0')
	{
		free(stash[fd]);
		stash[fd] == NULL;
		return (NULL);
	}
	line = build_line(&stash[fd]); //link to the stash 
	return (line);
}
