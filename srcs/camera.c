/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 14:46:51 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:44:10 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

void        vect_sub(t_coord v1, t_coord v2, t_coord *dest)
{
    dest->x = v1.x - v2.x;
    dest->y = v1.y - v2.y;
    dest->z = v1.z - v2.z;
}

void        vect_mult(t_coord v1, t_coord v2, t_coord *dest)
{
    dest->x = (v1.y * v2.z) - (v1.z * v2.y);
    dest->y = (v1.z * v2.x) - (v1.x * v2.z);
    dest->z = (v1.x * v2.y) - (v1.y * v2.x);
}

void    generate_look_at(t_draw *draw)
{
    GLfloat mat1[16] = {
        draw->cam.right.x, draw->cam.right.y, draw->cam.right.z, 0,
        draw->cam.up.x, draw->cam.up.y, draw->cam.up.z, 0,
        draw->cam.dir.x, draw->cam.dir.y, draw->cam.dir.z, 0,
        0, 0, 0, 1
    };
    GLfloat mat2[16] = {
        1, 0, 0, -draw->cam.pos.x,
        0, 1, 0, -draw->cam.pos.y,
        0, 0, 1, -draw->cam.pos.z,
        0, 0, 0, 1
    };
    matrice_generate(&(draw->cam.look_at));
	mult_matrix(mat1, mat2, &(draw->cam.look_at));
    display_matrices(draw->cam.look_at);
}

void        fill_vector(t_coord *coord, GLfloat x, GLfloat y, GLfloat z)
{
    coord->x = x;
    coord->y = y;
    coord->z = z;
}

void printup(t_coord up)
{
    printf("up : x->%f, y->%f, z->%f\n", up.x, up.y, up.z);
}

int camera_init(t_draw *draw)
{ 
    t_coord up;

    fill_vector(&up, 0.0, 1.0, 0.0);
    printup(up);
    fill_vector(&draw->cam.pos, 0.0, 0.0, 1.0);
    printup(draw->cam.pos);
    fill_vector(&draw->cam.targ, 0.0, 0.0, 0.0);
    printup(draw->cam.targ);

    vect_sub(draw->cam.pos, draw->cam.targ, &(draw->cam.dir));
    printup(draw->cam.dir);
    vect_mult(up, draw->cam.dir, &(draw->cam.right));
    printup(draw->cam.right);
    vect_mult(draw->cam.dir, draw->cam.right, &(draw->cam.up));
    printup(draw->cam.up);
    generate_look_at(draw);
  //  draw->cam.look_at[0] = 0;
  //  draw->cam.look_at[1] = 0;
  //  draw->cam.look_at[2] = 0;
  //  draw->cam.look_at[3] = 3;
  //  draw->cam.look_at[4] = 0;
  //  draw->cam.look_at[5] = 0;
  //  draw->cam.look_at[6] = 0;
  //  draw->cam.look_at[7] = 0;
  //  draw->cam.look_at[8] = 0;
  //  draw->cam.look_at[9] = 1;
  //  draw->cam.look_at[10] = 0;
  //  draw->cam.look_at[11] = 0;
  //  draw->cam.look_at[12] = 0;
  //  draw->cam.look_at[13] = 0;
  //  draw->cam.look_at[14] = 0;
  //  draw->cam.look_at[15] = 0;
    return (0);

}