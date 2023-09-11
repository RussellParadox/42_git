/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:02:15 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/10 12:42:15 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//return the size of the first word in arg, if single_quote worth 0 it return the word size without the single quote count, else with
static int	word_size(char *arg, int single_quote)
{
	int	size;
	int	quote_count;

	if (single_quote != 0)
		single_quote = 1;
	size = 0;
	quote_count = 0;
	while (arg[size] != '\0' && arg[size] != ' ')
	{
		if (arg[size] == '\'')
		{
			quote_count++;
			size++;
			while (arg[size] != '\0' && arg[size] != '\'')
				size++;
			if (arg[size] == '\'')
				quote_count++;
		}
		size++;
	}
	return (size - quote_count * !single_quote);
}

static int	word_count(char *arg)
{
	int	count;

	count = 0;
	while (*arg != '\0' && *arg == ' ')
		arg++;
	while (*arg != '\0')
	{
		arg += word_size(arg, 1);
		while (*arg != '\0' && *arg == ' ')
			arg++;
		count++;
	}
	return (count);
}

static char	*next_word(char *arg, int *start)
{
	char	*word;
	int		quoted_size;
	int		size;
	int		i;
	int		j;

	while (arg[*start] != '\0' && arg[*start] == ' ')
		(*start)++;
	size = word_size(arg + *start, 0);
	word = (char *)sec_alloc(malloc(sizeof(char) * (size + 1)), 0);
	if (word == NULL)
		return (NULL);
	quoted_size = word_size(arg + *start, 1);
	i = 0;
	j = 0;
	while (i < quoted_size)
	{
		if (arg[*start + i] != '\'')
		{
			word[j] = arg[*start + i];
			j++;
		}
		i++;
	}
	word[size] = '\0';
	*start += quoted_size;
	return (word);
}

static char	**split_exit(char **split, int done)
{
	int	i;

	i = 0;
	while (i < done)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

//split with space as character, but escape spaces between ' and '
char	**split_arg(char *arg)
{
	char	**split;
	int		count;
	int		next_start;
	int		i;

	next_start = 0;
	count = word_count(arg);
	split = (char **)sec_alloc(malloc(sizeof(char *) * (count + 1)), 0);
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		split[i] = next_word(arg, &next_start);
		if (split[i] == NULL)
			return (NULL);
		i++;
	}
	split[count] = NULL;
	return (split);
}
