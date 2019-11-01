/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scop.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:16:18 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 14:46:54 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "mlx.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <openGL/gl3.h>
# include "mlx_opengl.h"
# include <math.h>

/*
** info
*/
char    *get_vertex_shader(void);
char    *get_frag_shader(void);
void    get_version_opengl(void);

GLuint	makeShaderProgram(void);

GLuint	make_float_vbo(GLfloat *values, GLsizeiptr size, GLenum vbo_type);
GLuint	make_short_vbo(GLshort *values, GLsizeiptr size);
void	create_vao(void);

void    draw_triangle(char c);

GLfloat		*matrice_rot_create(float angle, char axis);
float       increm_angle(int inc);
void    	display_matrices(GLfloat *mat);

#endif
