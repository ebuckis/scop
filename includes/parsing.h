`/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 14:46:33 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 11:16:55 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "scop.h"
# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

typedef struct  s_parse
{
	size_t		n;
	size_t		*len;
	size_t		*start;
	char		**tab;
}               t_parse;

static int		fill_parse_table(t_parse *prs, char *line, size_t i);