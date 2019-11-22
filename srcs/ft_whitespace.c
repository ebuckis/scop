/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_whitespace.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 08:36:17 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 08:52:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/parsing.h"

static bool		is_white(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static int		parse_init(t_parse *prs, size_t size)
{
	int     j;

	prs->len = (size_t *)malloc(sizeof(size_t) * (size + 1));
	prs->start = (size_t *)malloc(sizeof(size_t) * (size + 1));
	j = 0;
	while (j < size)
	{
		prs->len[j] = 0;
		prs->start[j] = 0;
		j++;
	}
	prs->n = 0;
	return (0);
}

static int		fill_parse_table(t_parse *prs, char *line, size_t i)
{
	prs->tab = (char **)malloc(sizeof(char *) * (prs->n + 1));
	if (!prs->tab)
		return (NULL);
	i = 0;
	while (i < prs->n)
	{
		prs->tab[i] = (char *)malloc(sizeof(char) * (prs->len[i]));
		if (!prs->tab[i])
			return (NULL);
		strncpy(prs->tab[i], line + prs->start[i], prs->len[i]);
		prs->tab[i][prs->len[i]] = '\0';
//		printf("len : %zu && start : %zu -> word : |%s|\n", prs.len[i], prs.start[i], prs.tab[i]);
		i++;
	}
	prs->tab[i] = NULL;
	free(prs->start);
	free(prs->len);
	return (prs->tab);
}

char		**ft_whitespace(char *line, size_t size)
{
	t_parse	prs;
	size_t i;

	if (!line || parse_init(&prs, size)))
		return (NULL);
	i = 0;
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
	return (fill_parse_table(&prs, line, i));
}