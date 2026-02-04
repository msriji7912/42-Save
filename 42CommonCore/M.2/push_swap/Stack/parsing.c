/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:33:26 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/04 19:57:26 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//join all my arguments and put them all into a temporary string
char	*join_arg(int ac, char *av[])
{
	int		i;
	char	*tmp_str;
	char	*no_leaks;

	i = 1;
	tmp_str = ft_strdup("");
	while (i < ac)
	{
		no_leaks = tmp_str;
		tmp_str = ft_strjoin(tmp_str, av[i]);
		free(no_leaks);
		no_leaks = tmp_str;
		tmp_str = ft_strjoin(tmp_str, " ");
		free(no_leaks);
		i++;
	}
	return (tmp_str);
}

int are_digits(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/*
Free temporary stuff (joined string, split tab)
*/

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int dups(char *target, char **tab , int index)
{
	int i;

	i = 1;
	while (tab[index + i])
	{
		if (!ft_strcmp(target, tab[index + i]))
			return (1);
		i++;
	}
	return (0);
}

int is_range(long nbr)
{
	if (nbr > 2147483647)
		return (1);
	else if (nbr < -2147483648)
		return (1);
	else
		return(0);
}

void print_list(t_list *stack_a)
{
	t_list *current;
	
	current = stack_a;
	while (current->next != NULL)
	{
		printf("%d", current->content);
		current = current->next;
	}	
	
}

int parsing(int ac, char *av[])
{
	int i;
	int size;
	long nbr;
	char **tab;
	int *final_tab;
	char *tmp_str;
	t_list *stack_a;
	
	i = 0;
	stack_a = NULL;
	tmp_str = join_arg(ac, av);
	size = count_words(tmp_str, " ");
	tab = ft_split (tmp_str, " ");
	final_tab = malloc(sizeof(int)*size);
	if (!final_tab)
		return (0);
	while (tab[i])
	{
		if (are_digits(tab[i]))
			return (1);
		else if (dups(tab[i], tab, i))
			return (1);
		nbr = atol(tab[i]);          
		if (is_range(nbr))
			return (1);
		final_tab[i] = (int)nbr;
		i++;
	}
	stack_a = stack_fill(final_tab, size);
	print_list(stack_a);
	return (0);
}


int main(int ac, char *av[])
{
	parsing(ac, av);
	return (0);
}