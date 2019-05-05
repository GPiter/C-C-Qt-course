/* Задание 5.2 Определить частоту используемых символов из файла
   В данной программе используются функции:
   1) Функция memset заполняет num байтов блока памяти, через указатель memptr. Код заполняемого символа передаётся в функцию через параметр val.
   void * memset( void * memptr, int val, size_t num );
   2) Функция feof проверяет, достигнут ли конец файла, связанного с потоком, через параметр filestream.
   int feof ( FILE * filestream );
*/

#include <stdio.h>
#include <string.h>

// Создание словаря
unsigned Vocab[256];

void main( void )
{
  char Name[12];
  FILE *F;
  int i;

  printf("Введите имя файла: ");
  scanf("%s", Name);
  if ((F = fopen(Name, "rt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для чтения файл '%s'\n", Name);
    return;
  }

  /* Обнуление словаря */
  memset(Vocab, 0, 256 * sizeof(unsigned));

  /* Заполнение словаря */
  while (!feof(F))
    Vocab[fgetc(F)] ++;

  printf("Частоты появления символов:\n");
  for (i = 0; i < 256; i ++)
    if (Vocab[i])
      printf("Символ %c : %5u раз\n", i, Vocab[i]);
}

