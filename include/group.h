/* group.h
 * Автор: Янушкевич Максим
 * Группа: 12
 */

#ifndef GROUP_H
#define GROUP_H

/*
 * Заголовочный файл модуля работы со структурой GROUP.
 * Содержит определение структуры и объявления функций.
 */

#define MAX_NAME 50   /* Максимальная длина ФИО */
#define STUDENTS_COUNT 8  /* Количество студентов */

/* Структура для даты */
typedef struct {
    int year;
    int month;
    int day;
} Date;

/* Основная структура GROUP */
typedef struct {
    char name[MAX_NAME];      /* Фамилия и инициалы */
    Date admission_date;      /* Дата поступления */
    int grades[3];            /* Успеваемость (3 оценки) */
} Group;

/*
 * Ввод данных одной структуры с клавиатуры.
 */
void input_group(Group *g);

/*
 * Ввод массива структур (8 студентов).
 */
void input_groups(Group groups[]);

/*
 * Вывод одной структуры на экран.
 */
void print_group(const Group *g);

/*
 * Вывод всего массива структур.
 */
void print_groups(const Group groups[]);

/*
 * Сортировка массива по возрастанию суммы оценок.
 */
void sort_by_ses(Group groups[]);

/*
 * Проверка возраста на 01.12.2020 (<= 20 лет).
 */
int is_younger_than_20(const Group *g);

/*
 * Вывод студентов не старше 20 лет.
 */
void print_young_students(const Group groups[]);

#endif /* GROUP_H */
