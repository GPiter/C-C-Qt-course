/* Задание 6.2 2 Написать функцию,  в которой вы используете все ключевые слова Си.
   Автор: Ганин П.А.
*/

#include <stdio.h>

extern int x, y;
typedef float MY_FLOAT;
MY_FLOAT numb = 1.0002;

volatile int var = 1;
void Function() {

    start:
    if (var == 1)
        goto start;
    else
        printf("It's ok!\n");
}

int main()
{
    const volatile int local = 10;
    int *ptr = (int*) &local;
    printf("1) volatile work example: \n");
    printf("Initial value of local : %d \n", local);
    *ptr = 100;
    printf("Modified value of local: %d \n", local);

    printf("2) typedef work example: \n");
    printf("My type number = : %f \n", numb);

    printf("3) sizeof work example: \n");
    float size = sizeof numb;
    printf("Size of my number = : %f bytes\n", size);

    return 0;

}
