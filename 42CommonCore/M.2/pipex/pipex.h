/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:33:33 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/14 15:24:40 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**paths;
	char	**envp;
	int		pipe_fd[2];
}			t_pipex;

/* Parsing*/
int			parsing(int ac, char *av[]);

/* Utils  */
int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
// split
int			count_words(const char *str, char c);
int			word_len(const char *str, char c);
void		free_tab(char **tab);
char		**ft_split(char const *str, char c);

/*   Errors  */
void		ft_putstr(char *str);
void		arg_err(void);

#endif