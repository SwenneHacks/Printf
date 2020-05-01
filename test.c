#include "printf.h"

void	result(int test, int ft)
{
	if (test == ft)
	{
		ft_putstr("				PASS\n");
		g_pass ++;
	}
	else
	{
		ft_putstr("				FAIL\n");
		printf("				pf[%d]\n", test);
		printf("				ft[%d]\n\n", ft);
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

// ft_putstr("\n_____________________________ BONUS: \n\n");
	
// 	test =	printf(		"%% d 		|% d|\n", i);
// 	t =	ft_printf(		"%% d 		|% d|\n", i);
// 	result(test, t);
// 	test =	printf(		"%%  d 		|%  d|\n", i);
// 	t =	ft_printf(		"%%  d 		|%  d|\n", i);
// 	result(test, t);
// 	test =	printf(	"%% d, 0 		|% d|\n",  0);
// 	t =	ft_printf(	"%% d, 0 		|% d|\n",  0);
// 	result(test, t);
// 	test =	printf(		"%% -4d,55 	|% -4d|\n", d);
// 	t =	ft_printf(		"%% -4d,55 	|% -4d|\n", d);
// 	result(test, t);
// 	test =	printf(		"%%+-.1d,-	|%+-.1d|\n", i);
// 	t =	ft_printf(		"%%+-.1d,-	|%+-.1d|\n", i);
// 	result(test, t);
// 	test =	printf(		"%%+-2.d,0	|%+-2.d|\n", 0);
// 	t =	ft_printf(		"%%+-2.d,0	|%+-2.d|\n", 0);
// 	result(test, t);
// 	test =	printf(		"%%+3.d, 0	|%+3.d|\n", 0);
// 	t =	ft_printf(		"%%+3.d, 0	|%+3.d|\n", 0);
// 	result(test, t);
// 	test =	printf(		"%% .3d,5 	|% .3d|\n", 5);
// 	t =	ft_printf(		"%% .3d,5 	|% .3d|\n", 5);
// 	result(test, t);
// 	test =	printf(		"%% -.3d,- 	|% -.3d|\n", i);
// 	t =	ft_printf(		"%% -.3d,- 	|% -.3d|\n", i);
// 	result(test, t);
// 	test =	printf(	"%% 08.5d		|% 08.5d|\n", 0);
// 	t =	ft_printf(	"%% 08.5d		|% 08.5d|\n", 0);
// 	result(test, t);
// 	test =	printf(		"%% -5d,- 	|% -5d|\n", i);
// 	t =	ft_printf(		"%% -5d,- 	|% -5d|\n", i);
// 	result(test, t);

	ft_putstr("_____________________________________ DONE: \n\n");

//_______________________________________________________ DIGITS
	test =	printf(			"%%i 		|%i|\n", -7);
	t =	ft_printf(			"%%i 		|%i|\n", -7);
	result(test, t);
	test =	printf(			"%%d 		|%d|\n", -7);
	t =	ft_printf(			"%%d 		|%d|\n", -7);
	result(test, t);
	test =	printf(			"%%d,0		|%d|\n", 0);
	t =	ft_printf(			"%%d,0		|%d|\n", 0);
	result(test, t);
	test =	printf(			"%%05d 		|%05d|\n", -7);
	t =	ft_printf(			"%%05d 		|%05d|\n", -7);
	result(test, t);
	test =	printf(			"%%5d 		|%5d|\n", -7);
	t =	ft_printf(			"%%5d 		|%5d|\n", -7);
	result(test, t);
	test =	printf(			"%%*d		|%*d|\n", 4, +7);
	t =	ft_printf(			"%%*d		|%*d|\n", 4, +7);
	result(test, t);
	test =	printf(			"%%.1d		|%.1d|\n", -7);
	t =	ft_printf(			"%%.1d		|%.1d|\n", -7);
	result(test, t);
	test =	printf(			"%%0.5d		|%0.5d|\n", -7);
	t =	ft_printf(			"%%0.5d		|%0.5d|\n", -7);
	result(test, t);
	test =	printf(			"%%.1d		|%.1d|\n", 55);
	t =	ft_printf(			"%%.1d		|%.1d|\n", 55);
	result(test, t);
	test =	printf(			"%%5.1d		|%5.1d|\n", 55);
	t =	ft_printf(			"%%5.1d		|%5.1d|\n", 55);
	result(test, t);
	test =	printf(			"%%.d,0		|%.d|\n", 0);
	t =	ft_printf(			"%%.d,0		|%.d|\n", 0);
	result(test, t);
	test =	printf(			"%%.5d		|%.5d|\n", 55);
	t =	ft_printf(			"%%.5d		|%.5d|\n", 55);
	result(test, t);
	test =	printf(		"%%.5d,-		|%.5d|\n", -7);
	t =	ft_printf(		"%%.5d,-		|%.5d|\n", -7);
	result(test, t);
	test =	printf(		"%%.5d,0		|%.5d|\n", 0);
	t =	ft_printf(		"%%.5d,0		|%.5d|\n", 0);
	result(test, t);
	test =	printf(		"%%.0d,0		|%.0d|\n", 0);
	t =	ft_printf(		"%%.0d,0		|%.0d|\n", 0);
	result(test, t);
	test =	printf(		"%%-1.d,0		|%-1.d|\n", 0);
	t =	ft_printf(		"%%-1.d,0		|%-1.d|\n", 0);
	result(test, t);
	test =	printf(		"%%-8.5d		|%-8.5d|\n", 0);
	t =	ft_printf(		"%%-8.5d		|%-8.5d|\n", 0);
	result(test, t);
	test =	printf(		"%%-8.5d		|%-8.5d|\n", -217);
	t =	ft_printf(		"%%-8.5d		|%-8.5d|\n", -217);
	result(test, t);
	test =	printf(		"%%-8.5d		|%-8.5d|\n", 55);
	t =	ft_printf(		"%%-8.5d		|%-8.5d|\n", 55);
	result(test, t);
	test =	printf(		"%%-3.3d		|%-3.3d|\n", 6983);
	t =	ft_printf(		"%%-3.3d		|%-3.3d|\n", 6983);
	result(test, t);
	test =	printf(		"%%-3.3d		|%-3.3d|\n", -8375);
	t =	ft_printf(		"%%-3.3d		|%-3.3d|\n", -8375);
	result(test, t);
	test =	printf(		"%%-8.3d		|%-8.3d|\n", 8375);
	t =	ft_printf(		"%%-8.3d		|%-8.3d|\n", 8375);
	result(test, t);
	test =	printf(		"%%-3.7d		|%-3.7d|\n", 3267);
	t =	ft_printf(		"%%-3.7d		|%-3.7d|\n", 3267);
	result(test, t);
	test =	printf(		"%%-3.7d		|%-3.7d|\n", -2375);
	t =	ft_printf(		"%%-3.7d		|%-3.7d|\n", -2375);
	result(test, t);
	test =	printf(			"%%3d 		|%5d|\n", 0);
	t =	ft_printf(			"%%3d 		|%5d|\n", 0);
	result(test, t);
	test =	printf(			"%%03d 		|%05d|\n", 0);
	t =	ft_printf(			"%%03d 		|%05d|\n", 0);
	result(test, t);
	test =	printf(			"%%-3d 		|%-5d|\n", 0);
	t =	ft_printf(			"%%-3d 		|%-5d|\n", 0);
	result(test, t);
	test =	printf(			"%%08.5d,0	|%08.5d|\n", 0);
	t =	ft_printf(			"%%08.5d,0	|%08.5d|\n", 0);
	result(test, t);
	test =	printf(		"%%8.5d,0		|%8.5d|\n", 0);
	t =	ft_printf(		"%%8.5d,0		|%8.5d|\n", 0);
	result(test, t);
	test =	printf(			"%%8.5d,55	|%8.5d|\n", 55);
	t =	ft_printf(			"%%8.5d,55	|%8.5d|\n", 55);
	result(test, t);
	
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
//____________________________________________________________ STRINGS
	test =	printf(			"%%5s 		|%5s|\n", s);
	t =	ft_printf(			"%%5s 		|%5s|\n", s);
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
//___________________________________________________________ UNSIGNED
	test =	printf(			"%%u 		|%u|\n", d);
	t =	ft_printf(			"%%u 		|%u|\n", d);
	result(test, t);
//_____________________________________________________________ OCTA
	test =	printf(			"%%o 		|%o|\n", d);
	t =	ft_printf(			"%%o 		|%o|\n", d);
	result(test, t);
	
	ft_putstr("\n_____________________________________ TO FIX: \n\n");

	test =	printf(			"%%u 		|%u|\n", i);
	t =	ft_printf(			"%%u 		|%u|\n", i);
	result(test, t);

	printf("\n RESULT: %d correct out of %d tests\n\n", g_pass, g_test);

	return (0);
}
/*
Test 538 (d_prec_width_fit_fit_pos) : FAILED.
    First line of code: {return test("%8.5d", 34);}
      expected output : "   00034"
      your output     : "      34"
      expected (nonprintable as hex) : "   00034"
      actual   (nonprintable as hex) : "      34"

Test 539 (d_prec_width_fit_fit_neg) : FAILED.
    First line of code: {return test("%10.5d", -216);}
      expected output : "    -00216"
      your output     : "      -216"
      expected (nonprintable as hex) : "    -00216"
      actual   (nonprintable as hex) : "      -216"

Test 540 (d_prec_width_fit_fit_zero) : FAILED.
    First line of code: {return test("%8.5d", 0);}
      expected output : "   00000"
      your output     : "00000"
      expected (nonprintable as hex) : "   00000"
      actual   (nonprintable as hex) : "00000"

Test 543 (d_prec_width_fit_nofit_pos) : FAILED.
    First line of code: {return test("%3.7d", 3267);}
      expected output : "0003267"
      your output     : "3267"
      expected (nonprintable as hex) : "0003267"
      actual   (nonprintable as hex) : "3267"

Test 544 (d_prec_width_fit_nofit_neg) : FAILED.
    First line of code: {return test("%3.7d", -2375);}
      expected output : "-0002375"
      your output     : "-2375"
      expected (nonprintable as hex) : "-0002375"
      actual   (nonprintable as hex) : "-2375"

Test 548 (d_prec_width_fit_fit_neg_lj) : FAILED.
    First line of code: {return test("%-10.5d", -216);}
      expected output : "-00216    "
      your output     : "-00216  "
      expected (nonprintable as hex) : "-00216    "
      actual   (nonprintable as hex) : "-00216  "

Test 551 (d_prec_width_nofit_fit_neg_lj) : FAILED.
    First line of code: {return test("%-8.3d", -8473);}
      expected output : "-8473   "
      your output     : "-8473    "
      expected (nonprintable as hex) : "-8473   "
      actual   (nonprintable as hex) : "-8473    "
	  */