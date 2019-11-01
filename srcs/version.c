/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   version.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 11:18:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 10:20:57 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

char    *get_vertex_shader(void)
{
	return ("#version 400\n\
in vec3 glVertex;\n\
in vec3 glColor;\n\
out vec3 frgColor;\n\
void main()\n\
{\n\
    vec3 position = glVertex;\n\
    gl_Position = vec4(position, 1.0);\n\
	frgColor = glColor;\n\
}\n");
}

char    *get_frag_shader(void)
{
	return ("#version 400\n\
in vec3 frgColor;\n\
out vec4 glFragColor;\n\
void main()\n\
{\n\
	glFragColor = vec4(frgColor, 1);\n\
}\n");
}




void    get_version_opengl(void)
{
	printf("Graphic Card : %s\n", (char *)glGetString(GL_RENDERER));
	printf("Version : %s\n", (char *)glGetString(GL_VERSION));
	printf("GLSL : %s\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
}
