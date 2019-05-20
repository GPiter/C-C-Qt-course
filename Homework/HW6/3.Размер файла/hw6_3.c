/* Задание 6.3 Реализовать программу, вычитывающую текст из файла(до 100000 символов) и считающую размер считанных данных.
   За основу взята программа задания 5.2. Добавлена переменная size для подсчета размера считанных символов с помощью ключевого слова sizeof.
   1) Функция memset заполняет num байтов блока памяти, через указатель memptr. Код заполняемого символа передаётся в функцию через параметр val.
   Протоип функции: void * memset( void * memptr, int val, size_t num );
   В качестве * memptr в данном задании передаем массив словаря Vocab[256].
   2) Функция feof проверяет, достигнут ли конец файла, связанного с потоком, через параметр filestream.
   int feof ( FILE * filestream );

   Автор: Ганин П.А.
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
  int size = 0;

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
    if (Vocab[i]) {
      printf("Символ %c : %5u раз\n", i, Vocab[i]);
      size = size + sizeof(Vocab[i]); // Размер считанных символов
    }
    
    printf("Размер считанных символов = %d байт\n", size);
  
}
