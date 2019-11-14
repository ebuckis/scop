/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scop.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:16:18 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 12:59:27 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "mlx.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <openGL/gl3.h>
# include "mlx_opengl.h"
# include <math.h>

# define HEIGHT_WIN	1000
# define WIDTH_WIN	1000
/*
** Stuctures 
*/


typedef struct		s_matrix
{
	GLfloat 		*values;
	GLuint			loc;
}					t_matrix;

typedef	struct		s_index
{
	GLuint			id;
	size_t			size;
	GLshort		 	*values;
}					t_index;

typedef struct		s_vbo
{
	size_t			size;
	GLuint			id;
	GLuint			loc;
	GLfloat			*values;//short for indexes
}					t_vbo;

typedef	struct		s_angle
{
	GLfloat			x;
	GLfloat			y;
	GLfloat			z;
}					t_angle;

typedef	struct		s_shader
{
	GLuint			id;
	GLuint			ver_id;
	GLuint			frag_id;
	char			*ver_str;
	char			*frag_str;
}					t_shader;

typedef struct		s_norm
{
	size_t			size;
	GLfloat			*values;
}					t_norm;


typedef struct		s_draw
{
	void			*init;
	void			*win;
	GLuint			vao;
	t_vbo			vbo_vertex;
	t_vbo			vbo_colors;
	t_index			vbo_index;
	t_shader		shader;
	char			axis;
	t_angle			angle;
	t_matrix		matrix;
	t_norm			normal;
}					t_draw;





/*
** info
*/

int			init_matrix(t_draw *draw);
int			init_vertex(t_draw *draw);	//VBO vertex
int			init_colors(t_draw *draw);	//VBO colors
int			init_indexes(t_draw *draw);

char		*get_vertex_shader(void);
char		*get_frag_shader(void);
void		get_version_opengl(void);

void 		make_shader_program(t_draw *draw);

GLuint		make_float_vbo(GLfloat *values, GLsizeiptr size, GLenum vbo_type);
GLuint		make_short_vbo(GLshort *values, GLsizeiptr size);
void		create_vao(t_draw *draw);

void	    draw_triangle(t_draw *draw);

GLfloat		*matrice_rot_create(t_draw *draw);
void    	display_matrices(GLfloat *mat);
void		destruct_vao_vbo(t_draw *draw);

#endif
