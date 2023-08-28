#include "ft_color.h"
#include <stdio.h>

t_color change_intesity(t_color color, float intensity)
{
	t_color new_color;

	if (intensity > 1)
		intensity = 1;
	else if (intensity < 0)
		intensity = 0;
	new_color.r = color.r * intensity;
	printf("c.r = %i, intensity = %f, new c = %i\n", color.r, intensity, new_color.r);
	new_color.g = color.g * intensity;
	printf("c.g = %i, intensity = %f, new c = %i\n", color.g, intensity, new_color.g);
	new_color.b = color.b * intensity;
	printf("c.b = %i, intensity = %f, new c = %i\n", color.b, intensity, new_color.b);
	return (new_color);
}

t_color add_color(t_color color1, t_color color2)
{
	t_color new_color;

	new_color.r = color1.r + color2.r;
	new_color.g = color1.g + color2.g;
	new_color.b = color1.b + color2.b;
	return (new_color);
}

t_color mult_color(t_color color1, t_color color2)
{
	t_color new_color;

	new_color.r = color1.r * color2.r / 255;
	printf("c1.r = %i, c2.r = %i, new c = %i\n", color1.r, color2.r, new_color.r);
	new_color.g = color1.g * color2.g / 255;
	printf("c1.g = %i, c2.g = %i, new c = %i\n", color1.g, color2.g, new_color.g);
	new_color.b = color1.b * color2.b / 255;
	printf("c1.b = %i, c2.b = %i, new c = %i\n", color1.b, color2.b, new_color.b);
	return (new_color);
}

int color_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

/* int main(void)
{
	t_color color = {255, 0, 0};

	printf("color to int = %x\n", color_to_int(color));
	return (0);
} */