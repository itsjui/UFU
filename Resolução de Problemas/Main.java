import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Leitura rápida da entrada
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine(); // Sequência de parênteses
        int n = s.length();

        // Pré-processamento: Arrays para armazenar pares acumulados
        int[] pairs = new int[n + 1]; // Quantidade de pares até a posição i
        int open = 0; // Contador de "("

        // Pré-computação dos pares válidos
        for (int i = 0; i < n; i++) {
            pairs[i + 1] = pairs[i]; // Herdar o valor acumulado anterior
            if (s.charAt(i) == '(') {
                open++; // Incrementa o número de "("
            } else if (open > 0) {
                // Encontrou um par válido "()" e reduz o contador de "("
                open--;
                pairs[i + 1]++; // Incrementa o número de pares válidos acumulados
            }
        }

        // Leitura do número de consultas
        int m = Integer.parseInt(br.readLine());
        StringBuilder output = new StringBuilder();

        // Processamento das consultas
        for (int i = 0; i < m; i++) {
            String[] query = br.readLine().split(" ");
            int li = Integer.parseInt(query[0]);
            int ri = Integer.parseInt(query[1]);

            // Calcular o número de pares válidos no intervalo
            int totalPairs = pairs[ri] - pairs[li - 1];
            int maxLength = totalPairs * 2; // Cada par representa 2 caracteres
            output.append(maxLength).append("\n");
        }

        // Impressão do resultado acumulado para maior eficiência
        System.out.print(output);
    }
}
