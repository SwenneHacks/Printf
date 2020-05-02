
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
		printf("				pf[%d]\n", test);
		printf("				ft[%d]\n\n", ft);
	}
	g_test++;
}

int		main(void)
{
	int				test;
	int				t;
	g_pass 			= 0;
	g_test			= 0;

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
	
	ft_putstr("\n_____________________________________ TO FIX: \n\n");

	test =	printf(			"%%10.5d,-	|%10.5d|\n", -55);
	t =	ft_printf(			"%%10.5d,-	|%10.5d|\n", -55);
	result(test, t);
	test =	printf(			"%%-8.5d,-	|%-8.5d|\n", -55);
	t =	ft_printf(			"%%-8.5d,-	|%-8.5d|\n", -55);
	result(test, t);
	test =	printf(		"%%08.5d		|%08.5d|\n", 55);
	t =	ft_printf(		"%%08.5d		|%08.5d|\n", 55);
	result(test, t);
	test =	printf(			"%%08.5d,-	|%08.5d|\n", -55);
	t =	ft_printf(			"%%08.5d,-	|%08.5d|\n", -55);
	result(test, t);
	test =	printf(		"%%3.7d,-		|%3.7d|\n", -55);
	t =	ft_printf(		"%%3.7d,-		|%3.7d|\n", -55);
	result(test, t);
	test =	printf(			"%%3.7d		|%3.7d|\n", 55);
	t =	ft_printf(			"%%3.7d		|%3.7d|\n", 55);
	result(test, t);
	test =	printf(		"%%--3.7d		|%----3.7d|\n", 55);
	t =	ft_printf(		"%%--3.7d		|%----3.7d|\n", 55);
	result(test, t);
	test =	printf(			"%%0-8.5d,-	|%0-8.5d|\n", -55);
	t =	ft_printf(			"%%0-8.5d,-	|%0-8.5d|\n", -55);
	result(test, t);
	test =	printf(		"%%0-5.3d,07	|%0-5.3d|\n", 07);
	t =	ft_printf(		"%%0-5.3d,07	|%0-5.3d|\n", 07);
	result(test, t);
	test =	printf(			"%%0-5.3d,0	|%0-5.3d|\n", 0);
	t =	ft_printf(			"%%0-5.3d,0	|%0-5.3d|\n", 0);
	result(test, t);

	printf("\n RESULT: %d correct out of %d tests\n\n", g_pass, g_test);

	return (0);
}
