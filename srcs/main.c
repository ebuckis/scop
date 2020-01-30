/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:14:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 14:02:58 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

int     ft_key_action(int keycode, void *p)
{
	t_draw	*draw;

	draw = (t_draw *)p;
//	printf("|%d|\n", keycode);
	if (keycode == 86)
		draw->axis = 'X';
	else if (keycode == 87)
		draw->axis = 'Y';
	else if (keycode == 88)
		draw->axis = 'Z';
	else
		draw->axis = 0;
	
	return (1);
}

int     loop_func(void *p)
{
	t_draw	*draw;

	draw = (t_draw *)p;
	if (draw->axis == 'X')
		draw->angle.x += M_PI / 200;
	else if (draw->axis == 'Y')
		draw->angle.y += M_PI / 200;
	else if (draw->axis == 'Z')
		draw->angle.z += M_PI / 200;

//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	draw_triangle(draw);
	mlx_opengl_swap_buffers(draw->win);
	return (1);
}

int		draw_init(t_draw *draw)
{
	draw->axis = 'X';
	draw->angle.x = 0;
	draw->angle.y = 0;
	draw->angle.z = 0;

	draw->shader.ver_str = get_vertex_shader();
	draw->shader.frag_str = get_frag_shader();

	make_shader_program(draw);

	matrix_init(draw);
	camera_init(draw);
	projection_init(draw);


	//VBO Vertex
	init_vertex(draw);
	//VBO colors
	init_colors(draw);
	//VBO_indices
	init_indexes(draw);

	//TODO: verifier les retours de fonctions
	return (0);
}

int     main(int ac, char **av)
{
	t_draw	draw;

	if (ac != 2)
		return (-1);//error

	draw.vbo_index.values = NULL;
	draw.vbo_index.size = 0;
	draw.vbo_vertex.values = NULL;
	draw.vbo_vertex.size = 0;

	//Parsing
	obj_parse(&draw, av[1]);

	draw.init = mlx_init();
	draw.win = mlx_new_opengl_window(draw.init, WIDTH_WIN, HEIGHT_WIN, "Scop");

	draw_init(&draw);
	
	mlx_opengl_window_set_context(draw.win);



	draw_triangle(&draw);
	mlx_opengl_swap_buffers(draw.win);

	mlx_key_hook(draw.win, ft_key_action, (void *)&draw);

	//mlx_hook(draw.win, 17, (1L << 17), &exit, NULL);//for the red cross

	mlx_loop_hook(draw.init, loop_func, (void *)&draw);
	mlx_loop(draw.init);
	return (0);
}
