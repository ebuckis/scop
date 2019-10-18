/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   version.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 11:18:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 11:59:35 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/scop.h"

char    *get_vertex_shader(void)
{
	return ("#version 410 es\n\
        in vec2 glVertex;\n\
        void main()\n\
        {\n\
            gl_Position = vec4(glVertex, 0.0, 1.0);\n\
        }\n");
}

char    *get_frag_shader(void)
{
	return ("#version 410 es\n\
        precision mediump float;\n\
        out vec4 glFragColor;\n\
        void main()\n\
        {\n\
            glFragColor = vec4(0.84, 0.15, 0.51, 1.0);\n\
        }\n");
}

void    get_version_opengl(void)
{
	printf("Graphic Card : %s\n", (char *)glGetString(GL_RENDERER));
	printf("Version : %s\n", (char *)glGetString(GL_VERSION));
	printf("GLSL : %s\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
}
