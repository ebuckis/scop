/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:35:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 15:22:10 by kcabus      ###    #+. /#+    ###.fr     */
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
	if (!draw->matrix.values)
		return (1);
	matrice_rot_create(draw);
	draw->matrix.loc = glGetUniformLocation(draw->shader.id, "matrix");
	return (0);
}

int		init_vertex(t_draw *draw)	//VBO vertex
{
//CUBE :
	float	v = 0.3;
	float	points[] = {
		+v, +v, +v,	//p0
		+v, -v, +v,	//p1
		-v, -v, +v,	//p2
		-v, +v, +v,	//p3
		+v, +v, -v,	//p4
		+v, -v, -v,	//p5
		-v, -v, -v,	//p6
		-v, +v, -v	//p7
	};

	draw->vbo_vertex.values = (GLfloat *)malloc(sizeof(GLfloat) * 24);
	for (int i = 0; i < 24; i++)
		draw->vbo_vertex.values[i] = points[i];

	draw->vbo_vertex.loc = glGetAttribLocation(draw->shader.id, "glVertex");
	draw->vbo_vertex.size = 24 * sizeof(GLfloat); 


	draw->vbo_vertex.id = make_float_vbo(draw->vbo_vertex.values, draw->vbo_vertex.size, GL_ARRAY_BUFFER);

	return (0);
}

int		init_colors(t_draw *draw)	//VBO colors
{
	GLfloat	colors[] = {
		1.0, 0.0 ,0.0,	//[0] rouge
		0.0, 1.0, 0.0,	//[1] vert
		0.0, 0.0, 1.0,	//[2] bleu
		1.0, 1.0, 0.0,	//[3] jaune
		1.0, 0.0, 1.0,	//[4] magenta
		0.0, 1.0, 1.0,	//[5] cyan
		1.0, 1.0, 1.0,	//[6] blanc
		1.0, 0.5, 0.0	//[7] orange
	};

	draw->vbo_colors.values = (GLfloat *)malloc(sizeof(GLfloat) * 24);
	for (int i = 0; i < 24; i++)
		draw->vbo_colors.values[i] = colors[i];

	draw->vbo_colors.size = 24 * sizeof(GLfloat);
	draw->vbo_colors.loc = glGetAttribLocation(draw->shader.id, "glColor");
	draw->vbo_colors.id = make_float_vbo(draw->vbo_colors.values, draw->vbo_colors.size, GL_ARRAY_BUFFER);
	return (0);
}


int		init_indexes(t_draw *draw)	//VBO_indices
{

	GLshort	index[] = {
		0, 1, 2,
		0, 2, 3,
		0, 1, 5,
		0, 4, 5,
		1, 2, 6,
		1, 5, 6,
		2, 3, 6,
		3, 6, 7,
		0, 3, 7,
		0, 4, 7,
		4, 5, 6,
		4, 6, 7,
	};
	
	draw->vbo_index.values = (GLshort *)malloc(sizeof(GLshort) * 12*3);
	for (int i = 0; i < 36; i++)
		draw->vbo_index.values[i] = index[i];
	draw->vbo_index.size = 36;
	draw->vbo_index.id = make_short_vbo(draw->vbo_index.values, draw->vbo_index.size);
	return (0);
}
