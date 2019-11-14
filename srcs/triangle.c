/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   triangle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 10:54:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 09:38:20 by kcabus      ###    #+. /#+    ###.fr     */
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// effacer l'ecran
	glEnable(GL_DEPTH_TEST);	//gestion de la profondeur

	matrice_rot_create(draw);
	glUniformMatrix4fv(draw->matrix.loc, 1, GL_FALSE, draw->matrix.values);

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

	glDrawElements(GL_TRIANGLES, 3*12, GL_UNSIGNED_SHORT, 0);

	destruct_vao_vbo(draw);

}