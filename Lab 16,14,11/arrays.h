#pragma once
#ifndef ARRAYS_H
#define ARRAYS_H
//структура дня рождения
struct Date {
    int day;
    int month;
    int year;
};
//структура заполнения данных сотружника
struct Employee {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char position[50];
    double salary;
    struct Date birthDate;
};

//Структура хранения массива с размером
struct ArrayData {
    double* data;
    int size;
};
//функции для лабораторной 16
double* full_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);
int delete_k(double* ptr_arr, int size, int k, int count);
double* insert(double* ptr_arr, int* size, int index, double num);
double* insert_after_min_k(double* ptr_arr, int* size, int k, double num);
int find_min_index(double* ptr_arr, int size);
struct ArrayData create_random_array();
struct ArrayData create_d_array(struct ArrayData a, struct ArrayData b, struct ArrayData c);
int printf_all_arrays();

//функция для лабораторной 14
double task_14(int size, int A);

// Прототипы функций для лабораторной 11
double task_for_lab11(int size);

// Прототипы функций для лабораторной 19
int inputEmployee(struct Employee* emp);
int printEmployee(struct Employee* emp);
int findEmployeesInMay(struct Employee employees[], int count);
int append_into_file(char* fname, struct Employee employees[], int cnt);

//double* full_elements(double* ptr_array, int size);
///**
//  * Заполнение массива значениями
//  * @param ptr_array указатель на массив
//  * @param size размер массива
//  * @return указатель на заполненный массив
//  */
//double* calc_elements(double* ptr_array, int size);
///**
//  * создание массива, где все отрицательные элементы заменяются на 0.0
//  * @param ptr_array указатель на массив
//  * @param size размер массива
//  * @return указатель на новый заполненный массив
//  */
//int put_elements(double* ptr_array, int size);
///**
//  * вывод массива на экран
//  * @param ptr_array указатель на массив
//  * @param size размер массива
//  * @return 0 при успешном выводе, 1 при ошибке
//  */
//int delete_k(double* ptr_arr, int size, int k, int count);
///**
///* удаление count элементов,начиная с индекса k
// /* @param ptr_array указатель на массив
// /* @param size размер массива
// /* @param k индекс,с которого начинать удаление
// /* @param count количество элементов для удаления
// /* @return новый размер массива после удаления
// /*/
//double* insert(double* ptr_arr, int* size, int index, double num);
///**
///* Вставка элемента num в позицию index
// /* @param ptr_array указатель на массив
// /* @param size размер массива
// /* @param index индекс,куда будет вставлен элемент num
// /* @param num значение для вставки
// /* @return указатель на массив
// /*/
//double* insert_after_min_k(double* ptr_arr, int* size, int k, double num);
///**
///* Вставка элемента num после каждого k элемента
// /* @param ptr_array указатель на массив
// /* @param size размер массива
// /* @param k после кажлого k-го элемента вставка num
// /* @param num значение для вставки
// /* @return указатель на массив
// /*/
//int find_min_index(double* ptr_arr, int size);
///**
///* поиск индекса минимального элемента массива
// /* @param ptr_array указатель на массив
// /* @param size размер массива
// /* @return -1,если массив пустой, либо число int-индекс минимального эл-та массива
// /*/
//double* create_random_array(int* size);
///**
///* создание массива из 10-50 случайных чисел от [-50:50]
// /* @param size указатель на переменную, кула запишщется размер массива
// /* @return указатель на созданный массив случайных чисел
// /*/
//double* create_d_array(double* a, int size_a, double* b, int size_b, double* c, int size_c, int size_d);
///**
///* Создание массива d по правилу d[i]
// /* @param a указатель на массив
// /* @param size_a размер массива
// /* @param b указатель на массив
// /* @param size_b размер массива
// /* @param c указатель на массив
// /* @param size_c размер массива
// /* @param size_d размер создаваемого массива
// /* @return указатель на новый массив d
// /*/
//void printf_all_arrays();
///* Создание массивов a,b,c,d и их вывод на экран*/
//
////задание к лаб 14
//double task_14(int size);
///**
///* Поиск минимального элемента, большего заданного числа A
// /* @param size размер массива
// /* @return значение найденного элемента, либо 0.0
// /*/
// //задание к лаб 11
//task_for_lab11(int size);
///**
///* Нахождение среднего арифметического между первыми двумя отрицательными элементами
// /* @param size размер массива
// /* @return значение среднего арифметического
// /*/
//
// //Функции к лаб.19
//void inputEmployee(struct Employee* emp);
///**
///* Запрос данных сотрудника и сохранение их в структуре
// /* @param emp указатель на структуру Employee
// /* @return ничего
// /*/
//void printEmployee(struct Employee* emp);
///**
///* Вывод информации о сотруднике на экран
// /* @param emp указатель на структуру Employee
// /* @return ничего
// /*/
//void findEmployeesInMay(struct Employee employees[], int count);
///**
///* Поиск и вывод данных о сотрудниках, родившихся в мае
// /* @param Employee employees[] массив структур Employee
// /* @param count количество элементов в массиве
// /* @return ничего
// /*/
//int append_into_file(char* fname, struct Employee employees[], int cnt);
///**
///* Запись в файл сотрудников, родившихся в мае
///* @param fname имя файла
// /* @param Employee employees[] массив структур Employee
// /* @param cnt количество сотрудников в массиве
// /* @return 1 при успешной записи, 0 при ошибке открытия файла
// /*/
#endif

