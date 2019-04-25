// Задание 3_1. Switch_case
// Калькулятор из простых арифметических действий (+, -, *, /)
// Автор: Ганин П.А.

#include <stdio.h>

int main() {
    char operation;
    float numb1, numb2, result;

    printf("Введите первое число, операцию и второе число: \n");
    scanf("%f %c %f", &numb1, &operation, &numb2);

    switch (operation) {
    case '+':
    result = numb1 + numb2;
    printf("%f %c %f = %f \n",numb1, operation, numb2, result);
    break;
    
    case '-':
    result = numb1 - numb2;
    printf("%f %c %f = %f \n",numb1, operation, numb2, result);
    break;

    case '*':
    result = numb1 * numb2;
    printf("%f %c %f = %f \n",numb1, operation, numb2, result);
    break;

    case '/':
    if (numb2 == 0) {
    printf("Деление на 0 запрещено!\n");
    }
    else {
    result = numb1 / numb2;
    printf("%f %c %f = %f \n",numb1, operation, numb2, result);
    }
    break;

    default:
    printf("Вы ввели неверную операцию! \n");
    break;
    }

    return 0;
}
