/* group.c
 * Автор: Янушкевич Максим
 * Группа: 12
 */

/*
 * Реализация функций для работы со структурой GROUP.
 */

#include "group.h"
#include <stdio.h>
#include <string.h>

/* Ввод данных одной структуры */
void input_group(Group *g)
{
    printf("  Введите фамилию и инициалы: ");
    scanf(" %[^\n]", g->name);
    
    printf("  Введите год поступления: ");
    scanf("%d", &g->admission_date.year);
    
    printf("  Введите месяц поступления: ");
    scanf("%d", &g->admission_date.month);
    
    printf("  Введите день поступления: ");
    scanf("%d", &g->admission_date.day);
    
    printf("  Введите 3 оценки через пробел: ");
    scanf("%d %d %d", &g->grades[0], &g->grades[1], &g->grades[2]);
    
    printf("\n");
}

/* Ввод массива структур */
void input_groups(Group groups[])
{
    printf("\n=== Ввод данных для %d студентов ===\n", STUDENTS_COUNT);
    
    for (int i = 0; i < STUDENTS_COUNT; i++) {
        printf("\n--- Студент %d ---\n", i + 1);
        input_group(&groups[i]);
    }
}

/* Вывод одной структуры */
void print_group(const Group *g)
{
    printf("  ФИО: %s\n", g->name);
    printf("  Дата поступления: %04d-%02d-%02d\n", 
           g->admission_date.year, 
           g->admission_date.month, 
           g->admission_date.day);
    printf("  Оценки: %d %d %d\n", 
           g->grades[0], g->grades[1], g->grades[2]);
    
    int sum = g->grades[0] + g->grades[1] + g->grades[2];
    float avg = sum / 3.0;
    printf("  Сумма баллов: %d, Средний: %.2f\n", sum, avg);
    printf("  ------------------------\n");
}

/* Вывод всего массива */
void print_groups(const Group groups[])
{
    printf("\n=== Список всех студентов ===\n");
    
    for (int i = 0; i < STUDENTS_COUNT; i++) {
        printf("\nСтудент %d:\n", i + 1);
        print_group(&groups[i]);
    }
}

/* Сортировка по возрастанию суммы оценок */
void sort_by_ses(Group groups[])
{
    for (int i = 0; i < STUDENTS_COUNT - 1; i++) {
        for (int j = 0; j < STUDENTS_COUNT - i - 1; j++) {
            int sum_j = groups[j].grades[0] + groups[j].grades[1] + groups[j].grades[2];
            int sum_j1 = groups[j+1].grades[0] + groups[j+1].grades[1] + groups[j+1].grades[2];
            
            if (sum_j > sum_j1) {
                Group temp = groups[j];
                groups[j] = groups[j + 1];
                groups[j + 1] = temp;
            }
        }
    }
}

/* Проверка возраста на 01.12.2020 */
int is_younger_than_20(const Group *g)
{
    const int check_year = 2020;
    const int check_month = 12;
    const int check_day = 1;
    
    /* Считаем, что при поступлении обычно 17 лет */
    int birth_year = g->admission_date.year - 17;
    int birth_month = g->admission_date.month;
    int birth_day = g->admission_date.day;
    
    int age = check_year - birth_year;
    
    if (check_month < birth_month || 
        (check_month == birth_month && check_day < birth_day)) {
        age--;
    }
    
    return (age <= 20);
}

/* Вывод студентов не старше 20 лет */
void print_young_students(const Group groups[])
{
    printf("\n=== Студенты с возрастом <= 20 лет на 01.12.2020 ===\n");
    
    int found = 0;
    
    for (int i = 0; i < STUDENTS_COUNT; i++) {
        if (is_younger_than_20(&groups[i])) {
            found++;
            printf("\nСтудент %d:\n", found);
            printf("  ФИО: %s\n", groups[i].name);
            printf("  Дата поступления: %04d-%02d-%02d\n", 
                   groups[i].admission_date.year,
                   groups[i].admission_date.month,
                   groups[i].admission_date.day);
        }
    }
    
    if (found == 0) {
        printf("  Таких студентов нет.\n");
    } else {
        printf("\n  Всего найдено: %d\n", found);
    }
}
