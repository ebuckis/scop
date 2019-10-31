/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   makeFloatVbo.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 10:52:18 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 16:08:42 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

void	make_float_vbo(GLfloat *values, GLsizeiptr size, GLenum vbo_type)
{
	GLuint	id;

	id = 0;
	glGenBuffers(1, &id);
	glBindBuffer(vbo_type, id);
	glBufferData(vbo_type, size, values, GL_STATIC_DRAW);
	glBindBuffer(vbo_type, id);
}

void	create_vao(void)
{
    GLuint vao = 0;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindVertexArray(vao);
}