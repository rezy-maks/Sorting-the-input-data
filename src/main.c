#include "sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10 //Количество целых чисел для сортировки

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("Список доступных ключей:\n");
        printf("-nt - сортировка из файла от меньшего к большему, результат "
               "записывается в файл\n");
        printf("-rnt - сортировка из файла от большего к меньшему, результат "
               "записывается в файл\n");
        printf("-nc - сортировка от меньшего к большему из входных данных, "
               "введённых в консоль, результат выводится в консоль\n");
        printf("-rnc - сортировка от большего к меньшему из входных данных, "
               "введённых в консоль, результат выводится в консоль\n");
        printf("-tf - сортировка текста в алфавитном порядке, заданного "
               "файлом, результат выводится в консоль (чувствителена к "
               "регистру)\n");
        printf("-rtf - сортировка текста в обратном алфавитном порядке, "
               "заданного файлом, результат выводится в консоль (чувствителена "
               "к регистру)\n");
    }

    if (argc > 1) {
        FILE *f1, *f2;

        if (argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == 't') {
            int i = 0;
            int file_numbers[N];
            f1
                    = fopen("/home/killreal/TRPO/Sorting-the-input-data/"
                            "thirdparty/test.txt",
                            "r");
            if (f1 != NULL) {
                while (feof(f1) == 0) {
                    fscanf(f1, "%d ", &file_numbers[i]);
                    i++;
                }
                fclose(f1);
                numberSort(file_numbers, 0, N - 1);
                f2
                        = fopen("/home/killreal/TRPO/Sorting-the-input-data/"
                                "thirdparty/res.txt",
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
            }
        }

        if (argv[1][0] == '-' && argv[1][1] == 'r' && argv[1][2] == 'n'
            && argv[1][3] == 't') {
            int i = 0;
            int file_numbers[N];
            f1
                    = fopen("/home/killreal/TRPO/Sorting-the-input-data/"
                            "thirdparty/test.txt",
                            "r");
            if (f1 != NULL) {
                while (feof(f1) == 0) {
                    fscanf(f1, "%d ", &file_numbers[i]);
                    i++;
                }
                fclose(f1);
                numberSort(file_numbers, 0, N - 1);
                f2
                        = fopen("/home/killreal/TRPO/Sorting-the-input-data/"
                                "thirdparty/revres.txt",
                                "w");
                printf("Массив, записанный в файл:");
                for (i = N - 1; i > -1; i--) {
                    fprintf(f2, "%d ", file_numbers[i]);
                    printf("%d ", file_numbers[i]);
                }
                fclose(f2);
                printf("\nОтсортированный от большего к меньшему массив "
                       "записан "
                       "в revres.txt\n");
            }
        }

        if (argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == 'c') {
            int input_numbers[N];
            printf("Введите 10 чисел для сортировки в консоль.\n");
            for (int i = 0; i < N; i++) {
                scanf("%d", &input_numbers[i]);
            }
            numberSort(input_numbers, 0, N - 1);
            printf("Отсортированный от меньшего к большему массив:");
            for (int i = 0; i < N; i++) {
                printf("%d ", input_numbers[i]);
            }
            printf("\n");
        }

        if (argv[1][0] == '-' && argv[1][1] == 'r' && argv[1][2] == 'n'
            && argv[1][3] == 'c') {
            int input_numbers[N];
            printf("Введите 10 чисел для сортировки в консоль.\n");
            for (int i = 0; i < N; i++) {
                scanf("%d", &input_numbers[i]);
            }
            numberSort(input_numbers, 0, N - 1);
            printf("Отсортированный от большего к меньшему массив:");
            for (int i = N - 1; i > -1; i--) {
                printf("%d ", input_numbers[i]);
            }
            printf("\n");
        }

        if (argv[1][0] == '-' && argv[1][1] == 't' && argv[1][2] == 'f') {
            printf("Отсортированные в афлавитном порядке с учётом регистра "
                   "слова:\n");
            vocabularySort();
            printf("\n");
        }

        if (argv[1][0] == '-' && argv[1][1] == 'r' && argv[1][2] == 't'
            && argv[1][3] == 'f') {
            printf("Отсортированные в обратном алфавитном порядке с учётом "
                   "регистра слова:\n");
            rvocabularySort();
            printf("\n");
        }
    }
}
