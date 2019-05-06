// Задание 5_1 Заполнение массива char 1000 случайными символами
// Автор: Ганин П.А.

#include <stdio.h>
#include <stdlib.h>

int main() {

	char array[1000];
	int i = 0;
	for (i = 0; i <= 999; ++i) {
	array[i] = rand() % 47;
	printf("%c\n", array[i]);
	}
	return 0;
}
