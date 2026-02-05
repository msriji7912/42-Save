/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:33:26 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 12:53:12 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (i < ac - 1)
		{
			no_leaks = tmp_str;
			tmp_str = ft_strjoin(tmp_str, " ");
			free(no_leaks);
		}
		i++;
	}
	return (tmp_str);
}

int	are_digits(char *str)
{
	int	i;

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

int	dups(char *target, char **tab, int index)
{
	int	i;

	i = 1;
	while (tab[index + i])
	{
		if (!ft_strcmp(target, tab[index + i]))
			return (1);
		i++;
	}
	return (0);
}

char	**prep_stack(int ac, char *av[])
{
	char	*tmp_str;
	char	**tab;

	tmp_str = join_arg(ac, av);
	tab = ft_split(tmp_str, ' ');
	if (!tab)
		return (NULL);
	free(tmp_str);
	return (tab);
}

t_list	*parsing(char **tab)
{
	int		i;
	long	nbr;
	int		size;
	int		*final_tab;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	size = count_tab(tab);
	final_tab = malloc(sizeof(int) * size);
	if (!final_tab)
		return (NULL);
	while (tab[i])
	{
		if (are_digits(tab[i]) || dups(tab[i], tab, i))
			return (error_msg(), free_tab(tab), free(final_tab), NULL);
		nbr = atol(tab[i]);
		if (is_range(nbr))
			return (error_msg(), free_tab(tab), free(final_tab), NULL);
		final_tab[i++] = (int)nbr;
	}
	stack_a = stack_fill(final_tab, size);
	free(final_tab);
	free_tab(tab);
	return (stack_a);
}
