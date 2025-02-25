#include <stdio.h>

#define MAX_P 30

// Функція для обчислення кількості допустимих чисел
int count_valid_numbers(int p) {
    // Ініціалізація масивів для динамічного програмування
    long long dp[MAX_P + 1][4] = {0};

    // Базовий випадок
    dp[1][0] = 1; // Один 5
    dp[1][2] = 1; // Один 9

    // Заповнення масивів динамічного програмування
    for (int i = 2; i <= p; i++) {
        dp[i][0] = dp[i - 1][2] + dp[i - 1][3]; // Додаємо 5 до чисел, що закінчуються на 9
        dp[i][1] = dp[i - 1][0]; // Додаємо 5 до чисел, що закінчуються на один 5
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1]; // Додаємо 9 до чисел, що закінчуються на 5
        dp[i][3] = dp[i - 1][2]; // Додаємо 9 до чисел, що закінчуються на один 9
    }

    // Результат: сума всіх можливих закінчень для чисел довжиною p
    return dp[p][0] + dp[p][1] + dp[p][2] + dp[p][3];
}

int main() {
    int p;
    scanf("%d", &p);

    if (p < 1 || p > 30) {
        printf("Invalid input\n");
        return 1;
    }

    printf("%lld\n", count_valid_numbers(p));
    return 0;
}
