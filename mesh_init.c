/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:45:02 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/06 16:48:16 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	*get_vertices(char *obj_path, int *ver_count)
{
	t_get_vert	ver;

	ver.obj_file = open(obj_path, O_RDONLY);
	*ver_count = data_counter(ver.obj_file, 'v');
	close(ver.obj_file);
	ver.vertices = malloc(sizeof(t_vec3) * *ver_count);
	ver.obj_file = open(obj_path, O_RDONLY);
	ver.index = 0;
	while (1)
	{
		if (get_vertex_data(&ver))
			break ;
	}
	close(ver.obj_file);
	return (ver.vertices);
}

t_tri	*get_triangles(char *obj_path, t_vec3 *vertices, int *tri_count)
{
	t_get_tris	tris;

	tris.obj_file = open(obj_path, O_RDONLY);
	*tri_count = data_counter(tris.obj_file, 'f');
	close(tris.obj_file);
	tris.tris = malloc(sizeof(t_tri) * *tri_count);
	tris.obj_file = open(obj_path, O_RDONLY);
	tris.index = 0;
	while (1)
	{
		if (get_triangle_data(&tris, vertices))
			break ;
	}
	close(tris.obj_file);
	return (tris.tris);
}

t_mesh	mesh_init(char *obj_path)
{
	t_mesh	mesh;
	t_vec3	*vertices;

	vertices = get_vertices(obj_path, &mesh.ver_count);
	mesh.mesh = get_triangles(obj_path, vertices, &mesh.tri_count);
	free(vertices);
	return (mesh);
}
