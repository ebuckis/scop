/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_matrix.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:35:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 10:49:49 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

int     init_matrix(t_draw *draw)
{
	mat = 

//	display_matrices(mat);

    draw->matrix.values = matrice_rot_create(0, 'X');
    draw->matrix.loc = glUniformMatrix4fv(loc, 1, GL_FALSE, mat);

	loc = glGetUniformLocation(sh_id, "matrix");
	glUniformMatrix4fv(loc, 1, GL_FALSE, mat);//malloc pas free
}