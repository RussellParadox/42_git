#include <stdio.h>
#include "libft/libft.h"

int	main(void)
{
	int	nb;
	char	*str_nb;

	nb = 354;
	str_nb = ft_itoa_base((long)&nb, "0123456789abcdef");
	if (str_nb == NULL)
		return (printf("coucou"));
	printf("\nstate: %d\n", printf("|%p 0x%1.3s|", &nb, str_nb));
	free(str_nb);
}
