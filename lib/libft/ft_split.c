/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:19 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/07 13:27:50 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_free(char **split, int option)
{
	int	i;

	if (split && option == 1)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			split[i] = NULL;
			i++;
		}
		free(split);
	}
	else if (split && *split && option == 2)
	{
		free(*split);
		*split = NULL;
	}
	split = NULL;
	return (NULL);
}

static char	*ft_create_word(char const *s, char c)
{
	size_t	end;
	char	*word;

	end = 0;
	while (s[end] != c && s[end])
		end++;
	word = ft_substr(s, 0, end);
	if (!word)
		return (NULL);
	return (word);
}

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	split = (char **)ft_calloc((ft_word_counter(s, c) + 1), sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			split[i++] = ft_create_word(s, c);
			if (!split[i - 1])
				return (ft_free(split, 1));
			while (*s != c && *s)
				s++;
		}
	}
	return (split);
}
