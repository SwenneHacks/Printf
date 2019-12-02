/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh ,swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:55:08 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/02 17:35:42 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Implementation of itoa_base() 
char 	*ft_itoa_base(int num, char *str, int base) 
{ 
    int i = 0; 
    int isNegative = 1; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = 0; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    ft_reverse(str); 
  
    return str; 
} 

//Reverse string
void 	ft_reverse(char *str) 		
{
	size_t len;
	
	len = ft_strlen(str);
    int start = 0; 
    int end = len -1; 
    while (start < end) 
    { 
        ft_swap((str + start), (str + end)); 
        start++; 
        end--; 
    } 
}

size_t	ft_strlen(const char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Driver program to test implementation of itoa() 
int main() 
{ 
    char str[100]; 
    printf("Base:10 %s", ft_itoa_base(1567, str, 10)); 
    printf("Base:10 %s", ft_itoa_base(-1567, str, 10)); 
    printf("Base:2 %s", ft_itoa_base(1567, str, 2)); 
    printf("Base:8 %s", ft_itoa_base(1567, str, 8)); 
    printf("Base:16 %s", ft_itoa_base(1567, str, 16)); 
    return 0; 
} 
