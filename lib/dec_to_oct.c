/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dec_to_oct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:37:29 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/03 17:58:46 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to octal 
int		ft_amount(int n)
{
	int amount;

	amount = 0;
	if (n == 0)
		amount++;
	while (n > 0)
	{
		n = n / 8;
		amount++;
	}
	return (amount);
}

char	*dec_to_octal(int n)
{
    // array to store octal number
    char *octalNum;

    // counter for octal number array
    int i = 0;
	
	i = ft_amount(n);
	printf("amount = %i\n", i);
	octalNum = malloc(sizeof(char) * (i + 1));
	octalNum[i] = '\0';
    while (n != 0) 
	{
        // storing remainder in octal array 
		i--;
        octalNum[i] = n % 8 - 48;
		printf("stored = %c\n", octalNum[i]);
        n = n / 8;
    }
	return (octalNum);
}

// Driver program to test above function 
int main() 
{
    int n = '!';

    printf("%s", dec_to_octal(n));

    return 0;
} 
