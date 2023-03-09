#include <stdio.h>
#include "libft/libft.h"

int	main(void)
{
	int	nb;
	char	*str_nb;

	nb = 354;
	str_nb = ft_itoa_base(nb, "0123456789abcdef");
	printf("\nstate: %d\n", printf("|%s|", str_nb));
	free(str_nb);
}
