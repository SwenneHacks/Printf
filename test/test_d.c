
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
	int				t;
	g_pass 			= 0;
	g_test			= 0;

	ft_putstr("_____________________________________ NEG.: \n\n");

		printf(			"%%i");
	test =	printf(			"		|%i|\n", -7);
	t =	ft_printf(			"		|%i|\n", -7);
	result(test, t);
		printf(			"%%d");
	test =	printf(			" 		|%d|\n", -7);
	t =	ft_printf(			" 		|%d|\n", -7);
	result(test, t);
		printf(			"%%05d");
	test =	printf(			" 		|%05d|\n", -7);
	t =	ft_printf(			" 		|%05d|\n", -7);
	result(test, t);
		printf(			"%%5d");
	test =	printf(			" 		|%5d|\n", -7);
	t =	ft_printf(			" 		|%5d|\n", -7);
	result(test, t);
		printf(			"%%*d");
	test =	printf(			"		|%*d|\n", 4, +7);
	t =	ft_printf(			"		|%*d|\n", 4, +7);
	result(test, t);
		printf(			"%%.1d");
	test =	printf(			"		|%.1d|\n", -7);
	t =	ft_printf(			"		|%.1d|\n", -7);
	result(test, t);
		printf(			"%%0.5d");
	test =	printf(			"		|%0.5d|\n", -7);
	t =	ft_printf(			"		|%0.5d|\n", -7);
	result(test, t);
		printf(			"%%.5d");
	test =	printf(			"		|%.5d|\n", -7);
	t =	ft_printf(			"		|%.5d|\n", -7);
	result(test, t);
		printf(			"%%-8.5d");
	test =	printf(			"		|%-8.5d|\n", -217);
	t =	ft_printf(			"		|%-8.5d|\n", -217);
	result(test, t);
		printf(			"%%-3.3d");
	test =	printf(			"		|%-3.3d|\n", -8375);
	t =	ft_printf(			"		|%-3.3d|\n", -8375);
	result(test, t);
		printf(			"%%-3.7d");
	test =	printf(			"		|%-3.7d|\n", -2375);
	t =	ft_printf(			"		|%-3.7d|\n", -2375);
	result(test, t);

ft_putstr("_____________________________________ PRECI.: \n");

		printf(			"%%-8.3d");
	test =	printf(			"		|%-8.3d|\n", 8375);
	t =	ft_printf(			"		|%-8.3d|\n", 8375);
	result(test, t);
		printf(			"%%-3.3d");
	test =	printf(			"		|%-3.3d|\n", 6983);
	t =	ft_printf(			"		|%-3.3d|\n", 6983);
	result(test, t);
		printf(			"%%.1d");
	test =	printf(			"		|%.1d|\n", 55);
	t =	ft_printf(			"		|%.1d|\n", 55);
	result(test, t);
		printf(			"%%5.1d");
	test =	printf(			"		|%5.1d|\n", 55);
	t =	ft_printf(			"		|%5.1d|\n", 55);
	result(test, t);
		printf(			"%%8.5d");
	test =	printf(			"		|%8.5d|\n", 55);
	t =	ft_printf(			"		|%8.5d|\n", 55);
	result(test, t);
		printf(			"%%-8.5d");
	test =	printf(			"		|%-8.5d|\n", 55);
	t =	ft_printf(			"		|%-8.5d|\n", 55);
	result(test, t);
		printf(			"%%.5d");
	test =	printf(			"		|%.5d|\n", 55);
	t =	ft_printf(			"		|%.5d|\n", 55);
	result(test, t);
		printf(			"%%-3.7d");
	test =	printf(			"		|%-3.7d|\n", 3267);
	t =	ft_printf(			"		|%-3.7d|\n", 3267);
	result(test, t);
		printf(			"%%3.7d");
	test =	printf(			"		|%3.7d|\n", 55);
	t =	ft_printf(			"		|%3.7d|\n", 55);
	result(test, t);
		printf(			"%%--3.7d");
	test =	printf(			"		|%----3.7d|\n", 55);
	t =	ft_printf(			"		|%----3.7d|\n", 55);
	result(test, t);
		printf(			"%%0-5.3d");
	test =	printf(			"		|%0-5.3d|\n", 07);
	t =	ft_printf(			"		|%0-5.3d|\n", 07);
	result(test, t);

