/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 12:00:16 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 12:49:15 by kcabus      ###    #+. /#+    ###.fr     */
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
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    GLuint shaderProgramID;

    vertexShaderID = makeVertexShader(get_vertex_shader());
    fragmentShaderID = makeFragmentShader(get_frag_shader());
    shaderProgramID = makeShaderProgram(vertexShaderID, fragmentShaderID);
    glUseProgram(shaderProgramID);
}
