/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:57:56 by hece              #+#    #+#             */
/*   Updated: 2023/04/30 20:59:44 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef	struct	s_int_values
{
	short	index;
	short	layer;
	short	size;
	short	len;
}				t_int_values;

static inline size_t
	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static inline void
	ft_init_int_value(t_int_values *int_values, char **result, char *s)
{
	int_values->index = 0;
	int_values->layer = 0;
	int_values->size = ft_strlen(s);
	*result = (char *)malloc(sizeof(char) * (int_values->size + 1));
	int_values->size--;
	int_values->len = int_values->size;
}

char
	*reverseWords(char *s)
{
	t_int_values	int_values;
	char			*result;

	ft_init_int_value(&int_values, &result, s);
	while (int_values.len >= 0)
	{
		while (int_values.len >= 0 && s[int_values.len] == ' ')
			int_values.len--;
		while (int_values.len >= 0 && s[int_values.len] != ' '
			&& ++(int_values.index))
			int_values.len--;
		int_values.size = int_values.len + 1;
		while (--(int_values.index) >= 0)
			result[int_values.layer++] = s[int_values.size++];
		result[int_values.layer++] = ' ';
		int_values.index = 0;
	}
	if (result[int_values.layer - 2] == ' ')
		result[int_values.layer - 2] = '\0';
	result[int_values.layer - 1] = '\0';
	return (result);
}

int
	main(void)
{
	char    *str = strdup("hasan kemal ece");
	char    *res = reverseWords(str);
	
	printf("%s\n", res);
	return (0);
}
