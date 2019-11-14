/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   obj_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 11:28:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 16:08:14 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

bool    is_white(char c)
{
	if (c == '\t'  || c == '\n' || c == '\r' 
		||c == '\v' || c == '\f' || c == ' ')
	{
		return (1);
	}
	return (0);
}

char		**ft_whitespace(char *line, size_t size)
{
	t_parse	prs;
	size_t i;

	prs.len = (size_t *)malloc(sizeof(size_t) * (size + 1));
	prs.start = (size_t *)malloc(sizeof(size_t) * (size + 1));
	for (int j = 0; j < size; j++)
	{
		prs.len[j] = 0;
		prs.start[j] = 0;
	}

	i = 0;
	prs.n = 0;
	if (!line)
		return (NULL);
	while (line[i])
	{
		prs.start[prs.n] = i;
		if (!is_white(line[i]))
		{
			while (line[i] && !is_white(line[i]))
			{
				prs.len[prs.n]++;
				if (!line[i + 1] || is_white(line[i + 1]))
					prs.n++;
				i++;
			}
		}
		else
			i++;
	}
	if (!prs.n)
		return (NULL);
	prs.tab = (char **)malloc(sizeof(char *) * (prs.n + 1));
	i = 0;
	while (i < prs.n)
	{
		prs.tab[i] = (char *)malloc(sizeof(char) * (prs.len[i]));
		strncpy(prs.tab[i], line + prs.start[i], prs.len[i]);
		prs.tab[i][prs.len[i]] = '\0';
		printf("len : %zu && start : %zu -> word : |%s|\n", prs.len[i], prs.start[i], prs.tab[i]);
		i++;
	}
	prs.tab[i] = NULL;
	free(prs.start);
	free(prs.len);
	return (prs.tab);
}

int     obj_parse(t_draw *draw, char *file_name)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **tab;

	fp = fopen(file_name, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		printf("%s", line);
		tab = ft_whitespace(line, read);
		if (tab)
		{
			for (int i = 0; tab[i]; i++)
				printf ("		->|%s|\n", tab[i]);
		}
	}

	if (line)
		free(line);

	return (0);
}
