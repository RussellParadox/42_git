#include <stdio.h>
#include <stdlib.h>
#include "queue_utility.h"

int	main(void)
{
	t_queue	*q;
	t_queue *q0;

	q0 = ft_init();
	q = ft_init();
	ft_addint(q, 0);
	ft_addint(q, 2);
	ft_addint(q, 78);
	ft_printqueue(q);
	ft_enqueue(q0, q);
	ft_end(q);
}
