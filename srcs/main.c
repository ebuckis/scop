/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:14:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 09:09:27 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "scop.h"

int     main()
{
    void	*p[3];

	p[0] = mlx_init();
    p[1] = mlx_new_opengl_window(p[0], 1000, 1000, "super");
//	p[2] = mlx_new_image(p[0], 2000, 2000);
    mlx_opengl_window_set_context(p[1]);


    draw_triangle();

printf("%s", get_vertex_shader());   
printf("%s", get_frag_shader());   

    mlx_opengl_swap_buffers(p[1]);
    get_version_opengl();
    mlx_loop(p[0]);
    return (0);
}
