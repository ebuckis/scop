/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:14:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 17:42:37 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/scop.h"

int     main(int ac, char **av)
{
    if (!av[ac - 1])
        return (1);

    void	*p[3];

	p[0] = mlx_init();
    p[1] = mlx_new_opengl_window(p[0], 800, 800, "super");
	p[2] = mlx_new_image(p[0], 2000, 2000);
    mlx_loop(p[0]);
    return (0);
}
