/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:50:00 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/01/07 16:50:00 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*copy_without_quotes(char *str, int start, int len);

static void	skip_spaces(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}

static void	skip_arg(char *str, int *i)
{
	int	in_quotes;

	in_quotes = 0;
	while (str[*i] && (str[*i] != ' ' || in_quotes))
	{
		if (str[*i] == '\'' && !in_quotes)
			in_quotes = 1;
		else if (str[*i] == '\'' && in_quotes)
			in_quotes = 0;
		(*i)++;
	}
}

static int	count_args(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		skip_spaces(str, &i);
		if (str[i])
		{
			count++;
			skip_arg(str, &i);
		}
	}
	return (count);
}

static char	*extract_arg(char *str, int *pos)
{
	int		start;
	int		len;
	int		in_quotes;
	char	*arg;

	while (str[*pos] && str[*pos] == ' ')
		(*pos)++;
	start = *pos;
	in_quotes = 0;
	len = 0;
	while (str[*pos] && (str[*pos] != ' ' || in_quotes))
	{
		if (str[*pos] == '\'' && !in_quotes)
			in_quotes = 1;
		else if (str[*pos] == '\'' && in_quotes)
			in_quotes = 0;
		else
			len++;
		(*pos)++;
	}
	arg = malloc(len + 1);
	if (!arg)
		return (NULL);
	return (copy_without_quotes(str, start, len));
}

static char	*copy_without_quotes(char *str, int start, int len)
{
	char	*result;
	int		i;
	int		j;
	int		in_quotes;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = start;
	j = 0;
	in_quotes = 0;
	while (j < len)
	{
		if (str[i] == '\'' && !in_quotes)
			in_quotes = 1;
		else if (str[i] == '\'' && in_quotes)
			in_quotes = 0;
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	**ft_split_quotes(char *str)
{
	char	**result;
	int		argc;
	int		pos;
	int		i;

	if (!str)
		return (NULL);
	argc = count_args(str);
	result = malloc(sizeof(char *) * (argc + 1));
	if (!result)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < argc)
	{
		result[i] = extract_arg(str, &pos);
		if (!result[i])
		{
			ft_free_split(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
