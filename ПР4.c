#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;

    // Перебираємо всі можливі дільники m
    for (int m = 2; m < n; m++) {
        int quotient = n / m;  // Частка
        int remainder = n % m; // Залишок

        // Перевіряємо умову рівного дільника
        if (quotient == remainder) {
            count++;
        }
    }

    // Виводимо кількість рівних дільників
    printf("%d\n", count);

    return 0;
}
