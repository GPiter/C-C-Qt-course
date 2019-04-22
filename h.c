#include <stdio.h>
#include "calc.h"

int a, b, sum, result;

int main(void)
{
	printf("Введите число а: ");    
    scanf("%d", &a);
	printf("Введите число b: ");    
    scanf("%d", &b);
    result = calc(a,b);
	printf("a * b = %d \n", result);
	return 0;
}

