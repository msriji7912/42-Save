/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:45:38 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 13:22:50 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_list
{
	int				content;
	int				index;
	struct t_list	*next;
}					t_list;

/*		Parsing		*/
char				*join_arg(int ac, char *av[]);
int					are_digits(char *str);
int					dups(char *target, char **tab, int index);
char				**prep_stack(int ac, char *av[]);
t_list				*parsing(char **tab);

/*		Put index		*/
void				initialize_index(t_list *stack_a);
t_list				*min_finder(t_list *stack_a);
int					lst_size(t_list *stack_a);

/*		Stack		*/
t_list				*new_node(int nbr);
void				lst_add_back(t_list **lst, t_list *to_add);
t_list				*stack_fill(int *tab, int size);

/*		Errors		*/
void				ft_putstr(char *str);
void				error_msg(void);

/*		Split		*/
int					count_words(const char *str, char c);
int					word_len(const char *str, char c);
void				free_tab(char **tab);
char				**ft_split(char const *str, char c);

/*		Long and range		*/
long				atol(const char *str);
int					is_range(long nbr);

/*		Parsing tools		*/
int					ft_strlen(char *str);
char				*ft_strdup(char *str);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
int					count_tab(char **tab);

/*		Operations		*/
//////////PUSH///////////
void				push(t_list **pushed, t_list **dest);
void				push_a(t_list **stack_a, t_list **stack_b);
void				push_b(t_list **stack_b, t_list **stack_a);

////////REVERSE/////////
void				reverse(t_list **stack);
void				reverse_a(t_list **stack_a);
void				reverse_b(t_list **stack_b);
void				rev_rev(t_list **stack_a, t_list **stack_b);

////////ROTATE//////////
void				rotate(t_list **stack);
void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				rotate_rotate(t_list **stack_a, t_list **stack_b);

/////////SWAP//////////
void				swap(t_list *stack);
void				swap_a(t_list *stack_a);
void				swap_b(t_list *stack_b);
void				swap_both(t_list *stack_a, t_list *stack_b);

#endif