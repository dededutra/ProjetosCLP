#include <stdio.h>

int peter_robinson(int m, int n) {
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return peter_robinson(m - 1, 1);
    return peter_robinson(m - 1, peter_robinson(m, n - 1));
}

int main() {
    int m = 2, n = 3;
    printf("A(%d, %d) = %d\n", m, n, peter_robinson(m, n));
    return 0;
}
