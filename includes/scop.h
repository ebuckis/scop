/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scop.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:16:18 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 09:12:38 by kcabus      ###    #+. /#+    ###.fr     */
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
** Stuctures 
*/

typedef struct		s_vbo
{
	GLuint			id;
	GLuint			loc;
	GLfloat			*values;//short for indexes
}					t_vbo;

typedef	struct		s_shader
{
	GLuint			id;
	GLuint			ver_id;
	GLuint			frag_id;
	char			*ver_str;
	char			*frag_str;
};


typedef struct		s_draw
{
	t_vbo			vbo_pts;
	t_vbo			vbo_colors;
	t_vbo			vbo_index;
	GLuint			vao;
	t_shader		shader;
}					t_draw;





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
