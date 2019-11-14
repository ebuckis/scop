/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   makeFloatVbo.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 10:52:18 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 09:28:55 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

GLuint		make_float_vbo(GLfloat *values, GLsizeiptr size, GLenum vbo_type)
{
	GLuint	id;

	id = 0;
	glGenBuffers(1, &id);
	glBindBuffer(vbo_type, id);
	glBufferData(vbo_type, size * sizeof(GLfloat), values, GL_STATIC_DRAW);
	return id;
}

GLuint		make_short_vbo(GLshort *values, GLsizeiptr size)
{
	GLuint	id;

	id = 0;
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLshort), values, GL_STATIC_DRAW);
	return id;
}

void		create_vao(t_draw *draw)
{
    glGenVertexArrays(1, &(draw->vao));
    glBindVertexArray(draw->vao);
}