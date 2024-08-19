#include <stdio.h>

#define MOD 12345

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 1) {
        printf("0\n");
        return 0;
    }

    // Масиви для збереження результатів
    long long dp0[n + 1];
    long long dp1[n + 1];
    long long dp2[n + 1];

    // Ініціалізація базових випадків
    dp0[1] = 1; // "0"
    dp1[1] = 1; // "1"
    dp2[1] = 0; // Немає можливих послідовностей довжини 1, що закінчуються на "11"

    if (n > 1) {
        dp0[2] = 2; // "00", "10"
        dp1[2] = 1; // "11"
        dp2[2] = 1; // "10" + "1" => "110"
    }

    // Заповнення масивів
    for (int i = 3; i <= n; i++) {
        dp0[i] = (dp0[i - 1] + dp1[i - 1] + dp2[i - 1]) % MOD;
        dp1[i] = dp0[i - 1] % MOD;
        dp2[i] = dp1[i - 1] % MOD;
    }

    // Кількість послідовностей довжиною n
    long long result = (dp0[n] + dp1[n] + dp2[n]) % MOD;

    printf("%lld\n", result);

    return 0;
}
