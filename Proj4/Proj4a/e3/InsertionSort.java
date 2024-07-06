
public class InsertionSort {
    void insertionSort(int arr[]) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int arr[10000];
        for (int i = 0; i < 10000; i++) {
              arr[i] = scanner.nextInt();
              if (entrada.isEmpty()) {
                  break;
              }
        }
        InsertionSort ob = new InsertionSort();
        ob.insertionSort(arr);
        for (int i = 0; i < arr.length; ++i)
        System.out.print(arr[i] + " ");
        System.out.println();
    }
}
