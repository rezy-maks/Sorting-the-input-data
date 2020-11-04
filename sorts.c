#include "sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define line 10 //(для Кира) количество строк (для vocabularySort)
#define column 32 //(для Кира) количество столбцов (для vocabularySort)

void numberSort(
        int array[],
        int l,
        int r) //(для Кира) если ввести массив чисел (array), нулевой (l) и
               //последний (r) эллемент, то функция их отсортирует (наверное
               //¯\_(ツ)_/¯). В функции нет вывода массива
{
    int i = l, j = r, x = array[(l + r) / 2],
        temp; // для упорядочивания чисел был выбран метод сортировки QuickSort

    do {
        while (array[i] < x)
            i++;
        while (array[j] > x)
            j--;

        if (i <= j) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < r)
        numberSort(array, i, r);
    if (l < j)
        numberSort(array, l, j);
}

void vocabularySort() //(для Кира) функция работает, использует bubbleSort. В
                      //этой вариации сортирует из заранее созданного текстового
                      //файла.
{
    char strings[line][column], str[column];
    FILE* f;
    int count = 0, i, j;
    if ((f
         = fopen("/home/killreal/TRPO/Sorting-the-input-data/testtext.txt",
                 "r"))
        == NULL) {
        return 1;
    }
    /* Считываем слова из файла */
    while (feof(f) == 0 || count > 10) {
        fscanf(f, "%s", str);
        strcpy(strings[count++], str);
    }
    fclose(f);
    /* Выводим считаные строки */
    for (i = 0; i < count; i++)
        printf("%s\n", strings[i]);
    putchar('\n');
    /* Сортировка методом пузырька */
    for (i = 1; i < count; i++)
        for (j = 0; j < count - i; j++)
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                strcpy(str, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], str);
            }
    /* Выводим отсортированные строки */
    for (i = 0; i < count; i++)
        printf("%s\n", strings[i]);
    return 0;
}

void rvocabularySort()
{
    char strings[line][column], str[column];
    FILE* f;
    int count = 0, i, j;
    if ((f
         = fopen("/home/killreal/TRPO/Sorting-the-input-data/testtext.txt",
                 "r"))
        == NULL) {
        return 1;
    }
    /* Считываем слова из файла */
    while (feof(f) == 0 || count > 10) {
        fscanf(f, "%s", str);
        strcpy(strings[count++], str);
    }
    fclose(f);
    /* Выводим считаные строки */
    for (i = 0; i < count; i++)
        printf("%s\n", strings[i]);
    putchar('\n');
    /* Сортировка методом пузырька */
    for (i = 1; i < count; i++)
        for (j = 0; j < count - i; j++)
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                strcpy(str, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], str);
            }
    /* Выводим отсортированные строки */
    for (i = count - 1; i > 0; i--)
        printf("%s\n", strings[i]);
    return 0;
}
