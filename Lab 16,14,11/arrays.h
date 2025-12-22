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
struct ArrayData create_random_array();
/**
/* Создание массива со случайными числами
 /* @param нет
 /* @return структуру ArrayData с случайным массивом
 /*/
struct ArrayData create_d_array(struct ArrayData a, struct ArrayData b, struct ArrayData c);
/**
/* Создание массива d по правилу di=max(ai,bi,ci)
 /* @param a - структура с массивом 
 /* @param b - структура с массивом 
 /* @param c - структура с массивом 
 /* @return структуру ArrayData с массивом d
 /*/
int printf_all_arrays();
/**
/* Вывод массивы a,b,c,d
 /* @param нет
 /* @return 0 при успехе, 1 при ошибке
 /*/
 //функции для лабораторной 19
int inputEmployee(struct Employee* emp);
/**
/* Ввод данных о сотруднике в структуру 
 /* @param emp - указатель на структуру
 /* @return 1 при успехе, 0 при ошибке
 /*/
int printEmployee(struct Employee* emp);
/**
/* Вывод данных о сотруднике на экран
 /* @param emp - указатель на структуру
 /* @return 1 при успехе, 0 при ошибке
 /*/
int findEmployeesInMay(struct Employee employees[], int count);
/**
/* Поиск и вывод сотруднмков, родившихся в мае
 /* @param employees[] - массив сотрудников
 /* @param count - количество сотрудников в массиве
 /* @return количество найденных сотрудников
 /*/
int append_into_file(char* fname, struct Employee employees[], int cnt);
/**
/* Запись в файл данных о сотрудниках, родившихся в мае
/* @param fname - имя файла
 /* @param employees[] - массив сотрудников
 /* @param count - количество сотрудников 
 /* @return 1 при успешной записи, 0 при ошибке
 /*/
#endif
