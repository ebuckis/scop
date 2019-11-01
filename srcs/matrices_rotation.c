/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrices_rotation.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 11:10:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 14:45:39 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

/*
** Matrice de rotation 4x4 sur Z :
** 
** | cos(-a)|-sin(-a)|   0    |   0    |
** | sin(-a)| cos(-a)|   0    |   0    |
** |   0    |   0    |   1    |   0    |
** |   0    |   0    |   0    |   1    |
** 
*/

static GLfloat     *mat_rot_z(GLfloat *matrice, float angle)
{
	matrice[0] = cos(-angle);
	matrice[4] = sin(-angle);
	matrice[1] = -matrice[4];
	matrice[5] = matrice[0];
	matrice[10] = 1;
	matrice[15] = 1;
	return (matrice);
}

/*
** Matrice de rotation 4x4 sur Y :
** 
** | cos(-a)|   0    | sin(-a)|   0    |
** |   0    |   1    |   0    |   0    |
** |-sin(-a)|   0    | cos(-a)|   0    |
** |   0    |   0    |   0    |   1    |
** 
*/

static GLfloat		*mat_rot_y(GLfloat *matrice, float angle)
{
	matrice[0] = cos(-angle);
	matrice[2] = sin(-angle);
	matrice[5] = 1;
	matrice[8] = -matrice[2];
	matrice[10] = matrice[0];
	matrice[15] = 1;
	return (matrice);
}

/*
** Matrice de rotation 4x4 sur X :
** 
** |   1    |   0    |   0    |   0    |
** |   0    | cos(-a)|-sin(-a)|   0    |
** |   0    | sin(-a)| cos(-a)|   0    |
** |   0    |   0    |   0    |   1    |
** 
*/

static GLfloat		*mat_rot_x(GLfloat *matrice, float angle)
{
	matrice[0] = 1.0;
	matrice[5] = cos(-angle);
	matrice[9] = sin(-angle);
	matrice[6] = -matrice[9];
	matrice[10] = matrice[5];
	matrice[15] = 1.0;
	return (matrice);
}

static GLfloat		*matrice_generate(void)
{
	GLfloat 	*mat;
	unsigned	i;

	i = 0;
	mat = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	if (!mat)
		return (NULL);
	while (i < 16)
	{
		mat[i] = 0;
		i++;
	}
	return (mat);
}

GLfloat		*matrice_rot_create(float angle, char axis)
{
	GLfloat 	*mat;

	mat = matrice_generate();
	if (!mat)
		return (NULL);
	if (axis == 'X')
		return (mat_rot_x(mat, angle));
	else if (axis == 'Y')
		return (mat_rot_y(mat, angle));
	else if (axis == 'Z')
		return (mat_rot_z(mat, angle));
	else
		return (NULL);
}

void	display_matrices(GLfloat *mat)
{
	int i = 0;
	int j;

	while (i < 4)
	{
		j = 0;
		printf("|");
		while (j < 4)
		{
			printf(" %f |", mat[(i*4) + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}