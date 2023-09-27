#include <iostream>

using namespace std;
int memo[41] = { 0, 1 };

int fibonacci(int n) {
    if (n == 0) {
        memo[n] = 0;
        return 0;
    }
    else if (n == 1) {
        memo[n] = 1;
        return 1;
    }
    if (memo[n] != 0)
        return memo[n];
    else {
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t == 0)
            printf("%d %d\n", 1, 0);
        else if (t == 1)
            printf("%d %d\n", 0, 1);
        else {
            fibonacci(t);
            printf("%d %d\n", memo[t - 1], memo[t]);
        }
    }
    return 0;
}