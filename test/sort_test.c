#include "ctest.h"
#include "../src/sorts.h"
#include <stdlib.h>
#include <time.h>

CTEST(check_mass, correct_sort_1)
{
    int sort_mass[5];
    sort_mass[0] = 1;
    sort_mass[1] = 2;
    sort_mass[2] = 3;
    sort_mass[3] = 4;
    sort_mass[4] = 5;
    const int result = check_mass(sort_mass, 5);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_mass, correct_sort_2)
{
    int sort_mass[10];
    sort_mass[0] = -25;
    sort_mass[1] = 0;
    sort_mass[2] = 0;
    sort_mass[3] = 44;
    sort_mass[4] = 501;
    sort_mass[5] = 502;
    sort_mass[6] = 505;
    sort_mass[7] = 507;
    sort_mass[8] = 10000;
    sort_mass[9] = 99999999;
    const int result = check_mass(sort_mass, 10);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_mass, incorrect_sort_1)
{
    int sort_mass[5];
    sort_mass[0] = 1;
    sort_mass[1] = 4;
    sort_mass[2] = 3;
    sort_mass[3] = 4;
    sort_mass[4] = 5;
    const int result = check_mass(sort_mass, 5);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_mass, incorrect_sort_2)
{
    int sort_mass[10];
    sort_mass[0] = 1;
    sort_mass[1] = 2;
    sort_mass[2] = 3;
    sort_mass[3] = 4;
    sort_mass[4] = 5;
    sort_mass[5] = 6;
    sort_mass[6] = 7;
    sort_mass[7] = 8;
    sort_mass[8] = 0;
    sort_mass[9] = -124;
    const int result = check_mass(sort_mass, 10);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_mass, correct_sort_3)
{
    int sort_mass[1];
    srand(time(NULL));
    sort_mass[0] = rand();
    const int result = check_mass(sort_mass, 1);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}