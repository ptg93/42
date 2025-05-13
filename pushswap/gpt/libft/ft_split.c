/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <ptraba-d@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:38:14 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/01/13 15:44:00 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split, size_t word_idx)
{
	while (word_idx > 0)
	{
		free(split[word_idx - 1]);
		word_idx--;
	}
	free(split);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*extract_word(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	split_words(char const *s, char c, char **split, size_t word_count)
{
	size_t	i;
	size_t	start;
	size_t	word_idx;

	i = 0;
	word_idx = 0;
	while (s[i] != '\0' && word_idx < word_count)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			split[word_idx] = extract_word(s, start, i + 1);
			if (!split[word_idx])
			{
				free_split(split, word_idx);
				return (0);
			}
			word_idx++;
		}
		i ++;
	}
	split[word_idx] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!split_words(s, c, split, word_count))
		return (NULL);
	return (split);
}
