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

int main() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    int choice;
    printf("Выберите задания:\n");
    printf("1 - выполнение лабораторной 16 (не домашняя)\n");
    printf("2 - выполнение домашней работы по лабораторной 16\n");
    printf("3 - выполнение домашней работы к лаб. 14\n");
    printf("4 - выполнение домашней работы к лаб. 11\n");
    printf("5 - дз к лабораторной 19\n");
    printf("ЗАДАНИЕ №: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
        // Лабораторная 16
        int size;
        printf("Введите размер массива: ");
        if (scanf("%d", &size) != 1) {
            printf("Ошибка ввода размера массива!\n");
            return -1;
        }
        if (size <= 0) {
            printf("Размер массива должен быть положительным!\n");
            return -1;
        }

        double* ptr_array = (double*)malloc(size * sizeof(double));
        if (ptr_array == NULL) {
            printf("Ошибка выделения памяти!\n");
            return -1;
        }

        printf("Исходный массив:\n");
        ptr_array = full_elements(ptr_array, size);
        put_elements(ptr_array, size);

        printf("Обработанный массив:\n");
        double* new_array = calc_elements(ptr_array, size);
        put_elements(new_array, size);

        printf("\n======================================================================\n");
        printf("УДАЛЕНИЕ ЭЛЕМЕНТОВ\n");

        if (size > 0) {
            int del_index = rand() % size;
            int del_count = 1 + rand() % (size - del_index);
            printf("Удаляем %d элементов, начиная с индекса %d\n", del_count, del_index);

            int new_size = delete_k(ptr_array, size, del_index, del_count);
            printf("Размер массива после удаления %d элементов: %d\n", del_count, new_size);
            printf("Массив после удаления:\n");
            put_elements(ptr_array, new_size);

            printf("\n======================================================================\n");
            printf("ВСТАВКА ЭЛЕМЕНТОВ\n");

            if (new_size > 0) {
                int min_index = find_min_index(ptr_array, new_size);
                printf("Минимальный элемент: %.4f находится на индексе %d\n",
                    ptr_array[min_index], min_index);
                printf("Вставляем -999 после минимального элемента (после индекса %d)\n", min_index);

                double* temp_array = insert(ptr_array, &new_size, min_index + 1, -999.0);
                if (temp_array != NULL) {
                    ptr_array = temp_array;
                    printf("Массив после вставки имеет %d элементов:\n", new_size);
                    put_elements(ptr_array, new_size);
                }
            }
        }

        free(ptr_array);
        free(new_array);
        break;
    }
    case 2: {
        // Домашняя работа к лабораторной 16
        printf("\n\tДЗ к лабораторной 16\n");
        printf_all_arrays();
        break;
    }
    case 3: {
        // Лабораторная 14
        int size, A;
        printf("Введите размер массива: ");
        scanf("%d", &size);
        if (size <= 0 || size > N) {
            printf("Некорректный размер массива! Должен быть от 1 до %d\n", N);
            break;
        }

        printf("Введите значение А: ");
        scanf("%d", &A);

        double min_element = task_14(size, A);
        if (min_element != 0.0) {
            printf("Минимальный элемент среди элементов больше A=%d: %.4f\n", A, min_element);
        }
        break;
    }
    case 4: {
        // Лабораторная 11
        int size;
        printf("Введите размер массива: ");
        scanf("%d", &size);
        if (size <= 0 || size > N) {
            printf("Некорректный размер массива! Должен быть от 1 до %d\n", N);
            break;
        }

        double average = task_for_lab11(size);
        if (average != 0.0) {
            printf("Среднее арифметическое равно: %f\n", average);
        }
        break;
    }
    case 5: {
        // Лабораторная 19
        int quantity_of_Employees;
        char fname[30] = "dz_lab19.txt";

        printf("Введите количество сотрудников (от 5 до 10): ");
        scanf("%d", &quantity_of_Employees);

        if (quantity_of_Employees < 5 || quantity_of_Employees > 10) {
            printf("Ошибка! Введите число от 5 до 10.\n");
            return 1;
        }

        struct Employee* employees = (struct Employee*)malloc(quantity_of_Employees * sizeof(struct Employee));
        if (employees == NULL) {
            printf("Ошибка выделения памяти!\n");
            return 1;
        }

        for (int i = 0; i < quantity_of_Employees; i++) {
            printf("\nСотрудник №%d:\n", i + 1);
            int result = inputEmployee(&employees[i]);
            if (result != 1) {
                printf("Ошибка ввода данных сотрудника %d!\n", i + 1);
                free(employees);
                return 1;
            }
        }

        int found = findEmployeesInMay(employees, quantity_of_Employees);
        if (found == 0) {
            printf("Сотрудников, родившихся в мае, не найдено.\n");
        }

        int file_result = append_into_file(fname, employees, quantity_of_Employees);
        if (file_result == 1) {
            printf("Данные успешно записаны в файл %s\n", fname);
        }
        else {
            printf("Ошибка записи в файл!\n");
        }

        free(employees);
        break;
    }
    default:
        printf("Такого задания нет!\n");
        break;
    }

    return 0;
}

