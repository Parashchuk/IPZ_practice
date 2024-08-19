#include <stdio.h>
#include <string.h>
#include <math.h>

// Функція для обчислення факторіалу
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функція для обчислення кількості анаграм
unsigned long long count_anagrams(const char *word) {
    int freq[26] = {0}; // Масив для зберігання частот букв
    int length = strlen(word);
    unsigned long long result = factorial(length);

    // Підрахунок частот букв
    for (int i = 0; i < length; i++) {
        freq[word[i] - 'A']++;
    }

    // Ділення на факторіали частот букв
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            result /= factorial(freq[i]);
        }
    }

    return result;
}

int main() {
    char word[15]; // Максимум 14 букв + 1 для нульового символу

    // Зчитування слова
    scanf("%s", word);

    // Перевірка довжини слова
    if (strlen(word) > 14) {
        printf("Word length exceeds 14 characters\n");
        return 1;
    }

    // Обчислення та виведення кількості анаграм
    printf("%llu\n", count_anagrams(word));

    return 0;
}
