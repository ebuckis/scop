/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   triangle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 10:54:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 15:57:19 by kcabus      ###    #+. /#+    ###.fr     */
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

void    draw_triangle(void)
{
	GLuint	loc;
	float	pt = 0.3;
	float	points[] = {
		+0.0, +0.0, +1.0,	//p0
		+0.0, +0.5, +0.5,	//p1
		+0.5, +0.0, -0.9,	//p2
		+0.0, -0.5, +0.1,	//p3
		-0.5, +0.0, +0.3	//p4
	};

	float	colors[] = {
		1.0, 1.0, 0.0,	//jaune
		1.0, 1.0, 0.0,	//jaune
		1.0, 0.5, 0.3,	//orange
		1.0, 1.0, 0.0,	//jaune
		1.0, 0.5, 0.3,	//orange
	};

	GLshort	index[] = {
		0, 1,
		0, 2,
		0, 3,
		0, 4,
		4, 1,
		1, 2,
		2, 3,
		3, 4
	};
	GLuint sh_id, ver_id, frg_id, ind_id;
	create_vao();

	sh_id = makeShaderProgram();

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
	glDrawElements(GL_LINES, 8*2, GL_UNSIGNED_SHORT, 0);
	destruct_vao_vbo();

}