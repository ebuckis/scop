/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:14:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 10:48:41 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

/*int     ft_key_action(int keycode, void *p)
{
	printf("|%d|\n", keycode);
   // glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (keycode == 86)
	{
		draw_triangle('X');
	}
	if (keycode == 87)
	{
		draw_triangle('Y');
	}
	if (keycode == 88)
	{
		draw_triangle('Z');
	}
	mlx_opengl_swap_buffers();
	return (1);
}*/

int     loop_func(void *p)
{
	t_draw	*draw;

	draw = (t_draw *)p;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw_triangle(&draw);
	mlx_opengl_swap_buffers(draw->win);
	return (1);
}

int		draw_init(t_draw *draw)
{
	GLuint	loc;
	float	v = 0.5;
	float	points[] = {
		+v, +v, +v,	//p0
		+v, -v, +v,	//p1
		-v, -v, +v,	//p2
		-v, +v, +v,	//p3
		+v, +v, -v,	//p4
		+v, -v, -v,	//p5
		-v, -v, -v,	//p6
		-v, +v, -v,	//p7
	};

	float	colors[] = {
		1.0, 0.0 ,0.0,	//[0] rouge
		0.0, 1.0, 0.0,	//[1] vert
		0.0, 0.0, 1.0,	//[2] bleu
		1.0, 1.0, 0.0,	//[3] jaune
		1.0, 0.0, 1.0,	//[4] magenta
		0.0, 1.0, 1.0,	//[5] cyan
		1.0, 1.0, 1.0,	//[6] blanc
		1.0, 0.5, 0.0,	//[7] orange
	};

	GLshort	index[] = {
		0, 1, 2,
		0, 2, 3,
		0, 1, 5,
		0, 4, 5,
		1, 2, 6,
		1, 5, 6,
		2, 3, 6,
		3, 6, 7,
		0, 3, 7,
		0, 4, 7,
		4, 5, 6,
		4, 6, 7,
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	draw->init = mlx_init();
	draw->win = mlx_new_opengl_window(draw->init, WIDTH_WIN, HEIGHT_WIN, "super");

	draw->shader.id = makeShaderProgram(&draw);

	init_matrix(draw);
	

}

int     main()
{
	t_draw	draw;

	draw_init(&draw);
	
	mlx_opengl_window_set_context(draw.win);


	draw_triangle('Y');
	mlx_opengl_swap_buffers(draw.win);


//	mlx_key_hook(draw.win, ft_key_action, p);

	mlx_hook(draw.win, 17, (1L << 17), &exit, NULL);//for the red cross

	mlx_loop_hook(draw.init, loop_func, (void *)&draw);
	mlx_loop(draw.init);
	return (0);
}
