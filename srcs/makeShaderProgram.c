/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   makeShaderProgram.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 10:45:55 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 14:50:44 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

GLuint makeVertexShader(const GLchar* shaderSource)
{
	GLuint vertexShaderID = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertexShaderID, 1, &shaderSource, NULL );
	glCompileShader( vertexShaderID );
	return vertexShaderID;
}

GLuint makeFragmentShader(const GLchar* shaderSource)
{
	GLuint fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( fragmentShaderID, 1, &shaderSource, NULL );
	glCompileShader( fragmentShaderID );
	return fragmentShaderID;
}

GLuint makeShaderProgram(void)
{
	GLuint		vertexShaderID;
	GLuint		fragmentShaderID;
	GLuint		shaderProgramID;
	const char	*str_shader;
	
	str_shader = get_vertex_shader();
	vertexShaderID = makeVertexShader(str_shader);

	str_shader = get_frag_shader();
	fragmentShaderID = makeFragmentShader(str_shader);

	shaderProgramID = glCreateProgram();
	glAttachShader( shaderProgramID, vertexShaderID );
	glAttachShader( shaderProgramID, fragmentShaderID );
	glLinkProgram( shaderProgramID );
    glUseProgram(shaderProgramID);

	return shaderProgramID;
}
