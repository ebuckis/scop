/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   triangle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 10:54:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 09:22:58 by kcabus      ###    #+. /#+    ###.fr     */
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
	GLuint	vertex_loc;
	float	pt = 0.5;
	float	points[] = {
		-pt, +pt, +pt,	//p0
		+pt, -pt, +pt,	//p1
		+pt, +pt, -pt,	//p2

		-pt, +pt, +pt,	//p0
		+pt, -pt, +pt,	//p1
		-pt, -pt, -pt,	//p3

		+pt, -pt, +pt,	//p1
		+pt, +pt, -pt,	//p2
		-pt, -pt, -pt,	//p3

		-pt, +pt, +pt,	//p0
		+pt, +pt, -pt,	//p2
		-pt, -pt, -pt	//p3
	};

/*	float	colors[] = {
		0.0, 0.5, 1.0,	//bleu
		1.0, 0.5, 0.0,	//orange
		0.0, 1.0, 0.0,	//vert

		0.0, 0.5, 1.0,	//bleu
		1.0, 0.5, 0.0,	//orange
		0.7, 0.0, 0.7,	//violet

		1.0, 0.5, 0.0,	//orange
		0.0, 1.0, 0.0,	//vert
		0.7, 0.0, 0.7,	//violet

		0.0, 0.5, 1.0,	//bleu
		0.0, 1.0, 0.0,	//vert
		0.7, 0.0, 0.7	//violet
	};*/

	vertex_loc = 0;
	create_vao();
	make_float_vbo(points, sizeof(points), GL_ARRAY_BUFFER);	
	glVertexAttribPointer(vertex_loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	makeShaderProgram();

	//gestion de la profondeur
	glEnable(GL_DEPTH_TEST);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	destruct_vao_vbo();

}