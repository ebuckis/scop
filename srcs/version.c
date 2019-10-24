/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   version.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 11:18:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 13:10:12 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

char    *get_vertex_shader(void)
{
	return ("#version 400\n\
in vec3 glVertex;\n\
void main()\n\
{\n\
    gl_Position = vec4(glVertex, 1.0);\n\
}\n");
}

char    *get_frag_shader(void)
{
	return ("#version 400\n\
out vec4 glFragColor;\n\
void main()\n\
{\n\
  glFragColor = vec4(1, 1, 1, 1);\n\
}\n");
}

void    get_version_opengl(void)
{
	printf("Graphic Card : %s\n", (char *)glGetString(GL_RENDERER));
	printf("Version : %s\n", (char *)glGetString(GL_VERSION));
	printf("GLSL : %s\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
}
