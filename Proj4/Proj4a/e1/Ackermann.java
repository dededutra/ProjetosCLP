public class Ackermann {

    public static int funcAckermann(int m, int n, int p) {
        if (p == 0) return m + n;
        if (p == 1) return 0;
        if (p == 2) return 1;
        if (p == 3) return m;
        if (n == 0 && p > 2) return funcAckermann(m, 0, p - 1);
        return funcAckermann(m, funcAckermann(m, n - 1, p), p - 1);
    }

    public static void main(String[] args) {
        int m = 2, n = 3, p = 4;
        System.out.println("phi(" + m + ", " + n + ", " + p + ") = " + funcAckermann(m, n, p));
    }
}
