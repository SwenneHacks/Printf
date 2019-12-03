/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh ,swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:55:08 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/03 18:59:45 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *str);
char 	*ft_strrev(char *str);
void	ft_swap(int *a, int *b);

char 	*ft_itoa_base(int nbr, char *str, int base) 
{
    int i = 0;
	int convert;

	if (base == 10)
		str = ft_itoa(nbr);
    while (nbr != 0)
    {
        convert = nbr % base; 
        str[i++] = (convert > 9)? (convert - 10) + 'a' : convert + '0'; 
        nbr = nbr/base; 
    }
    str[i] = '\0';
    ft_strrev(str);
    return (str);
}

//Reverse string
char	*ft_strrev(char *str)
{
	char	rev;
	int		len;
	int		index;

	len = ft_strlen(str);
	index = 0;
	while (index < len / 2)
	{
		rev = str[index];
		str[index] = str[len - index - 1];
		str[len - index - 1] = rev;
		index++;
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

// Driver program to test implementation of itoa() 
int main() 
{ 
    char str[100]; 
    printf("Base:10 %s\n", ft_itoa_base(1567, str, 10)); 
    printf("Base:10 %s\n", ft_itoa_base(-1567, str, 10)); 
    printf("Base:2 %s\n", ft_itoa_base(1567, str, 2)); 
    printf("Base:8 %s\n", ft_itoa_base(1567, str, 8)); 
    printf("Base:16 %s\n", ft_itoa_base(1567, str, 16)); 
    return 0; 
} 

// // Implementation of itoa_base() 
// char 	*ft_itoa_base(int num, char *str, int base) 
// { 
//     int i = 0; 
//     int isNegative = 1; 
  
//     /* Handle 0 explicitely, otherwise empty string is printed for 0 */
//     if (num == 0) 
//     { 
//         str[i++] = '0'; 
//         str[i] = '\0'; 
//         return str; 
//     } 
  
//     // In standard itoa(), negative numbers are handled only with  
//     // base 10. Otherwise numbers are considered unsigned. 
//     if (num < 0 && base == 10) 
//     { 
//         isNegative = 0; 
//         num = -num; 
//     } 
  
//     // Process individual digits 
//     while (num != 0) 
//     { 
//         int rem = num % base; 
//         str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
//         num = num/base; 
//     } 
  
//     // If number is negative, append '-' 
//     if (isNegative) 
//         str[i++] = '-'; 
  
//     str[i] = '\0'; // Append string terminator 
  
//     // Reverse the string 
//     reverse(str);
  
//     return (str); 
// }
