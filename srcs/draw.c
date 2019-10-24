/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 12:00:16 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 16:22:16 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/scop.h"

GLuint makeVertexShader(const char* shaderSource)
{
	GLuint vertexShaderID = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertexShaderID, 1, (const GLchar**)&shaderSource, NULL );
	glCompileShader( vertexShaderID );
	return vertexShaderID;
}

GLuint makeFragmentShader(const char* shaderSource)
{
	GLuint fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( fragmentShaderID, 1, (const GLchar**)&shaderSource, NULL );
	glCompileShader( fragmentShaderID );
	return fragmentShaderID;
}

GLuint makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
{
	GLuint shaderProgramID = glCreateProgram();
	glAttachShader( shaderProgramID, vertexShaderID );
	glAttachShader( shaderProgramID, fragmentShaderID );
	glLinkProgram( shaderProgramID );
	return shaderProgramID;
}

void    draw_triangle(void)
{
/*	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	GLuint shaderProgramID;
	GLuint vertexBufferID;

	vertexBufferID = makeFloatVBO(ft_get_coord_triangle(), GL_ARRAY_BUFFER, GL_STATIC_DRAW);

	GLuint  vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	vertexShaderID = makeVertexShader(get_vertex_shader());

	fragmentShaderID = makeFragmentShader(get_frag_shader());

	shaderProgramID = makeShaderProgram(vertexShaderID, fragmentShaderID);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderProgramID);
	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 3);*/


    float points[] = {.0,  .5,  .0, -.5,  -.5,  .0, .5,  -.5,  .0,
    .0,  .8,  .0, -.5,  .7,  .0, .5,  .7,  .0};
    GLuint vbo = 0;
    GLuint vao = 0;
    const char* vertex_shader =
        "#version 400\n"
        "in vec3 vp;"
        "void main() {"
        "  gl_Position = vec4(vp, 1.0);"
        "}";
    const char* fragment_shader =
        "#version 400\n"
        "out vec4 frag_colour;"
        "void main() {"
        "  frag_colour = vec4(1, 1, 1, 1);"
        "}";
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);
    GLuint shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shader_programme);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 3, 3);



}