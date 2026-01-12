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
    do {
    int choice;
    printf("Выберите задания:\n");
    printf("1 - выполнение лабораторной 16 (не домашняя)\n");
    printf("2 - выполнение домашней работы по лабораторной 16\n");
    printf("3 - выполнение домашней работы к лаб. 14\n");
    printf("4 - выполнение домашней работы к лаб. 11\n");
    printf("5 - выполнение сортировки разными способами\n");
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

        printf("\n***********************************************\n");
        printf("УДАЛЕНИЕ ЭЛЕМЕНТОВ\n");

        if (size > 0) {
            int del_index = rand() % size;
            int del_count = 1 + rand() % (size - del_index);
            printf("Удаляем %d элементов, начиная с индекса %d\n", del_count, del_index);

            int new_size = delete_k(ptr_array, size, del_index, del_count);
            printf("Размер массива после удаления %d элементов: %d\n", del_count, new_size);
            printf("Массив после удаления:\n");
            put_elements(ptr_array, new_size);

            printf("\n**************************************************\n");
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
    case 5:{
          // Лабораторная 17 - сортировки
          printf("\n======================================================================\n");
          printf("ЛАБОРАТОРНАЯ РАБОТА 17 - СОРТИРОВКИ\n");
          printf("======================================================================\n");

          int size;
          printf("Введите размер массива для сортировки: ");
          scanf("%d", &size);

          if (size <= 0) {
              printf("Некорректный размер массива! Должен быть больше 0\n");
              break;
          }

          // Создаем массив
          int* array = (int*)malloc(size * sizeof(int));
          if (array == NULL) {
              printf("Ошибка выделения памяти!\n");
              break;
          }

          // Заполняем массив
          array = full_elements_for17(array, size);

          /*printf("\nИсходный массив:\n");
          for (int i = 0; i < size; i++) {
              printf("[%d] = %d\n", i, array[i]);
          }*/

          // Выбираем тип сортировки
          int sort_choice;
          printf("\nВыберите тип сортировки:\n");
          printf("1 - Сортировка пузырьком (Bubble Sort)\n");
          printf("2 - Сортировка выбором (Selection Sort)\n");
          printf("3 - Быстрая сортировка (Quick Sort)\n");
          printf("Выбор: ");
          scanf("%d", &sort_choice);

          clock_t start_time, end_time;
          double time_taken;

          // Создаем копию массива для сортировки
          int* array_copy = (int*)malloc(size * sizeof(int));
          if (array_copy == NULL) {
              printf("Ошибка выделения памяти для копии массива!\n");
              free(array);
              break;
          }

          // Копируем массив вручную (без memcpy)
          for (int i = 0; i < size; i++) {
              array_copy[i] = array[i];
          }

          switch (sort_choice) {
          case 1: {
              printf("\n--- СОРТИРОВКА ПУЗЫРЬКОМ ---\n");
              start_time = clock();
              sort_bubble(array_copy, size);
              end_time = clock();
              time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

              /*printf("Отсортированный массив:\n");
              for (int i = 0; i < size; i++) {
                  printf("[%d] = %d\n", i, array_copy[i]);
              }*/
              printf("Время выполнения: %.6f секунд\n", time_taken);
              break;
          }
          case 2: {
              printf("\n--- СОРТИРОВКА ВЫБОРОМ ---\n");
              start_time = clock();
              sort_select(array_copy, size);
              end_time = clock();
              time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

              /*printf("Отсортированный массив:\n");
              for (int i = 0; i < size; i++) {
                  printf("[%d] = %d\n", i, array_copy[i]);
              }*/
              printf("Время выполнения: %.6f секунд\n", time_taken);
              break;
          }
          case 3: {
              printf("\n--- БЫСТРАЯ СОРТИРОВКА ---\n");
              start_time = clock();
              sort_qwi(array_copy, size);
              end_time = clock();
              time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

              /*printf("Отсортированный массив:\n");
              for (int i = 0; i < size; i++) {
                  printf("[%d] = %d\n", i, array_copy[i]);
              }*/
              printf("Время выполнения: %.6f секунд\n", time_taken);
              break;
          }
          default:
              printf("Неверный выбор сортировки!\n");
              break;
          }

          // Освобождаем память
          free(array);
          free(array_copy);

          printf("\n======================================================================\n");
          break;
    }
    default:
        printf("Такого задания нет!\n");
        break;
    }
    char a;
    printf("Продолжить ? (Да - любая клавиша, нет - n)\n");
    getchar();
    if ((a = getchar()) == 'n') break;
    } while (1);
    return 0;
}
