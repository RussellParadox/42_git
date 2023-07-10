#include "stdio.h"
#include "stdlib.h"

int	main(void)
{
	int	i;
	int	*ptr;
	int	res;

	i = 0;
	while (i < 10)
	{
		ptr = (int *)malloc(sizeof(int));
		res = ((int)ptr % 10) + 10;
		printf("%d\n", res);
		i++;
	}
}
