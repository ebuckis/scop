/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:14:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 15:25:27 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

int     ft_key_action(int keycode, void **p)
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
    mlx_opengl_swap_buffers(p[1]);
    
}

int     main()
{
    void	*p[3];

	p[0] = mlx_init();
    p[1] = mlx_new_opengl_window(p[0], 1000, 1000, "super");
//	p[2] = mlx_new_image(p[0], 2000, 2000);
    mlx_opengl_window_set_context(p[1]);


    
    draw_triangle('Y');
    mlx_opengl_swap_buffers(p[1]);


    mlx_key_hook(p[1], ft_key_action, p);
    mlx_loop(p[0]);
    return (0);
}
