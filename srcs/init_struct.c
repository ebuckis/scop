/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:35:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 12:53:12 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

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

int     init_matrix(t_draw *draw)
{
//	display_matrices(mat);

	draw->matrix.values = matrice_generate();
	draw->matrix.x_mat = matrice_generate();
	draw->matrix.y_mat = matrice_generate();
	draw->matrix.z_mat = matrice_generate();
	draw->matrix.tmp_mat = matrice_generate();
	if (!draw->matrix.values)
		return (1);
	matrice_rot_create(draw);
	draw->matrix.loc = glGetUniformLocation(draw->shader.id, "matrix");
	return (0);
}

int		init_vertex(t_draw *draw)	//VBO vertex
{
//CUBE :
	draw->vbo_vertex.loc = glGetAttribLocation(draw->shader.id, "glVertex");


	draw->vbo_vertex.id = make_float_vbo(draw->vbo_vertex.values, draw->vbo_vertex.size, GL_ARRAY_BUFFER);

	return (0);
}

int		init_colors(t_draw *draw)	//VBO colors
{
	draw->vbo_colors.loc = glGetAttribLocation(draw->shader.id, "glColor");
//	draw->vbo_colors.id = make_float_vbo(draw->vbo_colors.values, draw->vbo_colors.size, GL_ARRAY_BUFFER);
	return (0);
}


int		init_indexes(t_draw *draw)	//VBO_indices
{
	draw->vbo_index.id = make_short_vbo(draw->vbo_index.values, draw->vbo_index.size);
	return (0);
}
