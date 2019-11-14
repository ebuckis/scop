/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   obj_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 11:28:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 13:00:20 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

bool    is_white(char c)
{
	if (c == '\t'  || c == '\n' || c == '\r' 
		||c == '\v' || c == '\f' || c == ' ')
	{
		return (1);
	}
	return (0);
}

char **ft_whitespace(char *line)
{
	int 	i;
	int 	j;
	int		n_word;
	char	**tab;

	i = 0;
	n_word = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i + 1])
	{
		if (!is_white(line[i]) && (is_white(line[i + 1]) || !line[i + 1]))
			n_word++;
		i++;
	}
	if (!n_word)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (n_word + 1));
	i = 0;
	n_word = 0;
	while (line[i])
	{
		j = 0;
		while (line[i + j] && !is_white(line[i + j]))
			j++;
		if (j)
		{
			tab[n_word] = (char *)malloc(sizeof(char) * (j + 1));
			strncpy(tab[n_word], line + i, j + 1);
			tab[n_word][j] = '\0';
			n_word++;
			i += j;
		}
		else
			i++;
	}
	tab[n_word] = NULL;
	return (tab);
}

int     obj_parse(t_draw *draw)
{
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	if (ac < 2)
		return (0);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		printf("%s", line);
	}

	


	if (line)
		free(line);

	return (0);
}