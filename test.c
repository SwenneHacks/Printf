#include "printf.h"

int		main(void)
{
	unsigned int	i = -7;
	char			c = 'c';
	char			*s = "Here";

	char		s1[] = "Lookie";
	char		s2[] = "Here";
	char		s3[] = "Wow this is a really big string wowow";
	char		s4[] = "Old man";

	ft_printf("\033[1;31m");
	ft_printf("Strings: -010Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-10s$ %*s$ %-8.7s$ %s$", s1, -10, s2, s3, s4));
	printf("<- %i \n\n", printf("%-10s$ %*s$ %-8.7s$ %s$", s1, -10, s2, s3, s4));
	ft_printf("\033[0m");

	ft_putstr("______________ DONE: \n\n");
		printf(			"%%i 		|%i|\n", i);
	ft_printf(			"%%i 		|%i|\n", i);
	ft_putchar('\n');
//_______________________________________________________ DIGITS
		printf(			"%%d 		|%d|\n", i);
	ft_printf(			"%%d 		|%d|\n", i);
	ft_putchar('\n');
		printf(			"%% d 		|% d|\n", i);
	ft_printf(			"%% d 		|% d|\n", i);
	ft_putchar('\n');
		printf(			"%%05d 		|%05d|\n", i);
	ft_printf(			"%%05d 		|%05d|\n", i);
	ft_putchar('\n');
		printf(			"%%5d 		|%5d|\n", i);
	ft_printf(			"%%5d 		|%5d|\n", i);
	ft_putchar('\n');
		printf(			"%%.1d		|%.1d|\n", i);
	ft_printf(			"%%.1d		|%.1d|\n", i);
	ft_putchar('\n');
		printf(			"%%0.5d		|%0.5d|\n", i);
	ft_printf(			"%%0.5d		|%0.5d|\n", i);
	ft_putchar('\n');
		printf(			"%%.1d		|%.1d|\n", 555);
	ft_printf(			"%%.1d		|%.1d|\n", 555);
	ft_putchar('\n');
		printf(			"%%5.1d		|%5.1d|\n", i);
	ft_printf(			"%%5.1d		|%5.1d|\n", i);
	ft_putchar('\n');
		printf(		"%% -5d 		|% -5d|\n", i);
	ft_printf(		"%% -5d 		|% -5d|\n", i);
	ft_putchar('\n');
//_______________________________________________________ CHARS
		printf(			"%%c 		|%c|\n", c);
	ft_printf(			"%%c 		|%c|\n", c);
	ft_putchar('\n');
		printf(		"%%*c,4		|%*c|\n", 4, c);
	ft_printf(		"%%*c,4		|%*c|\n", 4, c);
	ft_putchar('\n');
		printf(			"%%-4c 		|%-4c|\n", c);
	ft_printf(			"%%-4c 		|%-4c|\n", c);
	ft_putchar('\n');
//_______________________________________________________ STRINGS
		printf(			"%%5s 		|%5s|\n", s);
	ft_printf(			"%%5s 		|%5s|\n", s);
	ft_putchar('\n');
		printf(			"%%-5s 		|%-5s|\n", s);
	ft_printf(			"%%-5s 		|%-5s|\n", s);
	ft_putchar('\n');
		printf(			"%%-*s 		|%-*s|\n", 5, s);
	ft_printf(			"%%-*s 		|%-*s|\n", 5, s);
	ft_putchar('\n');
		printf(			"%%.2s		|%.2s|\n", "Hello");
	ft_printf(			"%%.2s		|%.2s|\n", "Hello");
	ft_putchar('\n');
		printf(			"%%6.4s		|%6.4s|\n", "Hello");
	ft_printf(			"%%6.4s		|%6.4s|\n", "Hello");
	ft_putchar('\n');
		printf(			"%%*s,6		|%*s|\n", 6, "Hello");
	ft_printf(			"%%*s,6		|%*s|\n", 6, "Hello");
	ft_putchar('\n');
		printf(		"%%.*s,2		|%.*s|\n", 2, "Hello");
	ft_printf(		"%%.*s,2 		|%.*s|\n", 2, "Hello");
	ft_putchar('\n');
		printf(		"%%-6.4s 		|%-6.4s|\n", "Hello");
	ft_printf(		"%%-6.4s		|%-6.4s|\n", "Hello");
	ft_putchar('\n');
//_______________________________________________________ POINTER
		printf(			"%%p 		|%p|\n", &c);
	ft_printf(			"%%p 		|%p|\n", &c);
	ft_putchar('\n');
//_______________________________________________________ HEXA
		printf(			"%%x		|%x|\n", 555);
	ft_printf(			"%%x		|%x|\n", 555);
	ft_putchar('\n');
		printf(			"%%X 		|%X|\n", 555);
	ft_printf(			"%%X 		|%X|\n", 555);
	ft_putchar('\n');
//_______________________________________________________ UNSIGNED
		printf(			"%%u 		|%u|\n", 555);
	ft_printf(			"%%u 		|%u|\n", 555);
	ft_putchar('\n');
//_______________________________________________________ OCTA
		printf(			"%%o 		|%o|\n", 555);
	ft_printf(			"%%o 		|%o|\n", 555);
	ft_putchar('\n');

	ft_putstr("______________________________ ULTIMATE: \n");
	ft_putchar('\n');
		printf(	"%%---*s 		|%---*s|\n", 5, s);
	ft_printf(	"%%---*s 		|%---*s|\n", 5, s);
	ft_putchar('\n');
		printf(	"%%*c,-4		|%*c|\n", -4, c);
	ft_printf(	"%%*c,-4		|%*c|\n", -4, c);
	ft_putchar('\n');
		printf(	"%%*c,-4		|%*c|\n", -4, i);
	ft_printf(	"%%*c,-4		|%*c|\n", -4, i);
	ft_putchar('\n');
		printf(	"%% *d,4		|%*d|\n", 4, +7);
	ft_printf(	"%% *d,4		|%*d|\n", 4, +7);
	ft_putchar('\n');
		printf(		"%%-*s 		|%-*s|\n", 5, s);
	ft_printf(		"%%-*s 		|%-*s|\n", 5, s);
	ft_putchar('\n');
		printf(		"%%*s 		|%*s|\n", -5, s);
	ft_printf(		"%%*s 		|%*s|\n", -5, s);
	ft_putchar('\n');

	ft_putstr("______________________________ TO FIX: \n");
	ft_putchar('\n');
		printf(		"%%u 		|%u|\n", -7);
	ft_printf(		"%%u 		|%u|\n", -7);
	ft_putchar('\n');

	return (0);
}
