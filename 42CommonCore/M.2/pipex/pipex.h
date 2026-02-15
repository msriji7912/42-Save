/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:33:33 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/15 15:55:38 by mosriji          ###   ########.fr       */
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

/*       TOOLS         */
//    split
int			count_words(const char *str, char c);
int			word_len(const char *str, char c);
void		free_tab(char **tab);
char		**ft_split(char const *str, char c);

//    utils
int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);

/*       PIPEX        */
// PIPEX UTILS
void		error_exit(char *mess);
char		*find_path(char **cmd, char **envp);
void		exec_enfant_1(char *cmd, char **envp);
void		exec_enfant_2(char *cmd, char **envp);

// PIPEX MOUHAHAH
pid_t		enfant_1(t_pipex *folder, char *av[], char **envp);
pid_t		enfant_2(t_pipex *folder, char *av[], char **envp);
void		parent(t_pipex *folder, pid_t pid1, pid_t pid2);

#endif