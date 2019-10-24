/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   triangle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 10:54:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 15:02:40 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

void	disable_draw(void)
{
	GLuint	vertex_loc = 0;

	glDisableVertexAttribArray(vertex_loc);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void    draw_triangle(void)
{
    float points[] = {.0,  .5,  .0, -.5,  -.5,  .0, .5,  -.5,  .0,
    .0,  .8,  .0, -.5,  .7,  .0, .5,  .7,  .0};
    GLuint vbo = 0;
    GLuint vao = 0;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindVertexArray(vao);


	vbo = make_float_vbo(points, sizeof(points), GL_ARRAY_BUFFER);	

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    makeShaderProgram();

    glDrawArrays(GL_TRIANGLES, 0, 3);
}