#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define N 5
#define K 3

typedef struct {
    char name[4];
    double x[N];
} Component;

int main(void) {
    setlocale(LC_ALL, "RUS");

    Component c[3] = {
        {"NIC", {45.5, 46.0, 46.5, 47.0, 52.9}},
        {"HDD", {55.6, 53.6, 57.0, 55.0, 53.0}},
        {"SSD", {33.9, 33.1, 32.4, 31.6, 30.9}}
    };

    double q[3][N];
    int problems = 0, problem = -1;

    printf("Вариант 21\n");

    for (int i = 0; i < 3; i++) {
        int n = 0, growth = 1;

        printf("\n%s:\n", c[i].name);

        for (int j = K; j < N; j++) {
            q[i][n] = 100.0 * (c[i].x[j] - c[i].x[j - K])
                / c[i].x[j - K];

            printf("Q[%d] = %.2f%%\n", j + 1, q[i][n]);
            n++;
        }

        if (n < K)
            growth = 0;
        else
            for (int j = n - K + 1; j < n; j++)
                if (q[i][j] <= q[i][j - 1])
                    growth = 0;

        printf("Состояние: %s\n",
            growth ? "УСТОЙЧИВЫЙ РОСТ" : "НОРМА");

        if (growth) {
            problems++;
            problem = i;
        }
    }

    if (problems == 1)
        printf("\nОбнаружен инцидент: %s\n", c[problem].name);
    else
        printf("\nИнцидент не обнаружен\n");

    return 0;
}