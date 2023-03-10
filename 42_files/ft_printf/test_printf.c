#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	printf("\nstate :%d\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
}
