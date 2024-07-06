public class Peter_robinson {

    public static int funcPeterRobinson(int m, int n) {
        if (m == 0) return n + 1;
        if (m > 0 && n == 0) return funcPeterRobinson(m - 1, 1);
        return funcPeterRobinson(m - 1, funcPeterRobinson(m, n - 1));
    }

    public static void main(String[] args) {
        int m = 2, n = 3;
        System.out.println("A(" + m + ", " + n + ") = " + funcPeterRobinson(m, n));
    }
}
