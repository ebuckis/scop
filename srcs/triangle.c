/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   triangle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 10:54:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 15:24:41 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

void	destruct_vao_vbo(void)
{
	glDisableVertexAttribArray(0);//vertex_loc
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void    draw_triangle(char c)
{
	GLuint	loc;
	float	pt = 0.3;
	float	points[] = {
		+0.0, +0.0, +1.0,	//p0
		+0.0, +0.5, +0.0,	//p1
		+0.5, +0.0, +0.0,	//p2
		+0.0, -0.5, +0.0,	//p3
		-0.5, +0.0, +0.0	//p4
	};

	float	colors[] = {
		0.0, 0.5, 1.0,	//bleu
		1.0, 0.5, 0.0,	//orange
		0.0, 1.0, 0.0,	//vert
		0.7, 0.0, 0.7,	//violet
		1.0, 1.0, 1.0	//blanc
	};

	GLshort	index[] = {
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 1
	};

	GLuint sh_id, ver_id, frg_id, ind_id;
	GLfloat 	*mat;
	static float angle = 0;
	angle += M_PI /50;

	mat = matrice_rot_create(angle, c);
	display_matrices(mat);
// effacer l'ecran
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// creer matrice de rotation


	create_vao();

	sh_id = makeShaderProgram();

	loc = glGetUniformLocation(sh_id, "matrix");
	glUniformMatrix4fv(loc, 1, GL_FALSE, mat);//malloc pas free



	glEnable(GL_DEPTH_TEST);
	// VBO points
	ver_id = make_float_vbo(points, sizeof(points), GL_ARRAY_BUFFER);
	loc = glGetAttribLocation(sh_id, "glVertex");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	// VBO colors
	frg_id = make_float_vbo(colors, sizeof(colors), GL_ARRAY_BUFFER);
	loc = glGetAttribLocation(sh_id, "glColor");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	// VBO indices
	ind_id = make_short_vbo(index, sizeof(index));
	


	//gestion de la profondeur
	//glDrawArrays(GL_TRIANGLES, 0, 3*4);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_SHORT, 0);
	destruct_vao_vbo();

}