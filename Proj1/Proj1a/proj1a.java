package projeto1;

import java.util.Random;

public class Proj1a {

    static final int TAM = 100;
    static final int NUM = 1024;
  
    static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {  
        double[] processingTimes = new double[NUM];

        for (int i = 0; i < NUM; i++) {
            int[] arr = new int[TAM];
            Random rand = new Random();
            for (int i = 0; i < arr.length; i++) {
                arr[i] = rand.nextInt(10000);
            }
            long start = System.nanoTime();
            insertionSort(arr);
            long end = System.nanoTime();
            double cpuTimeUsed = (end - start) / 1e9;
            processingTimes[i] = cpuTimeUsed;
        }
        for (double time : processingTimes) {
            System.out.println(time);
        }
    }
}
