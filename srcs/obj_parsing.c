/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   obj_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 11:28:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 10:23:59 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//#include "parsing.h"
#include "../includes/parsing.h"

int		obj_creation()
{
	
}


int     obj_parse(t_draw *draw, char *file_name)
{
	FILE	*fp;
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

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	obj_parse(NULL, av[1]);
}
