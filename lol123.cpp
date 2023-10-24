#include <windows.h>
#include <conio.h>
#include<stdio.h>
#include <iostream>



int main() {
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int bit_num;
    long a;

    while (true) {
        printf("Автор: Нитенко В.В.\nГруппа: БББО-03-23\nВариант: 23\n");
        printf("\nВведите число A:");
        scanf("%lx", &a);
        printf("Введённые значения:\nA=%lx\n", a);

        auto* result = new int;
        *result = (a >> 0 & 0xF)<<24 | (a >> 8 & 0xF)<<16 | (a >> 16 & 0xF)<<8 | (a >> 24 & 0xF);
        printf("Двоичное значение переменной:");
        for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
            printf("%d", (*result >> i) & 1);
        }
        printf("\nАдрес переменной в памяти: %p\n", result);

        while (true)
        {
            printf("Введите номер бита, который необходимо вывести: ");
            scanf("%x", &bit_num);
            if (bit_num < 0 || bit_num > 31)
            {
                printf("Неверный ввод. Значение должно быть в промежутке [0; 15].\n");
                continue;
            }
            if ((*result >> bit_num & 1) == 1) {
                *result = *result << 4;
                printf("Сдвигаем биты на 4\n");
                printf("Поулученное число: %d\n", *result);
                break;
            }
            printf("Не изменяем число");
            break;
        }

        printf("exit? (y/n): ");
        if (getch() == 'y') {
            break;
        }
    }
    return 0;
}
