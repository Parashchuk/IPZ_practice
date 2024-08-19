#include <stdio.h>
#include <math.h>

int min_steps(int x, int y) {
    // Розрахунок відстані між x і y
    int D = y - x;
    
    // Якщо x == y, то кількість кроків 0, але це можливо лише якщо x == y == 0
    if (D == 0) {
        return 0;
    }

    // Формула для розрахунку мінімальної кількості кроків
    int k = (int)ceil((-1 + sqrt(1 + 8.0 * D)) / 2);
    
    return k;
}

int main() {
    int x, y;
    
    // Зчитування x і y
    scanf("%d %d", &x, &y);

    // Обчислення мінімальної кількості кроків
    int result = min_steps(x, y);

    // Виведення результату
    printf("%d\n", result);

    return 0;
}
