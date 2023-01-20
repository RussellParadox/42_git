#ifndef QUEUE_UTILITY_H
#define QUEUE_UTILITY_H
#include <stdlib.h>
#include <stdio.h>

typedef struct s_element	t_element;
struct s_element
{
	int	content;
	t_element	*next;
};

typedef struct s_queue	t_queue;
struct s_queue
{
	t_element	*first;
	int	size;
};

t_queue	*ft_init(void);
void	ft_enqueue(t_queue *queue, int new_content);
void	ft_end(t_queue *queue);
void	ft_dequeue(t_queue *queue);
void	ft_printqueue(t_queue *queue);

#endif
