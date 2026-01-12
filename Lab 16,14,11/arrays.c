#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "arrays.h"
#define _CRT_SECURE_NO_DEPRECATE 
#define N 100


// Функции для лабораторной 16
double* full_elements(double* ptr_array, int size) {
    if (ptr_array == NULL || size <= 0) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        ptr_array[i] = pow(i, 3) - 4 * pow(i, 2) + 2;
    }

    return ptr_array;
}

double* calc_elements(double* ptr_array, int size) {
    if (ptr_array == NULL || size <= 0) {
        return NULL;
    }

    double* new_array = (double*)malloc(size * sizeof(double));
    if (new_array == NULL) {
        printf("Ошибка выделения памяти для нового массива!\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        if (ptr_array[i] < 0) {
            new_array[i] = 0.0;
        }
        else {
            new_array[i] = ptr_array[i];
        }
    }

    return new_array;
}

int put_elements(double* ptr_array, int size) {
    if (ptr_array == NULL) {
        printf("Пустой массив!\n");
        return -1;
    }
    if (size <= 0) {
        printf("Неверный размер массива!\n");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        printf("[%d] = %.4f\n", i, ptr_array[i]);
    }

    return 0;
}

int delete_k(double* ptr_arr, int size, int k, int count) {
    if (ptr_arr == NULL) {
        return 0;
    }

    if (k < 0 || k >= size) {
        printf("Неправильно указан начальный индекс для удаления: %d\n", k);
        return size;
    }

    if (count <= 0) {
        printf("Некорректное количество элементов для удаления: %d\n", count);
        return size;
    }

    if (count > size - k) {
        count = size - k;
    }

    int new_size = size - count;
    for (int i = k; i < new_size; i++) {
        ptr_arr[i] = ptr_arr[i + count];
    }

    return new_size;
}

int find_min_index(double* ptr_arr, int size) {
    if (ptr_arr == NULL || size <= 0) {
        return -1;
    }

    int min_index = 0;
    double min_value = ptr_arr[0];

    for (int i = 1; i < size; i++) {
        if (ptr_arr[i] < min_value) {
            min_value = ptr_arr[i];
            min_index = i;
        }
    }

    return min_index;
}

double* insert(double* ptr_arr, int* size, int index, double num) {
    if (ptr_arr == NULL || size == NULL) {
        printf("Некорректные параметры для вставки!\n");
        return NULL;
    }

    if (index < 0 || index > *size) {
        printf("Некорректный индекс для вставки: %d (размер: %d)\n", index, *size);
        return ptr_arr;
    }

    int size_n = (*size) + 1;
    double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));

    if (ptr_arr_n == NULL) {
        printf("Ошибка перевыделения памяти!\n");
        return ptr_arr;
    }

    for (int i = size_n - 1; i > index; i--) {
        ptr_arr_n[i] = ptr_arr_n[i - 1];
    }

    ptr_arr_n[index] = num;
    *size = size_n;

    return ptr_arr_n;
}

double* insert_after_min_k(double* ptr_arr, int* size, int k, double num) {
    if (ptr_arr == NULL || size == NULL || k <= 0) {
        printf("Некорректные параметры для вставки после каждого k-го элемента!\n");
        return ptr_arr;
    }

    if (*size == 0) {
        printf("Массив пуст, вставка невозможна!\n");
        return ptr_arr;
    }

    double* current_array = ptr_arr;
    int current_size = *size;

    for (int i = current_size - 1; i >= 0; i--) {
        if ((i + 1) % k == 0) {
            current_array = insert(current_array, &current_size, i + 1, num);
            if (current_array == NULL) {
                printf("Ошибка при вставке после элемента %d\n", i);
                return ptr_arr;
            }
        }
    }

    *size = current_size;
    return current_array;
}

// Создание случайного массива с использованием структуры
struct ArrayData create_random_array() {
    struct ArrayData result;
    result.size = rand() % 41 + 10; // 10-50
    result.data = (double*)malloc(result.size * sizeof(double));

    if (result.data == NULL) {
        printf("Ошибка выделения памяти для массива!\n");
        result.size = 0;
        return result;
    }

    for (int i = 0; i < result.size; i++) {
        result.data[i] = (double)rand() / RAND_MAX * 100.0 - 50.0;
    }

    return result;
}

// Создание массива d по правилу di = max(ai, bi, ci) с использованием структуры
struct ArrayData create_d_array(struct ArrayData a, struct ArrayData b, struct ArrayData c) {
    struct ArrayData d;

