#include "ft_printf.h"

int		main(void)
{
//	printf("%s", imax_itoa(9223372036854775807));
	char	*s;	
	s = 0;
	long		USHRT_MAX;

	USHRT_MAX = 100;
/*
	printf("%.p, %.0p", s, s);
	printf("\n");
	ft_printf("%.p, %.0p", s, s);
	printf("\n");
*/
	printf("%");
//	printf("\n");
	ft_printf("%");
//	printf("\n");
	
/*
	int		SHRT_MAX;

	SHRT_MAX = 2780215158880;

	printf("%hhu / %hhu", SHRT_MAX - 42, SHRT_MAX - 4200);
	printf("\n");
	ft_printf("%hhu / %hhu", SHRT_MAX - 42, SHRT_MAX - 4200);
	printf("\n");
*/
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