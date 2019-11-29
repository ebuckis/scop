/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   obj_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 11:28:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:23:18 by kcabus      ###    #+. /#+    ###.fr     */
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
		if (i > 3)//TODO: a améliorer
			return (1);
		ftab[i - 1] = (GLfloat)atof(tab[i]);
		i++;
	}
//	printf("-+-+->fl0 %f\n", ftab[0]);
//	printf("-+-+->fl1 %f\n", ftab[1]);
//	printf("-+-+->fl2 %f\n", ftab[2]);

	if (i != 4)
		return (1);
	draw->vbo_vertex.size += 3;
	if (!draw->vbo_vertex.values)
		draw->vbo_vertex.values = malloc(sizeof(GLfloat) * draw->vbo_vertex.size);//TODO: verifier la taille
	else
		draw->vbo_vertex.values = realloc(draw->vbo_vertex.values, sizeof(GLfloat) * draw->vbo_vertex.size);
	draw->vbo_vertex.values[draw->vbo_vertex.size - 3] = ftab[0] / 4;
	draw->vbo_vertex.values[draw->vbo_vertex.size - 2] = ftab[1] / 4;
	draw->vbo_vertex.values[draw->vbo_vertex.size - 1] = ftab[2] / 4;
	return (0);
}

int		save_index(t_draw *draw, char **tab)
{
	int		i;

	i = 1;
	if (!(tab[i] && tab[i + 1] && tab[i + 2]))
		return (1);
	while (tab[i] && tab[i + 1] && tab[i + 2])
	{
		draw->vbo_index.size += 3;
		if (!draw->vbo_index.values)
			draw->vbo_index.values = (GLshort *)malloc(sizeof(GLshort) * draw->vbo_index.size);//TODO: verifier la taille
		else
			draw->vbo_index.values = (GLshort *)realloc(draw->vbo_index.values, sizeof(GLshort) * draw->vbo_index.size);
		draw->vbo_index.values[draw->vbo_index.size - 3] = (GLshort)atoi(tab[1]) - 1;
		draw->vbo_index.values[draw->vbo_index.size - 2] = (GLshort)atoi(tab[i + 1]) - 1;
		draw->vbo_index.values[draw->vbo_index.size - 1] = (GLshort)atoi(tab[i + 2]) - 1;
		i++;
	}
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

int		save_obj_information(t_draw *draw, char *line, int len)
{
	char	**tab;
	int		i;
	int		ret;

	ret = 1;
	if (!(tab = ft_whitespace(line, len)))
		return (ret);
	if (!strcmp(tab[0], "v"))
		ret = save_vertex(draw, tab);
	else if (!strcmp(tab[0], "f"))
		ret = save_index(draw, tab);
	i = 0;
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
	int 	ret;
	int		read;

	line = NULL;
	len = 0;
	fp = fopen(file_name, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line && test_utility(line))
		{

			ret = save_obj_information(draw, line, read);
			free(line);
			line = NULL;
			if (ret)
			{
				printf("parsing, error n%d\n", ret);
				return (ret);
			}
		}
	}
	return (0);
}

/*
int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	obj_parse(NULL, av[1]);
}*/
