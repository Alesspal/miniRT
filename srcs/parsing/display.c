#include <stdio.h>
#include <ft_raytracing.h>

void	display_ambient_light(t_ambiant_light ambient_light)
{
	printf("-----AMBIENT LIGHT-----\n");
	printf("intensity : %f\n", ambient_light.intensity);
	printf("rgb : %d, %d, %d\n", ambient_light.color.r, ambient_light.color.g, ambient_light.color.b);
	printf("-----------------------\n");
}

void	display_spot_light(t_spot_light spot_light)
{
	printf("-----SPOT LIGHT-----\n");
	printf("pos : %f, %f, %f\n", spot_light.pos.x, spot_light.pos.y, spot_light.pos.z);
	printf("intensity : %f\n", spot_light.intensity);
	printf("rgb : %d, %d, %d\n", spot_light.color.r, spot_light.color.g, spot_light.color.b);
	printf("--------------------\n");
}

void	display_camera(t_camera camera)
{
	printf("-----CAMERA-----\n");
	printf("pos : %f, %f, %f\n", camera.pos.x, camera.pos.y, camera.pos.z);
	printf("dir : %f, %f, %f\n", camera.dir.x, camera.dir.y, camera.dir.z);
	printf("fov : %d\n", camera.fov);
	printf("----------------\n");
}

void	display_sphere(t_sphere sphere)
{
	printf("-----SPHERE-----\n");
	printf("pos : %f, %f, %f\n", sphere.pos.x, sphere.pos.y, sphere.pos.z);
	printf("radius : %f\n", sphere.radius);
	printf("rgb : %d, %d, %d\n", sphere.color.r, sphere.color.g, sphere.color.b);
	printf("shininiess : %f\n", sphere.shininess);
	printf("----------------\n");
}

void	display_cylinder(t_cylinder cylinder)
{
	printf("-----CYLINDER-----\n");
	printf("pos : %f, %f, %f\n", cylinder.pos.x, cylinder.pos.y, cylinder.pos.z);
	printf("dir : %f, %f, %f\n", cylinder.dir.x, cylinder.dir.y, cylinder.dir.z);
	printf("radius : %f\n", cylinder.radius);
	printf("height : %f\n", cylinder.height);
	printf("rgb : %d, %d, %d\n", cylinder.color.r, cylinder.color.g, cylinder.color.b);
	printf("------------------\n");
}

void	display_plan(t_plane plan)
{
	printf("-----PLAN-----\n");
	printf("pos : %f, %f, %f\n", plan.pos.x, plan.pos.y, plan.pos.z);
	printf("dir : %f, %f, %f\n", plan.normal.x, plan.normal.y, plan.normal.z);
	printf("rgb : %d, %d, %d\n", plan.color.r, plan.color.g, plan.color.b);
	printf("--------------\n");
}

void	display_shapes(t_shapes *shapes)
{
	while (shapes)
	{
		printf("ID = %d\n", shapes->id);
		if (shapes->type == SPHERE)
			display_sphere(shapes->shape.sphere);
		else if (shapes->type == CYLINDER)
			display_cylinder(shapes->shape.cylinder);
		else if (shapes->type == PLANE)
			display_plan(shapes->shape.plane);
		shapes = shapes->next;
	}
}

void	display_scene(t_scene scene)
{
	printf("-----PARSING DISPLAY-----\n");
	display_ambient_light(scene.ambient_light);
	display_spot_light(scene.spot_light);
	display_camera(scene.camera);
	display_shapes(scene.shapes);
}
