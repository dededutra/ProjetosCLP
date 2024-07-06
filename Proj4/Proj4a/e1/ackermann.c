#include <stdio.h>

int ackermann(int m, int n, int p) {
    if (p == 0) return m + n;
    if (p == 1) return 0;
    if (p == 2) return 1;
    if (p == 3) return m;
    if (n == 0 && p > 2) return ackermann(m, 0, p - 1);
    return ackermann(m, ackermann(m, n - 1, p), p - 1);
}

int main() {
    int m = 2, n = 3, p = 4;
    printf("phi(%d, %d, %d) = %d\n", m, n, p, ackermann(m, n, p));
    return 0;
}
