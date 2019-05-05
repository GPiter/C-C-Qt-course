// Задание 3.1 Цикл в цикле в цикле
// Автор: Ганин П.А.

#include <stdio.h>

int main() {
	int i = 0;
	int j = 1;
	int k;

	do {
	// Первый вложенный цикл while
	while (j <= 5) {
        printf("Параметр j цикла while: %d\n", j);
	j++;	
		// Второй вложенный цикл for
		for ( k = 0; k < 10; k++ ) { 
        	printf("Параметр k цикла for: %d\n", k );	
    		}
	}

	printf("Цикл do while выполнен.\n");
	} while (i != 0);

	return 0;

}
