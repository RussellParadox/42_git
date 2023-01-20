#include "queue_utility.h"

t_queue	*ft_init(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(*queue));

	queue->first = NULL;
	queue->size = 0;
	return(queue);
}

void	ft_enqueue(t_queue *queue, int new_content)
{
	t_element	*new_ele;
	t_element	*e;

	new_ele = malloc(sizeof(*new_ele));

	new_ele->content = new_content;
	new_ele->next = NULL;

	if (queue->first != NULL)
	{
		e = queue->first;
		while (e->next != NULL)
		{
			e = e->next;
		}
		e->next = new_ele;	
	}
	else
	{
		queue->first = new_ele;
	}
	
	queue->size += 1;
}

void	ft_dequeue(t_queue *queue)
{
	t_element	*del_ele;

	del_ele = queue->first;
	queue->first = del_ele->next;
	free(del_ele);
}

void	ft_end(t_queue *queue)
{
	t_element	*e1;
	t_element	*e2;

	e1 = queue->first;
	while (e1 != NULL)
	{
		e2 = e1->next;
		free(e1);
		e1 = e2;
	}
	free(queue);
}

void	ft_printqueue(t_queue *queue)
{
	t_element	*e;

	e = queue->first;
	while (e != NULL)
	{
		printf("%d\n", e->content);
		e = e->next;
	}
}
