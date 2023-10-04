#include "element_parsing.h"
#include "display.h"
#include <stdlib.h>
#include <stdio.h>

int	shapes_len(t_shapes *shapes)
{
	int			len;
	t_shapes	*temp;

	if (!shapes)
		return (0);
	len = 0;
	temp = shapes;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

t_shapes	*create_new_node(int id)
{
	t_shapes	*new_node;

	new_node = malloc(sizeof(t_shapes));
	if (!new_node)
		return (NULL);
	new_node->id = id;
	new_node->next = NULL;
	return (new_node);
}

int	append_to_list(t_shapes **shapes, t_shapes *new_node)
{
	t_shapes	*tail;

	if (!shapes)
		return (1);
	tail = *shapes;
	while (tail && tail->next)
		tail = tail->next;
	if (tail)
		tail->next = new_node;
	else
		*shapes = new_node;
	return (0);
}

int	shapes_parsing(char *description, t_shapes **shapes, t_element_type el)
{
	t_shapes	*new_node;

	if (!shapes)
		return (1);
	new_node = create_new_node(shapes_len(*shapes));
	if (!new_node)
		return (printf("shape creation for list of shapes failed\n"), 1);
	if (append_to_list(shapes, new_node))
		return (printf("new shape could not be added to the list\n"), 1);
	if (el == SP)
		return (new_node->type = SPHERE,
			sphere_parsing(description, &new_node->shape.sphere));
	if (el == CY)
		return (new_node->type = CYLINDER,
			cylindre_parsing(description, &new_node->shape.cylinder));
	if (el == PL)
		return (new_node->type = PLANE,
			plan_parsing(description, &new_node->shape.plane));
	return (1);
}
