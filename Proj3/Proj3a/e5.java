public class E5 {

    public static void trocar(int[] vet, int i, int j) {
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
  
    public static void permutar(int[] vet, int inicio, int fim) {
        if (inicio != fim) {
            for (int i = inicio; i <= fim; i++) {
                trocar(vet, inicio, i);
                permutar(vet, inicio + 1, fim);
                trocar(vet, inicio, i);
            }
        }
    }

    public static void main(String[] args) {
        int n = 0;
        int[] vetor = new int[50];
        long inicio, fim;
        double tempo = 0.0;

        while (true) {
            vetor[n] = n;
            n++;
            inicio = System.currentTimeMillis();
            permutar(vetor, 0, n - 1);
            fim = System.currentTimeMillis();
            tempo = (fim - inicio) / 1000.0; 
            System.out.println("n = " + n + ", tempo = " + tempo);
            if (tempo >= 60.0) {
                System.out.println("Maior n para o qual as permutações podem ser calculadas em menos de 1 minuto: " + (n - 1));
                break;
            }
        }
    }
}
