#include <stdio.h>
#include <stdlib.h>

// Функція для знаходження найбільшого спільного кратного (НСД)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функція для знаходження найменшого спільного кратного (НСК) двох чисел
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Функція для знаходження НСК для масиву чисел
int find_lcm_of_array(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    int p;
    
    // Зчитування кількості чисел
    scanf("%d", &p);
    
    // Перевірка на валідність кількості чисел
    if (p < 2 || p > 20) {
        printf("Invalid number of integers\n");
        return 1;
    }
    
    int *numbers = (int *)malloc(p * sizeof(int));
    
    // Зчитування самих чисел
    for (int i = 0; i < p; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Обчислення НСК
    int result = find_lcm_of_array(numbers, p);
    
    // Виведення результату
    printf("%d\n", result);
    
    // Вивільнення пам'яті
    free(numbers);
    
    return 0;
}
