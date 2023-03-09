#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(void)
{
	int	nb;
	char	*str_nb;

	nb = -354;
	str_nb = ft_itoa_base(nb, "0123456789");
	if (str_nb == NULL)
		return (printf("coucou"));
	printf("|%d| |%s|\n", nb, "coucou");
	ft_printf("|%d| |%s|\n", nb, "coucou");
	free(str_nb);
}
