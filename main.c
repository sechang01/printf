#include "ft_printf.h"

int		main(void)
{
//	char	s[] = "asdfg";
//	char happy[] = { 0xe2, 0x98, 0xba };  /* U+263A */

//	printf("my- %c -yours- %c -ico- %c -mmm- %.4s num %d hex %x", 'h', 'o', 'o', "testing", 555, 555555);
	printf("\n");
//	ft_printf("my- %c -yours- %c -ico- %c -mmm- %.4s num %d hex %x", 'h', 'o', 'o', "testing", 555, 555555);
//
//	printf("hello%20x %u\n", 420, 888);
//	printf("\n");
//	ft_printf("hello%20x %u\n", 420, 888);		
//	printf("Locale is: %s\n", setlocale(LC_ALL, "en_GB"));
//	setlocale(LC_ALL, "en_US.UTF-8");
//	setlocale(LC_ALL, "en-US");
	printf("hello%C\n", L'ø');
//	printf("\n");
	ft_printf("hello%C\n", L'ø');
	ft_printf("hello%S\n", L"øøøø");
	printf("hello%S\n", L"øøøø");

	return (0);
}

// appending if longer than my buff size? or restarting at certain point
// widechar%