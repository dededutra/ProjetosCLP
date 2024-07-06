public class QuickSort {
    int partition(int arr[], int baixo, int alto) {
        int pivot = arr[alto];
        int i = (baixo-1);
        for (int j=baixo; j<alto; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[alto];
        arr[alto] = temp;
        return i+1;
    }

    void sort(int arr[], int baixo, int alto) {
        if (baixo < alto) {
            int pi = partition(arr, baixo, alto);
            sort(arr, baixo, pi-1);
            sort(arr, pi+1, alto);
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
        int n = arr.length;
        QuickSort ob = new QuickSort();
        ob.sort(arr, 0, n-1);
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