    // Проверка входных данных
    if (a.data == NULL || b.data == NULL || c.data == NULL ||
        a.size <= 0 || b.size <= 0 || c.size <= 0) {
        printf("Некорректные параметры для создания массива d!\n");
        d.data = NULL;
        d.size = 0;
        return d;
    }

    // Определяем размер массива d как удвоенный максимальный размер из a, b, c
    d.size = a.size;
    if (b.size > d.size) d.size = b.size;
    if (c.size > d.size) d.size = c.size;
    d.size = d.size * 2;

    d.data = (double*)malloc(d.size * sizeof(double));
    if (d.data == NULL) {
        printf("Ошибка выделения памяти для массива d!\n");
        d.size = 0;
        return d;
    }

    for (int i = 0; i < d.size; i++) {
        double ai = a.data[i % a.size];
        double bi = b.data[i % b.size];
        double ci = c.data[i % c.size];

        double max_val = ai;
        if (bi > max_val) max_val = bi;
        if (ci > max_val) max_val = ci;

        d.data[i] = max_val;
    }

    return d;
}

int printf_all_arrays() {
    printf("\n======================================================================\n");
    printf("ДЗ К ЛАБОРАТОРНОЙ 16\n");
    printf("Создание массивов a, b, c, d\n");
    printf("Правило: di = max(ai, bi, ci)\n");
    printf("======================================================================\n\n");

    // Создаем массивы a, b, c с использованием структур
    struct ArrayData a = create_random_array();
    if (a.data == NULL) return -1;

    printf("Массив a (размер: %d):\n", a.size);
    put_elements(a.data, a.size);

    struct ArrayData b = create_random_array();
    if (b.data == NULL) {
        free(a.data);
        return -1;
    }

    printf("\nМассив b (размер: %d):\n", b.size);
    put_elements(b.data, b.size);

    struct ArrayData c = create_random_array();
    if (c.data == NULL) {
        free(a.data);
        free(b.data);
        return -1;
    }

    printf("\nМассив c (размер: %d):\n", c.size);
    put_elements(c.data, c.size);

    // Создаем массив d с использованием структуры (всего 3 параметра!)
    struct ArrayData d = create_d_array(a, b, c);
    if (d.data == NULL) {
        free(a.data);
        free(b.data);
        free(c.data);
        return -1;
    }

    printf("\n======================================================================\n");
    printf("Массив d (размер: %d) по правилу: di = max(ai, bi, ci)\n", d.size);
    printf("======================================================================\n");
    put_elements(d.data, d.size);

    printf("\n======================================================================\n");
    printf("ИТОГИ:\n");
    printf("Размер массива a: %d элементов\n", a.size);
    printf("Размер массива b: %d элементов\n", b.size);
    printf("Размер массива c: %d элементов\n", c.size);
    printf("Размер массива d: %d элементов\n", d.size);
    printf("======================================================================\n");

    // Освобождаем память
    free(a.data);
    free(b.data);
    free(c.data);
    free(d.data);

    return 0;
}

// Функции для лабораторной 14
double task_14(int size, int A) {
    double array[N];

    for (int i = 0; i < size; i++) {
        array[i] = pow(i, 3) - 4 * pow(i, 2) + 2;
    }

    printf("Массив для задания 14:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] = %.4f\n", i, array[i]);
    }

    int minind = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] > A) {
            if (minind == -1 || array[i] < array[minind]) {
                minind = i;
            }
        }
    }

    if (minind == -1) {
        printf("Элементов больше A=%d не найдено!\n", A);
        return 0.0;
    }

    printf("Найден элемент № %d: %.4f\n", minind, array[minind]);
    return array[minind];
}

// Функции для лабораторной 11
double task_for_lab11(int size) {
    float C[N], temp, sum = 0;
    int count = 0, kol = 0, ind1 = -1, ind2 = -1;

    for (int i = 0; i < size; i++) {
        printf("c[%d] = ", i + 1);
        scanf("%f", &temp);
        C[i] = temp;
    }

    for (int i = 0; i < size; i++) {
        if (C[i] < 0) {
            ind1 = i;
            break;
        }
    }

    for (int j = ind1 + 1; j < size; j++) {
        if (C[j] < 0) {
            ind2 = j;
            break;
        }
    }

    if ((ind2 - ind1) <= 1 || (ind1 == -1 || ind2 == -1)) {
        printf("Нет чисел в интервале или нет отрицательных чисел\n");
        return 0.0;
    }

    for (int x = ind1 + 1; x < ind2; x++) {
        sum += C[x];
        kol++;
    }

    return sum / kol;
}


