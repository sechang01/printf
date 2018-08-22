#include <stdio.h>
#include <stdarg.h>

int		ftp(const char *s, ...)
{
	va_list x;
	char	*y;

	va_start(x, s);
	y = va_arg(x, char *);
	printf("%s\n", y);
//	printf("%d\n", (int)va_arg(x, char *));
	return 0;



}

int		main(void)
{
	char	s[] = "abcdef";
	int		i;

	i = 321;

	ftp("123", i);
//	printf("%lld\n", (long long int)s);

	return 0;
}