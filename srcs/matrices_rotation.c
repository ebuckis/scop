/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrices_rotation.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 11:10:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 16:29:25 by kcabus      ###    #+. /#+    ###.fr     */
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

static GLfloat     *mat_rot_z(t_draw *draw)
{
	GLfloat		*matrice;
	GLfloat		angle;

	matrice = draw->matrix.z_mat;
	angle = draw->angle.z;
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

GLfloat		*mat_rot_y(t_draw *draw)
{
	GLfloat		*matrice;
	GLfloat		angle;

	matrice = draw->matrix.y_mat;
	angle = draw->angle.y;
	matrice[0] = cos(-angle);
	matrice[2] = sin(-angle);
	matrice[5] = 1.0;
	matrice[8] = -matrice[2];
	matrice[10] = matrice[0];
	matrice[15] = 1.0;
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

static GLfloat		*mat_rot_x(t_draw *draw)
{
	GLfloat		*matrice;
	GLfloat		angle;

	matrice = draw->matrix.x_mat;
	angle = draw->angle.x;
	matrice[0] = 1.0;
	matrice[5] = cos(-angle);
	matrice[9] = sin(-angle);
	matrice[6] = -matrice[9];
	matrice[10] = matrice[5];
	matrice[15] = 1.0;
	return (matrice);
}

int		matrix_init(t_draw *draw)
{
//	display_matrices(mat);
	int 	ret;

	ret = matrice_generate(&(draw->matrix.values));
	ret |= matrice_generate(&(draw->matrix.x_mat));
	ret |= matrice_generate(&(draw->matrix.y_mat));
	ret |= matrice_generate(&(draw->matrix.z_mat));
	ret |= matrice_generate(&(draw->matrix.tmp_mat));

	if (ret)
		return (ret);

	draw->matrix.x_mat = mat_rot_x(draw);
	draw->matrix.y_mat = mat_rot_y(draw);
	draw->matrix.z_mat = mat_rot_z(draw);

	matrice_rot_create(draw);
	return (0);
}


void		matrice_rot_create(t_draw *draw)
{
	GLfloat 	*mat;

	if (draw->axis == 'X')
		draw->matrix.x_mat = mat_rot_x(draw);
	if (draw->axis == 'Y')
		draw->matrix.y_mat = mat_rot_y(draw);
	if (draw->axis == 'Z')
		draw->matrix.z_mat = mat_rot_z(draw);

	mult_matrix(draw->matrix.x_mat, draw->matrix.y_mat, &(draw->matrix.tmp_mat));
	mult_matrix(draw->matrix.tmp_mat, draw->matrix.z_mat, &(draw->matrix.values));
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