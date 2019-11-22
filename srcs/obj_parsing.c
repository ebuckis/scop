/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   obj_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 11:28:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 14:28:37 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"
//#include "../includes/parsing.h"

int		save_vertex(t_draw *draw, char **tab)
{
	int		i;
	GLfloat	ftab[3];

	i = 1;
	while (tab[i])
	{
		if (i > 2)//TODO: a améliorer
			return (1);
		ftab[i - 1] = (GLfloat)atof(tab[i]);
		i++;
	}
	if (i != 3)
		return (1);
	draw->vbo_vertex.size += 3;
	if (!draw->vbo_vertex.value)
		malloc(draw->vbo_vertex.value, sizeof(GLfloat) * draw->vbo_vertex.size);//TODO: verifier la taille
	else
		realloc(draw->vbo_vertex.value, sizeof(GLfloat) * draw->vbo_vertex.size);
	draw->vbo_vertex.value[draw->vbo_vertex.size - 3] = ftab[0];
	draw->vbo_vertex.value[draw->vbo_vertex.size - 2] = ftab[1];
	draw->vbo_vertex.value[draw->vbo_vertex.size - 1] = ftab[2];
	return (0);
}

int		save_index(t_draw *draw, char **tab)
{
	int		i;
	GLshort	shtab[3];

	i = 1;
	while (tab[i])
	{
		if (i > 2)//TODO: a améliorer
			return (1);
		shtab[i - 1] = (GLshort)itoa(tab[i]);
		if (shtab[i - 1] > draw->vbo_vertex.size)
			return (2);
		i++;
	}
	if (i != 3)
		return (1);
	draw->vbo_index.size += 3;
	if (!draw->vbo_index.value)
		draw->vbo_index.value = (GLfloat *)malloc(draw->vbo_index.value, sizeof(GLfloat) * draw->vbo_index.size);//TODO: verifier la taille
	else
		draw->vbo_index.value = (GLfloat *)realloc(draw->vbo_index.value, sizeof(GLfloat) * draw->vbo_index.size);
	draw->vbo_index.value[draw->vbo_index.size - 3] = shtab[0];
	draw->vbo_index.value[draw->vbo_index.size - 2] = shtab[1];
	draw->vbo_index.value[draw->vbo_index.size - 1] = shtab[2];
	return (0);
}

int		test_utility(char *line)
{
	int	i;

	i = 0;
	while (is_white(line[i]))
		i++;
	if (line[i] && (line[i] == 'f' || line[i] == 'v') && is_white(line[i + 1]))
		return (1);
	return 0;
}

int		save_obj_information(t_draw *draw, char *line)
{
	char	**tab;
	int		i;
	int		ret;

	ret = 1;
	tab = ft_whitespace(line, read);
	if (!strcmp(tab[0], "v"))
		ret = save_vertex(draw, tab);
	else if (!strcmp(tab[0], "f"))
		ret = save_index(draw, tab);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (ret);
}


int     obj_parse(t_draw *draw, char *file_name)
{
	FILE	*fp;
	char 	*line;
	size_t	len;
	inr 	ret;

	line = NULL;
	len = 0;
	fp = fopen(file_name, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while (getline(&line, &len, fp) != -1)
	{
		if (line && test_utility(line))
		{
			ret = save_obj_information(draw, line);
			free(line);
			if (ret)
			{
				printf("parsing, error n%d\n", ret);
				return (ret);
			}
		}
	}
	if (line)
		free(line);
	return (0);
}

/*
int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	obj_parse(NULL, av[1]);
}*/
