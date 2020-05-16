
#include "../printf.h"

void	result(int test, int ft)
{
	if (test == ft)
	{
		ft_putstr("				PASS\n");
		g_pass++;
	}
	else
	{
		ft_putstr("				FAIL\n");
		printf("				pf[%d]\n", test - 5);
		printf("				ft[%d]\n\n", ft - 5);
	}
	g_test++;
}

int		main(void)
{
	int				test;
	unsigned int	i = -7;
	int				d = 55;
	char			c = 'c';
	char			*s = "Here";
	int				t;
	g_pass 			= 0;
	g_test			= 0;


	ft_putstr("_____________________________________\nCHARS: \n\n");

//_____________________________________________________________ CHARS
	test =	printf(			"%%c 		|%c|\n", c);
	t =	ft_printf(			"%%c 		|%c|\n", c);
	result(test, t);
	test =	printf(			"%%-4c 		|%-4c|\n", c);
	t =	ft_printf(			"%%-4c 		|%-4c|\n", c);
	result(test, t);
	test =	printf(			"%%*c,4		|%*c|\n", 4, c);
	t =	ft_printf(			"%%*c,4		|%*c|\n", 4, c);
	result(test, t);
	test =	printf(			"%%*c,-		|%*c|\n", -4, c);
	t =	ft_printf(			"%%*c,-		|%*c|\n", -4, c);
	result(test, t);
	test =	printf(			"%%*c,0		|%*c|\n", 0, d);
	t =	ft_printf(			"%%*c,0		|%*c|\n", 0, d);
	result(test, t);
	test =	printf(			"%%c 		|%c|\n", '\0');
	t =	ft_printf(			"%%c 		|%c|\n", '\0');
	result(test, t);
	test =	printf(			"%%-4c 		|%.4c|\n", c);
	t =	ft_printf(			"%%-4c 		|%.4c|\n", c);
	result(test, t);
	test =	printf(			"%%*c,4		|%.c|\n", c);
	t =	ft_printf(			"%%*c,4		|%.c|\n", c);
	result(test, t);
	test =	printf(			"%%cc		|%c%c|\n", c, 'o');
	t =	ft_printf(			"%%cc		|%c%c|\n", c, 'o');
	result(test, t);
	test =	printf(			"%%cc		|%c%c|\n", c, d);
	t =	ft_printf(			"%%cc		|%c%c|\n", c, d);
	result(test, t);
	test =	printf(			"%% c 		|% c|\n", '\0');
	t =	ft_printf(			"%% c 		|% c|\n", '\0');
	result(test, t);
	test =	printf(			"%%c 		|%c|\n", d);
	t =	ft_printf(			"%%c 		|%c|\n", d);
	result(test, t);

ft_putstr("\n____________________________________\nSTRINGS: \n\n");
	test =	printf(			"%%5s 		|%5s|\n", s);
	t =	ft_printf(			"%%5s 		|%5s|\n", s);
	result(test, t);
	test =	printf(			"%%ss 		|%s%s|\n", s, "ok");
	t =	ft_printf(			"%%ss 		|%s%s|\n", s, "ok");
	result(test, t);
	test =	printf(			"%%-5s 		|%-5s|\n", s);
	t =	ft_printf(			"%%-5s 		|%-5s|\n", s);
	result(test, t);
	test =	printf(			"%%.2s		|%.2s|\n", s);
	t =	ft_printf(			"%%.2s		|%.2s|\n", s);
	result(test, t);
	test =	printf(			"%%*s,6		|%*s|\n", 6, s);
	t =	ft_printf(			"%%*s,6		|%*s|\n", 6, s);
	result(test, t);
	test =	printf(			"%%6.4s		|%6.4s|\n", s);
	t =	ft_printf(			"%%6.4s		|%6.4s|\n", s);
	result(test, t);
	test =	printf(			"%%*.*s		|%*.*s|\n", -5, 2, s);
	t =	ft_printf(			"%%*.*s		|%*.*s|\n", -5, 2, s);
	result(test, t);
	test =	printf(			"%%*s,-1 		|%*s|\n", -1, s);
	t =	ft_printf(			"%%*s,-1 		|%*s|\n", -1, s);
	result(test, t);
	test =	printf(			"%%*s,0 		|%*s|\n", 0, s);
	t =	ft_printf(			"%%*s,0 		|%*s|\n", 0, s);
	result(test, t);
	test =	printf(			"%%-*s,5 		|%-*s|\n", 5, s);
	t =	ft_printf(			"%%-*s,5 		|%-*s|\n", 5, s);
	result(test, t);
	test =	printf(			"%%--*s,1		|%--*s|\n", 1, s);
	t =	ft_printf(			"%%--*s,1		|%--*s|\n", 1, s);
	result(test, t);
	test =	printf(		"%%.*s,2		|%.*s|\n", 2, s);
	t =	ft_printf(		"%%.*s,2		|%.*s|\n", 2, s);
	result(test, t);
	test =	printf(		"%%-6.4s		|%-6.4s|\n", s);
	t =	ft_printf(		"%%-6.4s		|%-6.4s|\n", s);
	result(test, t);
//____________________________________________________________ POINTER
	test =	printf(			"%%p 	|%p|\n", &c);
	t =	ft_printf(			"%%p 	|%p|\n", &c);
	result(test, t);
//____________________________________________________________ HEXA
	test =	printf(			"%%x		|%x|\n", d);
	t =	ft_printf(			"%%x		|%x|\n", d);
	result(test, t);
	test =	printf(			"%%X 		|%X|\n", d);
	t =	ft_printf(			"%%X 		|%X|\n", d);
	result(test, t);
//_____________________________________________________________ OCTA
	test =	printf(			"%%o 		|%o|\n", d);
	t =	ft_printf(			"%%o 		|%o|\n", d);
	result(test, t);
//___________________________________________________________ UNSIGNED
	test =	printf(			"%%u 		|%u|\n", d);
	t =	ft_printf(			"%%u 		|%u|\n", d);
	result(test, t);
	test =	printf(			"%%u 		|%u|\n", i);
	t =	ft_printf(			"%%u 		|%u|\n", i);
	result(test, t);
	
ft_putstr("\n_____________________________________\nBONUS: \n\n");
	
			printf(		"%%+d"); 		
	test =	printf(			"		|%+d|\n", i);
	t =	ft_printf(			"		|%+d|\n", i);
	result(test, t);
			printf(		"%%+5d"); 		
	test =	printf(			"		|%+5d|\n", i);
	t =	ft_printf(			"		|%+5d|\n", i);
	result(test, t);
			printf(		"%%++5d"); 		
	test =	printf(			"		|%++5d|\n", d);
	t =	ft_printf(			"		|%++5d|\n", d);
	result(test, t);
			printf(		"%%+d"); 		
	test =	printf(			"		|%+d|\n", d);
	t =	ft_printf(			"		|%+d|\n", d);
	result(test, t);
			printf(		"%%+i"); 		
	test =	printf(			"		|%+i|\n", d);
	t =	ft_printf(			"		|%+i|\n", d);
	result(test, t);
			printf(		"%%++i"); 		
	test =	printf(			"		|%++i|\n", d);
	t =	ft_printf(			"		|%++i|\n", d);
	result(test, t);
			printf(		"%%+d, 0");
	test =	printf(			"		|%+d|\n",  0);
	t =	ft_printf(			"		|%+d|\n",  0);
	result(test, t);
			printf(		"%%+d,0");
	test =	printf(			"		|%+d|\n", 0);
	t =	ft_printf(			"		|%+d|\n", 0);
	result(test, t);
	test =	printf(		"%% -4d,55 	|% -4d|\n", d);
	t =	ft_printf(		"%% -4d,55 	|% -4d|\n", d);
	result(test, t);
	test =	printf(		"%%+-.1d,-	|%+-.1d|\n", i);
	t =	ft_printf(		"%%+-.1d,-	|%+-.1d|\n", i);
	result(test, t);
	test =	printf(		"%%+-2.d,0	|%+-2.d|\n", 0);
	t =	ft_printf(		"%%+-2.d,0	|%+-2.d|\n", 0);
	result(test, t);
	test =	printf(		"%%+3.d, 0	|%+3.d|\n", 0);
	t =	ft_printf(		"%%+3.d, 0	|%+3.d|\n", 0);
	result(test, t);
			printf(		"%% d, 0");
	test =	printf(			"		|% d|\n",  0);
	t =	ft_printf(			"		|% d|\n",  0);
	result(test, t);
			printf(		"%% d");
	test =	printf(			"		|% d|\n", i);
	t =	ft_printf(			"		|% d|\n", i);
	result(test, t);
			printf(		"%%  d"); 		
	test =	printf(			"		|%  d|\n", i);
	t =	ft_printf(			"		|%  d|\n", i);
	result(test, t);
			printf(		"%% .3d,5");
	test =	printf(			"		|% .3d|\n", 5);
	t =	ft_printf(			"		|% .3d|\n", 5);
	result(test, t);
			printf(		"%% -.3d");
	test =	printf(			"		|% -.3d|\n", i);
	t =	ft_printf(			"		|% -.3d|\n", i);
	result(test, t);
			printf(		"%% 08.5d");
	test =	printf(			"		|% 08.5d|\n", 0);
	t =	ft_printf(			"		|% 08.5d|\n", 0);
	result(test, t);
			printf(		"%% -5d,-");
	test =	printf(			"		|% -5d|\n", i);
	t =	ft_printf(			"		|% -5d|\n", i);
	result(test, t);
	ft_putstr("\n_____________________________________ TO FIX: \n\n");

		printf(			"%%0-8.5d");
	test =	printf(			"		|%0-8.5d|\n", 7);
	t =	ft_printf(			"		|%0-8.5d|\n", 7);
	result(test, t);
		printf(			"%%0-8.5d");
	test =	printf(			"		|%0-8.5d|\n", -7);
	t =	ft_printf(			"		|%0-8.5d|\n", -7);
	result(test, t);
		printf(			"%%--0.3d");
	test =	printf(			"		|%--0.3d|\n", 77);
	t =	ft_printf(			"		|%--0.3d|\n", 77);
	result(test, t);
		printf(			"%%-0.1d");
	test =	printf(			"		|%-0.1d|\n", -77);
	t =	ft_printf(			"		|%-0.1d|\n", -77);
	result(test, t);
		printf(			"%%0-5.3d");
	test =	printf(			"		|%0-5.3d|\n", 0);
	t =	ft_printf(			"		|%0-5.3d|\n", 0);
	result(test, t);

	printf("\n RESULT: %d correct out of %d tests\n\n", g_pass, g_test);

	return (0);
}
