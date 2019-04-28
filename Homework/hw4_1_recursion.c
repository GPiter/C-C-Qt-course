// Задание 4.1 Сумма чисел даты рождения через рекурсию
// Автор: Ганин П.А.

#include <stdio.h>

int main() {
	printf("Введите число, месяц и год рождения: \n");
	int date[3], i = 0;	// Создаем массив для хранения трех чисел (день, месяц, год)
	for(; i < 3; ++i)
	scanf("%d", &date[i]);

	int result = Sum(date, i);	// Передаем функции заполненный массив и его размер. После выполнения цикла переменная i = 3
	printf("Сумма чисел дня рождения: %d \n", result);

	return 0;
}


int Sum(int* date, int size)
{
    if (size > 0)
        return date[size-1] + Sum(date, size-1);
    else
        return 0;
}


/* Идея 2. Преобразовать цикл while ???

Цикл While
int i = 0;
data = 0;
while (i < 3) {
cin >> data;
data += data;
i++;
}

======

Рекурсия
i = 3;
int fun(int i) {

scanf("%d", data);
if (i == 0) return data;
else return data + fun(data) --i;

}

*/





