/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 14:46:51 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 11:27:47 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

void        vect_sub(GLfloat *v1, GLfloat *v2, GLfloat **dest)
{
    (*dest)[0] = v1[0] - v2[0];
    (*dest)[1] = v1[1] - v2[1];
    (*dest)[2] = v1[2] - v2[2];
}

void        vect_mult(GLfloat *v1, GLfloat *v2, GLfloat **dest)
{
    (*dest)[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    (*dest)[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
    (*dest)[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
}

void    generate_look_at(t_draw *draw)
{
    GLfloat *r;
    GLfloat *d;
    GLfloat *u;
    GLfloat *p;

    r = draw->cam.pos;
    d = draw->cam.dir;
    u = draw->cam.up;
    p = draw->cam.pos;
    GLfloat mat1[16] = {
        r[0], r[1], r[2], 0,
        u[0], u[1], u[2], 0,
        d[0], d[1], d[2], 0,
        0, 0, 0, 1
    };
    GLfloat mat2[16] = {
        1, 0, 0, -p[0],
        0, 1, 0, -p[1],
        0, 0, 1, -p[2],
        0, 0, 0, 1
    };
	mult_matrix(mat1, mat2, &(draw->cam.look_at));
}

int new_glfloat_array(GLfloat **array, size_t size, GLfloat value)
{
	(*array) = (GLfloat *)malloc(sizeof(GLfloat) * size);
    if (!(*array))
        return (1);
    while (size > 0)
    {
        (*array)[size - 1] = value;
        size--;
    }
    return (0);
}

int camera_init(t_draw *draw)
{ 
    int     ret;
    GLfloat *up;
        return (1);

	ret = new_glfloat_array(&up, 3, 0);
	ret |= new_glfloat_array(&draw->cam.pos, 3, 3.0);
	ret |= new_glfloat_array(&draw->cam.targ, 3, 0.0);
	ret |= new_glfloat_array(&draw->cam.dir, 3, 0.0);
	ret |= new_glfloat_array(&draw->cam.right, 3, 0.0);
	ret |= new_glfloat_array(&draw->cam.up, 3, 0.0);
	ret |= new_glfloat_array(&draw->cam.look_at, 16, 0.0);
    if (ret)
        return (1);

    up[1] = 1.0;
    vect_sub(draw->cam.pos, draw->cam.targ, &(draw->cam.dir));
    vect_mult(up, draw->cam.dir, &(draw->cam.right));
    vect_mult(draw->cam.dir, draw->cam.right, &(draw->cam.up));
    generate_look_at(draw);

    return (0);

}