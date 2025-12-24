/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:21:14 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/16 11:58:53 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ---------- GNL ------------ */
void	search_line(char **stash, char *buf, char **tmp, int fd);
char	*build_line(char **stash);
char	*get_next_line(int fd);

/* ---------- UTILS ---------- */
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s);
long	search_n(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
