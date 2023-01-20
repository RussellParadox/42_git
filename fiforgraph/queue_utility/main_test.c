#include <stdio.h>
#include <stdlib.h>
#include "queue_utility.h"

int	main(void)
{
	t_queue	*q;

	q = ft_init();
	ft_addint(q, 0);
	ft_addint(q, 2);
	ft_addint(q, 78);
	ft_printqueue(q);
	ft_dequeue(q);
	ft_printqueue(q);
	ft_end(q);
}
