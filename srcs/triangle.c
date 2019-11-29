/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   triangle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 10:54:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 16:33:14 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

void	destruct_vao_vbo(t_draw *draw)
{
	glDisableVertexAttribArray(draw->vbo_vertex.loc);//vertex
	glDisableVertexAttribArray(draw->vbo_colors.loc);//colors
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void    draw_triangle(t_draw *draw)
{
	glEnable(GL_DEPTH_TEST);	//gestion de la profondeur
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// effacer l'ecran
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_FRONT);
//	glFrontFace(GL_CW);  
	
	matrice_rot_create(draw);
	//display_matrices(draw->proj.mat);

	draw->matrix.loc = glGetUniformLocation(draw->shader.id, "matrix_rot");
	glUniformMatrix4fv(draw->matrix.loc, 1, GL_FALSE, draw->matrix.values);
	draw->cam.loc = glGetUniformLocation(draw->shader.id, "matrix_cam");
	glUniformMatrix4fv(draw->cam.loc, 1, GL_FALSE, draw->cam.look_at);
	draw->proj.loc = glGetUniformLocation(draw->shader.id, "matrix_proj");
	glUniformMatrix4fv(draw->proj.loc, 1, GL_FALSE, draw->proj.mat);

	create_vao(draw);
	// VBO points
	glBindBuffer(GL_ARRAY_BUFFER, draw->vbo_vertex.id);
	glEnableVertexAttribArray(draw->vbo_vertex.loc);
	glVertexAttribPointer(draw->vbo_vertex.loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	// VBO colors
	glBindBuffer(GL_ARRAY_BUFFER, draw->vbo_colors.id);
	glEnableVertexAttribArray(draw->vbo_colors.loc);
	glVertexAttribPointer(draw->vbo_colors.loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	// VBO indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, draw->vbo_index.id);

	glDrawElements(GL_TRIANGLES, draw->vbo_index.size, GL_UNSIGNED_SHORT, 0);

	destruct_vao_vbo(draw);

}