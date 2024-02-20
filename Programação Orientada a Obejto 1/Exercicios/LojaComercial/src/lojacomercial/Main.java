
package lojacomercial;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Vetor de vendedores
        Vendedor[] vendedores = new Vendedor[5];
        // Vetor de funcionários administrativos
        Administrativo[] administrativos = new Administrativo[5];

        // Preenchendo os vendedores
        for (int i = 0; i < vendedores.length; i++) {
            System.out.println("Dados do vendedor " + (i + 1) + ":");
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            System.out.print("RG: ");
            String rg = scanner.nextLine();
            System.out.print("Salário Base: ");
            double salarioBase = scanner.nextDouble();
            scanner.nextLine(); // Limpar o buffer do teclado
            vendedores[i] = new Vendedor(nome, rg, salarioBase);
        }

        // Preenchendo os funcionários administrativos
        for (int i = 0; i < administrativos.length; i++) {
            System.out.println("Dados do funcionário administrativo " + (i + 1) + ":");
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            System.out.print("RG: ");
            String rg = scanner.nextLine();
            System.out.print("Salário Base: ");
            double salarioBase = scanner.nextDouble();
            scanner.nextLine(); // Limpar o buffer do teclado
            administrativos[i] = new Administrativo(nome, rg, salarioBase);
        }

        // Adicionando vendas para os vendedores
        for (int i = 0; i < vendedores.length; i++) {
            System.out.print("Digite o total de vendas para o vendedor " + (i + 1) + ": ");
            double vendas = scanner.nextDouble();
            vendedores[i].adicionarVendas(vendas);
        }

        // Adicionando horas extras para os funcionários administrativos
        for (int i = 0; i < administrativos.length; i++) {
            System.out.print("Digite o total de horas extras para o funcionário administrativo " + (i + 1) + ": ");
            int horasExtras = scanner.nextInt();
            administrativos[i].adicionarHorasExtras(horasExtras);
        }

        // Calculando e mostrando a folha de pagamento mensal
        double totalSalarios = 0;
        System.out.println("\nFolha de Pagamento Mensal:");
        System.out.println("--------------------------------------------");
        System.out.println("Vendedores:");
        for (Vendedor vendedor : vendedores) {
            double salario = vendedor.calcularSalario();
            System.out.println("Nome: " + vendedor.nome + ", Salário: " + salario);
            totalSalarios += salario;
        }
        System.out.println("--------------------------------------------");
        System.out.println("Funcionários Administrativos:");
        for (Administrativo administrativo : administrativos) {
            double salario = administrativo.calcularSalario();
            System.out.println("Nome: " + administrativo.nome + ", Salário: " + salario);
            totalSalarios += salario;
        }
        System.out.println("--------------------------------------------");
        System.out.println("Total de Salários: " + totalSalarios);
        System.out.println("Média Salarial: " + (totalSalarios / (vendedores.length + administrativos.length)));

        // Encontrando o funcionário com maior e menor salário
        double maiorSalario = Double.MIN_VALUE;
        double menorSalario = Double.MAX_VALUE;
        String funcionarioMaiorSalario = "";
        String funcionarioMenorSalario = "";
        for (Vendedor vendedor : vendedores) {
            double salario = vendedor.calcularSalario();
            if (salario > maiorSalario) {
                maiorSalario = salario;
                funcionarioMaiorSalario = vendedor.nome;
            }
            if (salario < menorSalario) {
                menorSalario = salario;
                funcionarioMenorSalario = vendedor.nome;
            }
        }
        for (Administrativo administrativo : administrativos) {
            double salario = administrativo.calcularSalario();
            if (salario > maiorSalario) {
                maiorSalario = salario;
                funcionarioMaiorSalario = administrativo.nome;
            }
            if (salario < menorSalario) {
                menorSalario = salario;
                funcionarioMenorSalario = administrativo.nome;
            }
        }
        System.out.println("Funcionário com Maior Salário: " + funcionarioMaiorSalario + ", Salário: " + maiorSalario);
        System.out.println("Funcionário com Menor Salário: " + funcionarioMenorSalario + ", Salário: " + menorSalario);

        scanner.close();
    }
}