/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   makeShaderProgram.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 10:45:55 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 12:57:02 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

GLuint make_ver_shader(const GLchar* shaderSource)
{
	GLuint vertexShaderID = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertexShaderID, 1, &shaderSource, NULL );
	glCompileShader( vertexShaderID );
	return vertexShaderID;
}

GLuint make_frag_shader(const GLchar* shaderSource)
{
	GLuint fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( fragmentShaderID, 1, &shaderSource, NULL );
	glCompileShader( fragmentShaderID );
	return fragmentShaderID;
}

void make_shader_program(t_draw *draw)
{
	draw->shader.ver_id = make_ver_shader(draw->shader.ver_str);

	draw->shader.frag_id = make_frag_shader(draw->shader.frag_str);

	draw->shader.id = glCreateProgram();
	glAttachShader( draw->shader.id, draw->shader.ver_id );
	glAttachShader( draw->shader.id, draw->shader.frag_id );
	glLinkProgram( draw->shader.id );
    glUseProgram(draw->shader.id);
}

//glGetAttribLocation