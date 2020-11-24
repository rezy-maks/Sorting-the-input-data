#include "sorts.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10 // Количество сортируемых элементов
#define line 10
#define column 32

typedef struct DATE {
    int day;
    int month;
    int year;
} date;

int check_mass(int input[], int s)
{
    int n = s, a[n];
    for (int i = 0; i < n; i++) {
        a[i] = input[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}

int string_to_int(char* string, int size)
{
    if (size == 1 && *string == '-') {
        return -1;
    }
    if (size == 1) {
        return (*string - 0x30); //приводим к аски коду [0;9]
    }
    return string[size - 1] - 0x30
            + 10 * string_to_int(string, size - 1); //записываем число с конца
}

void numberSort(int array[], int l, int r)
{
    int i = l, j = r, x = array[(l + r) / 2], temp;

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
    if ((f = fopen("../thirdparty/testtext.txt", "r")) == NULL) {
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
    if ((f = fopen("../thirdparty/testtext.txt", "r")) == NULL) {
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
    for (i = count - 1; i > -1; i--)
        printf("%s\n", strings[i]);
    return 0;
}

int dateSort(int argc, char* argv[])
{
    int i = 0;
    int j = 0;
    int size;
    FILE *f1, *f2;
    f1 = fopen("../thirdparty/datetest.txt", "r");
    fseek(f1, 0, SEEK_END);
    size = ftell(f1);
    fseek(f1, 0, SEEK_SET);
    char* file_dates = malloc(size * (sizeof(char)));
    date* arr = malloc(size * sizeof(date));
    if (f1 != NULL) {
        while (feof(f1) == 0) {
            fscanf(f1, "%c", &file_dates[i]);
            i++;
        }
        fclose(f1);
        size = size / 11;
        for (i = 0; i < size; i++) {
            arr[i].day = 0;
            arr[i].month = 0;
            arr[i].year = 0;
            int counter = 10;
            while (file_dates[j] != '-') {
                arr[i].day = string_to_int((file_dates + j), 1) * counter
                        + arr[i].day;
                j++;
                counter = counter / 10;
            }
            j++;
            counter = 10;
            while (file_dates[j] != '-') {
                arr[i].month = string_to_int((file_dates + j), 1) * counter
                        + arr[i].month;
                j++;
                counter = counter / 10;
            }
            j++;
            counter = 1000;
            while (file_dates[j] != ' ') {
                arr[i].year = string_to_int((file_dates + j), 1) * counter
                        + arr[i].year;
                j++;
                counter = counter / 10;
            }
            j++;
        }
        printf("Массив, до сортировки:");
        for (i = 0; i < size; i++) {
            printf("%d", arr[i].day);
            printf("-");
            printf("%d", arr[i].month);
            printf("-");
            printf("%d", arr[i].year);
            printf(" ");
        }
        printf("\n");
        for (i = size - 1; i >= 0; i--) {
            for (j = 0; j < i; j++) {
                if ((arr[j].year * 10000) + (arr[j].month * 100) + (arr[j].day)
                    > (arr[j + 1].year * 10000) + (arr[j + 1].month * 100)
                            + (arr[j + 1].day)) {
                    date tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        f2 = fopen("../thirdparty/dateres.txt", "w");
        printf("Массив, записанный в файл:");
        for (i = 0; i < size; i++) {
            fprintf(f2, "%d", arr[i].day);
            printf("%d", arr[i].day);
            fprintf(f2, "-");
            printf("-");
            fprintf(f2, "%d", arr[i].month);
            printf("%d", arr[i].month);
            fprintf(f2, "-");
            printf("-");
            fprintf(f2, "%d", arr[i].year);
            printf("%d", arr[i].year);
            fprintf(f2, " ");
            printf(" ");
        }
    }
    return (0);
}

void rmassSort()
{
    int sizemass;
    printf("Введите количество сортируемых чисел:\n");
    scanf("%d", &sizemass);
    int input_numbers[sizemass];
    printf("Введите числа для сортировки в консоль.\n");

    for (int i = 0; i < sizemass; i++) {
        scanf("%d", &input_numbers[i]);
    }
    numberSort(input_numbers, 0, sizemass - 1);
    if (check_mass(input_numbers, sizemass) == 1) {
        printf("Отсортированный от большего к меньшему массив:");
        for (int i = sizemass - 1; i > -1; i--) {
            printf("%d ", input_numbers[i]);
        }
        printf("\n");
    } else
        printf("Ошибка сортировки.\n");
}

void massSort()
{
    int sizemass;
    printf("Введите количество сортируемых чисел:\n");
    scanf("%d", &sizemass);
    int input_numbers[sizemass];
    printf("Введите числа для сортировки в консоль.\n");
    for (int i = 0; i < sizemass; i++) {
        scanf("%d", &input_numbers[i]);
    }
    numberSort(input_numbers, 0, sizemass - 1);
    if (check_mass(input_numbers, sizemass) == 1) {
        printf("Отсортированный от меньшего к большему массив:");
        for (int i = 0; i < sizemass; i++) {
            printf("%d ", input_numbers[i]);
        }
        printf("\n");
    } else
        printf("Ошибка сортировки.\n");
}

void textrmassSort()
{
    FILE *f1, *f2;

    int i = 0;
    int file_numbers[N];
    f1 = fopen("../thirdparty/test.txt", "r");
    if (f1 != NULL) {
        while (feof(f1) == 0) {
            fscanf(f1, "%d ", &file_numbers[i]);
            i++;
        }
        fclose(f1);
        numberSort(file_numbers, 0, N - 1);
        if (check_mass(file_numbers, N) == 1) {
            f2 = fopen("../thirdparty/revres.txt", "w");
            printf("Массив, записанный в файл:");
            for (i = N - 1; i > -1; i--) {
                fprintf(f2, "%d ", file_numbers[i]);
                printf("%d ", file_numbers[i]);
            }
            fclose(f2);
            printf("\nОтсортированный от большего к меньшему массив "
                   "записан "
                   "в revres.txt\n");
        } else
            printf("Ошибка сортировки.\n");
    }
}

void textmassSort()
{
    FILE *f1, *f2;

    int i = 0;
    int file_numbers[N];

    f1 = fopen("../thirdparty/test.txt", "r");

    if (f1 != NULL) {
        while (feof(f1) == 0) {
            fscanf(f1, "%d ", &file_numbers[i]);
            i++;
        }
        fclose(f1);
        numberSort(file_numbers, 0, N - 1);
        if (check_mass(file_numbers, N) == 1){
        f2
                = fopen("../thirdparty/res.txt",
                        "w");
        printf("Массив, записанный в файл:");
        for (i = 0; i < N; i++) {
            fprintf(f2, "%d ", file_numbers[i]);
            printf("%d ", file_numbers[i]);
        }
        fclose(f2);
        printf("\nОтсортированный от меньшего к большему массив "
               "записан "
               "в res.txt\n");
    } else printf("Ошибка сортировки.\n");
}
}

