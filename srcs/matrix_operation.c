/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix_operation.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 11:09:38 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 14:26:06 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

int		matrice_generate(GLfloat **dest)
{
	GLfloat 	*mat;
	unsigned	i;

	i = 0;
	mat = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	if (!mat)
		return (1);
	while (i < 16)
	{
		mat[i] = 0;
		i++;
	}
	*dest = mat;
	return (0);
}

void	mult_matrix(GLfloat *m1, GLfloat *m2, GLfloat **dest)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*dest)[i * 4 + j] = (m1[i * 4 + 0] * m2[j * 4 + 0])
									+ (m1[i * 4 + 1] * m2[j * 4 + 1])
									+ (m1[i * 4 + 2] * m2[j * 4 + 2])
									+ (m1[i * 4 + 3] * m2[j * 4 + 3]);
			j++;
		}
		i++;
	}
}
