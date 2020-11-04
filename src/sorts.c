#include "sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define line 10 
#define column 32 

void numberSort(
        int array[],
        int l,
        int r) 
{
    int i = l, j = r, x = array[(l + r) / 2],
        temp; 

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

int vocabularySort() 
{
    char strings[line][column], str[column];
    FILE* f;
    int count = 0, i, j;
    if ((f
         = fopen("/home/killreal/TRPO/Sorting-the-input-data/thirdparty/"
                 "testtext.txt",
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

int rvocabularySort()
{
    char strings[line][column], str[column];
    FILE* f;
    int count = 0, i, j;
    if ((f
         = fopen("/home/killreal/TRPO/Sorting-the-input-data/thirdparty/"
                 "testtext.txt",
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
    for (i = count - 1; i > -1; i--)
        printf("%s\n", strings[i]);
    return 0;
}
