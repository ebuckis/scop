/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:35:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 13:35:46 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"


int		init_vertex(t_draw *draw)	//VBO vertex
{
	draw->vbo_vertex.loc = glGetAttribLocation(draw->shader.id, "glVertex");
	draw->vbo_vertex.id = make_float_vbo(draw->vbo_vertex.values, draw->vbo_vertex.size, GL_ARRAY_BUFFER);

	return (0);
}

int		init_colors(t_draw *draw)	//VBO colors
{
	draw->vbo_colors.loc = glGetAttribLocation(draw->shader.id, "glColor");
//	draw->vbo_colors.id = make_float_vbo(draw->vbo_colors.values, draw->vbo_colors.size, GL_ARRAY_BUFFER);
	return (0);
}


int		init_indexes(t_draw *draw)	//VBO_indices
{
	draw->vbo_index.id = make_short_vbo(draw->vbo_index.values, draw->vbo_index.size);
	return (0);
}
