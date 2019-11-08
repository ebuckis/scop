/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   triangle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 10:54:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 13:05:19 by kcabus      ###    #+. /#+    ###.fr     */
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

void    draw_triangle(t_draw *draw)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	matrice_rot_create(draw);
	display_matrices(draw->matrix.values);

	create_vao();

	make_shader_program(draw);

	//loc = glGetUniformLocation(sh_id, "matrix");
	draw->matrix.loc = glGetUniformLocation(draw->shader.id, "matrix");
    glUniformMatrix4fv(draw->matrix.loc, 1, GL_FALSE, draw->matrix.values);

	glEnable(GL_DEPTH_TEST);
//-----------------------------------------------------------------------------------
	// VBO points
//	ver_id = make_float_vbo(points, sizeof(points), GL_ARRAY_BUFFER);
//	loc = glGetAttribLocation(sh_id, "glVertex");
	draw->vbo_vertex.id = make_float_vbo(draw->vbo_vertex.values, draw->vbo_vertex.size, GL_ARRAY_BUFFER);
	draw->vbo_vertex.loc = glGetAttribLocation(draw->shader.id, "glVertex");
	glEnableVertexAttribArray(draw->vbo_vertex.loc);
	glVertexAttribPointer(draw->vbo_vertex.loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

//-----------------------------------------------------------------------------------
	// VBO colors
	draw->vbo_colors.id = make_float_vbo(draw->vbo_colors.values, draw->vbo_colors.size, GL_ARRAY_BUFFER);
	draw->vbo_colors.loc = glGetAttribLocation(draw->shader.id, "glColor");
	glEnableVertexAttribArray(draw->vbo_colors.loc);
	glVertexAttribPointer(draw->vbo_colors.loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

//-----------------------------------------------------------------------------------
	// VBO indices
	draw->vbo_index.id = make_short_vbo(draw->vbo_index.values, sizeof(draw->vbo_index.values));
//	ind_id = make_short_vbo(index, sizeof(index));
	
//-----------------------------------------------------------------------------------


	//glDrawArrays(GL_TRIANGLES, 0, 3*4);
	glDrawElements(GL_TRIANGLES, 3*12, GL_UNSIGNED_SHORT, 0);
	destruct_vao_vbo();

}