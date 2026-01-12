#pragma once
#ifndef ARRAYS_H
#define ARRAYS_H
//структура дня рождения
struct Date {
    int day;
    int month;
    int year;
};
/**
/* Хранение даты дня рождения
/* @param day - день
/* @param month - месяц
/* @param year - год
 /*/
//структура заполнения данных сотружника
struct Employee {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char position[50];
    double salary;
    struct Date birthDate;
};
/**
/* Хранение данных о сотруднике
/* @param lastName - Фамилия
/* @param firstName - Имя
/* @param middleName - Отчество
/* @param position - должность
/* @param salary - зарплата
/* @param birthDate - день рождения
 /*/

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

#endif


