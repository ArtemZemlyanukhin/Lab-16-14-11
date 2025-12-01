
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <limits.h>
#define N 100
double* full_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);
int delete_k(double* ptr_arr, int size, int k, int count);
double* insert(double* ptr_arr, int* size, int index, double num);
double* insert_after_min_k(double* ptr_arr, int* size, int k, double num);
int find_min_index(double* ptr_arr, int size);
double task_14(int size);
task_for_lab11(int size);
double* create_random_array(int* size);
double* create_d_array(double* a, int size_a, double* b, int size_b, double* c, int size_c, int size_d);
void printf_all_arrays();
int main() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    double* ptr_array = NULL;
    int size;

    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1) {
        puts("Ошибка ввода размера массива!");
        return -1;
    }
    if (size <= 0) {
        puts("Размер массива должен быть положительным!");
        return -1;
    }

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти!");
        return -1;
    }
    int choice;
    puts("Выберите задания:\n1-выполнение лабораторной 16( не домашняя)\n2-выполнение домашней работы по лабораторной 16\n3-\
выполнение домашней работы к лаб. 14\n4-Выполнение домашней работы к лаб.11\n\n");
    printf("ЗАДАНИЕ №: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Исходный массив:\n");
        full_elements(ptr_array, size);
        put_elements(ptr_array, size);

        printf("Обработанный массив:\n");
        double* new_array = calc_elements(ptr_array, size);
        put_elements(new_array, size);

        printf("\n======================================================================");
        printf("\n\t УДАЛЕНИЕ ЭЛЕМЕНТОВ\n");

        int del_index, del_count;

        if (size > 0) {
            del_index = rand() % size;
            del_count = 1 + rand() % (size - del_index);
            printf("Удаляем %d элементов, начиная с индекса %d\n", del_count, del_index);

            int new_size = delete_k(ptr_array, size, del_index, del_count);
            printf("Размер массива после удаления %d элементов:\n", new_size);
            put_elements(ptr_array, new_size);

            printf("\n======================================================================");
            printf("\n\tВСТАВКА ЭЛЕМЕНТОВ\n");

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

        if (ptr_array != NULL) {
            free(ptr_array);
            ptr_array = NULL;
        }
        if (new_array != NULL) {
            free(new_array);
            new_array = NULL;
        }
        break;
    case 2:
        puts("\n\tДЗ к лабораторной 16\n");
        printf_all_arrays();
        puts("=================================================================");
        break;
    case 3:
        printf(" \n\tЗадание для 14 лабораторной\n");
        puts("Поиск порядкового номера минимального значения элементов,\
больших заданного значения А\n");
        task_14(size);
        break;
    case 4:
        printf("\n\t Задание для 11 лабораторной\n");
        puts("Среднее арифметическое элементов массива, расположенных \
между первым и вторым отрицательными элементами\n");
        task_for_lab11(size);
        break;
    default:
        puts("Такого задания нет\n");
        break;
    }
    
   
    
    
    return 0;
}

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
        puts("Пустой массив!");
        return -1;
    }
    if (size <= 0) {
        puts("Неверный размер массива!");
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
double task_14(int size) {
    if (size > N || size <= 0) {
        printf("Некорректный размер массива для задачи 14!\n");
        return 0.0;
        }
    double array[N];
    int A;

        setlocale(LC_CTYPE, "RUS");
        printf("Введите значение А: ");
        scanf("%d", &A);

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
task_for_lab11(int size)
{
    float C[N], temp, sum = 0;
    int count = 0, kol = 0, ind1 = -1, ind2 = -1, pp;


    for (int i = 0; i < size; i++)
    {
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
    for (int j = ind1 + 1; j < size; j++)
    {
        if (C[j] < 0) {
            ind2 = j;
            break;
        }
    }
    if ((ind2 - ind1) <= 1|| (ind1==-1|| ind2==-1)) printf("Нет чисел в интервале или нет отрицательных чисел\n");
    else
    {
        for (int x = ind1+1; x < ind2; x++) {

            sum += C[x];
            kol++;
        }
        printf("\n\t\tСреднее арифметическое равно == %f\n", sum / kol);
    }
}

double* create_random_array(int* size) {
    if (size == NULL) {
        return NULL;
    }

    *size = rand() % 41 + 10; // 10-50
    double* array = (double*)malloc(*size * sizeof(double));

    if (array == NULL) {
        printf("Ошибка выделения памяти для массива!\n");
        return NULL;
    }

    for (int i = 0; i < *size; i++) {
        array[i] = (double)rand() / RAND_MAX * 100.0 - 50.0;
    }

    return array;
}

// Функция для создания массива d по правилу di = max(ai, bi, ci)
double* create_d_array(double* a, int size_a, double* b, int size_b,double* c, int size_c, int size_d) {
    if (a == NULL || b == NULL || c == NULL ||
        size_a <= 0 || size_b <= 0 || size_c <= 0 || size_d <= 0) {
        printf("Некорректные параметры для создания массива d!\n");
        return NULL;
    }

    double* d = (double*)malloc(size_d * sizeof(double));
    if (d == NULL) {
        printf("Ошибка выделения памяти для массива d!\n");
        return NULL;
    }

    for (int i = 0; i < size_d; i++) {
        
        double ai = a[i % size_a];
        double bi = b[i % size_b];
        double ci = c[i % size_c];

        
        double max_val = ai;
        if (bi > max_val) max_val = bi;
        if (ci > max_val) max_val = ci;

        d[i] = max_val;
    }

    return d;
}


void printf_all_arrays() {
    double* a = NULL, * b = NULL, * c = NULL, * d = NULL;
    int size_a = 0, size_b = 0, size_c = 0, size_d = 0;

    printf("\n======================================================================\n");
    printf("ДЗ К ЛАБОРАТОРНОЙ 16\n");
    printf("Создание массивов a, b, c, d\n");
    printf("Правило: di = max(ai, bi, ci)\n");
    printf("======================================================================\n\n");

    // Создаем массивы a, b, c
    printf("Создание массива a:\n");
    a = create_random_array(&size_a);
    if (a != NULL) {
        printf("Размер массива a: %d\n", size_a);
        put_elements(a, size_a);
    }

    printf("\nСоздание массива b:\n");
    b = create_random_array(&size_b);
    if (b != NULL) {
        printf("Размер массива b: %d\n", size_b);
        put_elements(b, size_b);
    }

    printf("\nСоздание массива c:\n");
    c = create_random_array(&size_c);
    if (c != NULL) {
        printf("Размер массива c: %d\n", size_c);
        put_elements(c, size_c);
    }

    
    if (a != NULL && b != NULL && c != NULL) {
       
        size_d = size_a;
        if (size_b > size_d) size_d = size_b;
        if (size_c > size_d) size_d = size_c;
        size_d = size_d * 2;

        printf("\n======================================================================\n");
        printf("Создание массива d по правилу: di = max(ai, bi, ci)\n");
        printf("Размер массива d: %d\n", size_d);
        printf("======================================================================\n");

        d = create_d_array(a, size_a, b, size_b, c, size_c, size_d);

        if (d != NULL) {
            printf("\nМассив d:\n\n");
            put_elements(d, size_d);
            puts("\n========ТУТ НАЧИНАЕТСЯ НОВЫЙ МАССИВ!!!=================\n");
            printf("\nМассив a:\n\n");
            put_elements(a, size_a);
            puts("\n========ТУТ НАЧИНАЕТСЯ НОВЫЙ МАССИВ!!!=================\n");
            printf("\nМассив b:\n\n");
            put_elements(b, size_b);
            puts("\n========ТУТ НАЧИНАЕТСЯ НОВЫЙ МАССИВ!!!=================\n");
            printf("\nМассив c:\n\n");
            put_elements(c, size_c);

            printf("\n======================================================================\n");

            printf("ИТОГИ:\n");
            printf("Размер массива a: %d элементов\n", size_a);
            printf("Размер массива b: %d элементов\n", size_b);
            printf("Размер массива c: %d элементов\n", size_c);
            printf("Размер массива d: %d элементов\n", size_d);
            printf("======================================================================\n");
            free(d);
        }
    }
    else {
        printf("\nОшибка при создании одного из массивов a, b, c!\n");
    }

    if (a != NULL) free(a);
    if (b != NULL) free(b);
    if (c != NULL) free(c);

}
