/* Задание 7. Телефонный справочник
 * Размер тел. справочника задется параметром SIZE
 * Макс. длина имени и тел.номера = 20 символов
 * Ввод имени осуществлять английской раскладкой
 * -----------------------------------------------
 * Автор: Ганин П.А.
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100

struct PhoneBook{
    char name[20];
    char number[20];
} person[SIZE];

int main() {
    char find_person[20];
    int choice;
    char flag;
    int flag_search = 0;
    int i = 0, n = 0, j = 0, k = 0;
    int count = 0;
    FILE * pFile;

Start:
    printf("1. Добавить контакт \n2. Запись в файл \n3. Показать телефонный справочник \n4. Поиск номера \n5. Выход \n>> ");
    scanf("%d", &choice);
    switch(choice) {

        case 1:
            for (i; i < SIZE; i++) {
            printf("Введите имя: ");
            scanf("%s", &person[i].name);
            printf("Введите телефон: ");
            scanf("%s", &person[i].number);
            count++;
            printf("Ввести снова? Y - yes, N - no > ");
            scanf(" %c", &flag);
            if ( (flag != 'Y') && (flag != 'y') ) goto Start;
            }
            break;

        case 2:
            pFile = fopen ("Contacts.txt","w");
            fprintf (pFile, "\t\tИмя  | \t Телефон \n");
            for (n = 0; n < count; n++)          
            fprintf (pFile, "%10s \t |  %10s \n", person[n].name, person[n].number);
            fclose (pFile);
            printf("Запись в файл......\n Завершено.\n \n");
            goto Start;
            break;
            
        case 3:
            printf("\tИмя \t | \t Телефон \n");
            for (j = 0; j < count; j++)
            printf("%10s \t |  %10s \n", person[j].name, person[j].number);

            printf("Вернуться в главное меню? Y - yes, N - no > ");
            scanf(" %c", &flag);
            if ((flag == 'Y')||(flag == 'y')) goto Start;

            break;
            
        case 4:
            printf("Введите имя, телефон которого хотите узнать: ");
            flag_search = 0;
            scanf("%s", find_person);
            
            for (k = 0; !flag_search && (k < count); k++) {
                if (strcmp(person[k].name, find_person) == 0) {
                    flag_search = 1;
                    printf("%s имеет телефон: %s \n", person[k].name, person[k].number);
                }
            }
            if (!flag_search) printf("Указанного имени нет в справочнике.\n");

            printf("Вернуться в главное меню? Y - yes, N - no > ");
            scanf(" %c", &flag);
            if ((flag == 'Y')||(flag == 'y')) goto Start;
            break;
        
        case 5:
            printf("Всего доброго! Спасибо, что воспользовались моим приложением!\n");
            break;            

    }

}
