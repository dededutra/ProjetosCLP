public class BubbleSort {
    void bubbleSort(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
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
        BubbleSort ob = new BubbleSort();
        ob.bubbleSort(arr);
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
