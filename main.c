#include "ft_printf.h"

int		main(void)
{
	printf("%03.2d", -1);
	printf("\n");
	ft_printf("%03.2d", -1);
	printf("\n");

/*	printf("hello%C\n", L'ø');
	ft_printf("hello%C\n", L'ø');

	printf("\n");

	ft_printf("hello%S\n", L"øøøø");
	printf("hello%S\n", L"øøøø");


	printf("printf:\n");
	printf("%5%");
	printf("\n");
	printf("ft_printf:\n");
	ft_printf("%1%");
	printf("\n");


	printf("printf:\n");
	printf("%x", 42);
	printf("\n");
	printf("ft_printf:\n");
	ft_printf("%x", 42);
	printf("\n");


	printf("printf:\n");
	printf("%-5c", 42);
	printf("\n");
	printf("ft_printf:\n");
	ft_printf("%-5c", 42);
	printf("\n");


	printf("printf:\n");
	printf("%s", "abc");
	printf("\n");
	printf("ft_printf:\n");
	ft_printf("%s", "abc");


	printf("printf:\n");
	printf("%d", 1);
	printf("\n");
	printf("ft_printf:\n");
	ft_printf("%d", 1);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
*/
	return (0);
}

// appending if longer than my buff size? or restarting at certain point
// widechar%