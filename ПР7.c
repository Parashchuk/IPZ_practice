#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, r1, x2, y2, r2;
    
    // Зчитування даних
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    
    // Обчислення відстані між центрами кола
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx * dx + dy * dy);
    
    // Перевірка умов
    if (d == 0 && r1 == r2) {
        // Нескінченна кількість точок перетину
        printf("-1\n");
    } else if (d > r1 + r2 || d < fabs(r1 - r2)) {
        // Кола не перетинаються
        printf("0\n");
    } else if (d == r1 + r2 || d == fabs(r1 - r2)) {
        // Кола перетинаються в одній точці
        printf("1\n");
    } else {
        // Кола перетинаються в двох точках
        printf("2\n");
    }

    return 0;
}
