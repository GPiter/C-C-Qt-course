// Задание 4_2: Функция, создающая n файлов и заполняющая m случайными цифрами
// Автор: Ганин П.А.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number_of_files, i, n; // переменные для создания файлов
  char buf[256];
  char *name = "text";
  char *suff = ".txt";

  int number_of_num, number; // переменные для генерации случайных чисел

  FILE *f;
 
  printf("Введите количество создаваемых файлов: ");
  scanf("%d", &number_of_files);

  printf("Введите количество создаваемых чисел: ");
  scanf("%d", &number_of_num);
 
  for ( i = 1; i <= number_of_files; ++i ) {
    sprintf(buf, "%s %d %s", name, i, suff);
    if ( ( f = fopen(buf, "w") ) == NULL )
    printf("Файл невозможно открыть или создать\n");
    else {
	for (n = 1; n <= number_of_num; ++n){	
	number = -100 + rand() % 200;
	fprintf(f, "%d\n", number);
	}
    }
    fclose(f);
  }
  return 0;
}
