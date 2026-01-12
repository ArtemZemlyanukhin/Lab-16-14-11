#pragma once
#ifndef ARRAYS_H
#define ARRAYS_H

//Структура хранения массива с размером
struct ArrayData {
    double* data;
    int size;
};
/**
/* Хранение массива и его размера
/* @param data - указатель на массив
/* @param size - размер массива
 /*/

//функции для лабораторной 16
double* full_elements(double* ptr_array, int size);
/**
  * Заполнение массива значениями
  * @param ptr_array указатель на массив
  * @param size размер массива
  * @return указатель на заполненный массив
  */
double* calc_elements(double* ptr_array, int size);
/**
  * создание массива, где все отрицательные элементы заменяются на 0.0
  * @param ptr_array указатель на массив
  * @param size размер массива
  * @return указатель на новый заполненный массив
  */
int put_elements(double* ptr_array, int size);
/**
  * вывод массива на экран
  * @param ptr_array указатель на массив
  * @param size размер массива
  * @return 0 при успешном выводе, 1 при ошибке
  */
int delete_k(double* ptr_arr, int size, int k, int count);
/**
/* удаление count элементов,начиная с индекса k
 /* @param ptr_array указатель на массив
 /* @param size размер массива
 /* @param k индекс,с которого начинать удаление
 /* @param count количество элементов для удаления
 /* @return новый размер массива после удаления
 /*/
double* insert(double* ptr_arr, int* size, int index, double num);
/**
/* Вставка элемента num в позицию index
 /* @param ptr_array указатель на массив
 /* @param size размер массива
 /* @param index индекс,куда будет вставлен элемент num
 /* @param num значение для вставки
 /* @return указатель на массив
 /*/
double* insert_after_min_k(double* ptr_arr, int* size, int k, double num);
/**
/* Вставка элемента num после каждого k элемента
 /* @param ptr_array указатель на массив
 /* @param size размер массива
 /* @param k после кажлого k-го элемента вставка num
 /* @param num значение для вставки
 /* @return указатель на массив
 /*/
int find_min_index(double* ptr_arr, int size);
/**
/* поиск индекса минимального элемента массива
 /* @param ptr_array указатель на массив
 /* @param size размер массива
 /* @return -1,если массив пустой, либо число int-индекс минимального эл-та массива
 /*/
struct ArrayData create_random_array();
/**
/* Создание случайного массива чисел с плавающей точкой
 /* @return структура ArrayData с созданным массивом и его размером
 /*/
struct ArrayData create_d_array(struct ArrayData a, struct ArrayData b, struct ArrayData c);
/**
/* Создание массива d по правилу: di = max(ai, bi, ci)
 /* @param a первый массив-источник
 /* @param b второй массив-источник
 /* @param c третий массив-источник
 /* @return структура ArrayData с созданным массивом d и его размером
 /*/
int printf_all_arrays();
/**
/* Выполнение домашнего задания к лабораторной работе 16
 /* @return 0 при успешном выполнении, -1 при ошибке выделения памяти
 /*/
 //функция для лабораторной 14 
double task_14(int size,int A);
/**
/* Поиск минимального элемента, большего заданного числа A
 /* @param size размер массива
 /* @return значение найденного элемента, либо 0.0
 /*/
 //функция для лабораторной 11
double task_for_lab11(int size);
/**
/* Нахождение среднего арифметического между первыми двумя отрицательными элементами
 /* @param size размер массива
 /* @return значение среднего арифметического
 /*/
int* full_elements_for17(int* ptrarr, int size);
/**
/* Заполнение массива целых чисел по специальной формуле
 /* @param ptrarr указатель на массив целых чисел
 /* @param size размер массива
 /* @return указатель на заполненный массив
 /*/
void sort_bubble(int* ptrarr, int n);
/**
/* Сортировка массива методом пузырька (Bubble Sort)
 /* @param ptrarr указатель на массив целых чисел
 /* @param n размер массива
 /*/
void sort_select(int* ptrarr, int n);
/**
/* Сортировка массива методом выбора (Selection Sort)
 /* @param ptrarr указатель на массив целых чисел
 /* @param n размер массива
 /*/
int func(int x);
/**
/* Вычисление значения по формуле для заполнения массива
 /* Для четных x: возвращает x*10*3
 /* Для нечетных x: возвращает (x*10)^2
 /* @param x входное значение
 /* @return вычисленное значение
 /*/
void swp(int* ptrarr, int* ptrarr2);
/**
/* Обмен значениями двух переменных
 /* @param ptrarr указатель на первую переменную
 /* @param ptrarr2 указатель на вторую переменную
 /*/
void sort_qwi(int* ptrarr, int n);
/**
/* Быстрая сортировка массива (Quick Sort)
 /* @param ptrarr указатель на массив целых чисел
 /* @param n размер массива
 /*/
#endif