ft_putstr("_____________________________________ ZEROS: \n\n");

		printf(			"%%d,0");
	test =	printf(			"		|%d|\n", 0);
	t =	ft_printf(			"		|%d|\n", 0);
	result(test, t);
		printf(			"%%.d,0");
	test =	printf(			"		|%.d|\n", 0);
	t =	ft_printf(			"		|%.d|\n", 0);
	result(test, t);
		printf(			"%%.5d");
	test =	printf(			"		|%.5d|\n", 0);
	t =	ft_printf(			"		|%.5d|\n", 0);
	result(test, t);
		printf(			"%%.0d");
	test =	printf(			"		|%.0d|\n", 0);
	t =	ft_printf(			"		|%.0d|\n", 0);
	result(test, t);
		printf(			"%%-1.d");
	test =	printf(			"		|%-1.d|\n", 0);
	t =	ft_printf(			"		|%-1.d|\n", 0);
	result(test, t);
		printf(			"%%-8.5d");
	test =	printf(			"		|%-8.5d|\n", 0);
	t =	ft_printf(			"		|%-8.5d|\n", 0);
	result(test, t);
		printf(			"%%5d");
	test =	printf(			"		|%5d|\n", 0);
	t =	ft_printf(			"		|%5d|\n", 0);
	result(test, t);
		printf(			"%%03d");
	test =	printf(			"		|%05d|\n", 0);
	t =	ft_printf(			"		|%05d|\n", 0);
	result(test, t);
		printf(			"%%-3d");
	test =	printf(			" 		|%-5d|\n", 0);
	t =	ft_printf(			" 		|%-5d|\n", 0);
	result(test, t);
		printf(			"%%08.5d");
	test =	printf(			"		|%08.5d|\n", 0);
	t =	ft_printf(			"		|%08.5d|\n", 0);
	result(test, t);
		printf(			"%%8.5d");
	test =	printf(			"		|%8.5d|\n", 0);
	t =	ft_printf(			"		|%8.5d|\n", 0);
	result(test, t);

ft_putstr("_____________________________________ TO FIX: \n");
		printf(			"%%0-5.3d");
	test =	printf(			"		|%0-5.3d|\n", 0);
	t =	ft_printf(			"		|%0-5.3d|\n", 0);
	result(test, t);
		printf(			"%%10.5d");
	test =	printf(			"		|%10.5d|\n", -55);
	t =	ft_printf(			"		|%10.5d|\n", -55);
	result(test, t);
		printf(			"%%-8.5d");
	test =	printf(			"		|%-8.5d|\n", -55);
	t =	ft_printf(			"		|%-8.5d|\n", -55);
	result(test, t);
		printf(			"%%08.5d");
	test =	printf(			"		|%08.5d|\n", -55);
	t =	ft_printf(			"		|%08.5d|\n", -55);
	result(test, t);
		printf(			"%%3.7d");
	test =	printf(			"		|%3.7d|\n", -55);
	t =	ft_printf(			"		|%3.7d|\n", -55);
	result(test, t);
		printf(			"%%0-8.5d");
	test =	printf(			"		|%0-8.5d|\n", -55);
	t =	ft_printf(			"		|%0-8.5d|\n", -55);
	result(test, t);
		printf(			"%%08.5d");
	test =	printf(			"		|%08.5d|\n", 55);
	t =	ft_printf(			"		|%08.5d|\n", 55);
	result(test, t);
	
	printf("\n RESULT: %d correct out of %d tests\n\n", g_pass, g_test);

	return (0);
}
