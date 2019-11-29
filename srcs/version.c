/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   version.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 11:18:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:22:20 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

char    *get_vertex_shader(void)
{
	return ("#version 400\n\
uniform mat4 matrix_rot;\n\
uniform mat4 matrix_proj;\n\
uniform mat4 matrix_cam;\n\
in vec3 glVertex;\n\
in vec3 glColor;\n\
out vec3 frgColor;\n\
void main()\n\
{\n\
    gl_Position =  matrix_proj * matrix_cam * matrix_rot * vec4(glVertex, 1.0);\n\
	frgColor = glColor;\n\
}\n");
}

char    *get_frag_shader(void)
{
	return ("#version 400\n\
out vec4 glFragColor;\n\
void main()\n\
{\n\
	float col;\n\
	col = (gl_PrimitiveID % 6) / 10.0;\n\
	glFragColor = vec4(col, col, col, 1.0);\n\
}\n");
}
	//glFragColor = vec4(frgColor, 1);\n\


void    get_version_opengl(void)
{
	printf("Graphic Card : %s\n", (char *)glGetString(GL_RENDERER));
	printf("Version : %s\n", (char *)glGetString(GL_VERSION));
	printf("GLSL : %s\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
}
