/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mat_projection.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 16:08:46 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:29:20 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"
#define IMAGEWIDTH  1000
#define IMAGEHEIGHT 1000

void		calc_perspective(t_draw *draw) 
{ 
	float scale;
	
	scale = tan(draw->proj.angle * 0.5 * M_PI / 180) * draw->proj.near; 
	draw->proj.r = draw->proj.ratio * scale;
	draw->proj.l = -draw->proj.r; 
	draw->proj.t = scale;
	draw->proj.b = -draw->proj.t; 
} 

void		make_mat_proj(t_draw *draw) 
{
	matrice_generate(&(draw->proj.mat));
	// set OpenGL perspective projection matrix
	draw->proj.mat[0] = 2 * draw->proj.near / (draw->proj.r - draw->proj.l); 
	draw->proj.mat[5] = 2 * draw->proj.near / (draw->proj.t - draw->proj.b); 
	draw->proj.mat[8] = (draw->proj.r + draw->proj.l) / (draw->proj.r - draw->proj.l); 
	draw->proj.mat[9] = (draw->proj.t + draw->proj.b) / (draw->proj.t - draw->proj.b); 
	draw->proj.mat[10] = -(draw->proj.far + draw->proj.near) / (draw->proj.far - draw->proj.near); 
	draw->proj.mat[11] = -1; 
	draw->proj.mat[14] = -2 * draw->proj.far * draw->proj.near / (draw->proj.far - draw->proj.near); 
} 

int		projection_init(t_draw *draw)
{
	draw->proj.angle = 90;
	draw->proj.near = 0.1;
	draw->proj.far = 100;
	draw->proj.ratio = IMAGEWIDTH / (float)IMAGEHEIGHT; 
	calc_perspective(draw);
	make_mat_proj(draw);
	return (0);
}