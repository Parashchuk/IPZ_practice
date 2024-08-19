#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;

    // Зчитування координат
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Обчислення довжини вектора
    double length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    // Виведення довжини вектора з точністю до шести знаків після коми
    printf("%.6f\n", length);

    return 0;
}
