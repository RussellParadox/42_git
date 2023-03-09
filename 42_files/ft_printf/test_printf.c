#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(void)
{
	int	nb;
	char	*str_nb;

	nb = -354;
	str_nb = ft_itoa_base((unsigned int)nb, "0123456789abcdef");
	if (str_nb == NULL)
		return (printf("coucou"));
	ft_printf("|%d| |%s|", nb, str_nb);
	free(str_nb);
}
