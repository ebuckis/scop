/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scop.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:16:18 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 14:30:13 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "mlx.h"
# include <stddef.h>
# include <stdio.h>
# include <openGL/gl3.h>
# include "mlx_opengl.h"

/*
** info
*/
char    *get_vertex_shader(void);
char    *get_frag_shader(void);
void    get_version_opengl(void);

GLuint makeShaderProgram(void);

GLuint  make_float_vbo(GLfloat *value, GLsizeiptr size, GLenum vbo_type);

void    draw_triangle(void);
void	display_draw(void);

#endif
