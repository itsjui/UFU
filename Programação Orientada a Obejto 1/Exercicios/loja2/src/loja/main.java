package loja;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Vendedor[] vendedores = new Vendedor[5];
        Admin[] administrativos = new Admin[5];

        for (int i = 0; i < vendedores.length; i++) {
            System.out.println("Dados do vendedor " + (i + 1) + ":");
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            System.out.print("RG: ");
            String rg = scanner.nextLine();
            System.out.print("Salário Base: ");
            double salario = scanner.nextDouble();
            scanner.nextLine();
            vendedores[i] = new Vendedor(nome, rg, (float) salario);
        }
        for (int i = 0; i < administrativos.length; i++) {
            System.out.println("Dados do funcionário administrativo " + (i + 1) + ":");
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            System.out.print("RG: ");
            String rg = scanner.nextLine();
            System.out.print("Salário: ");
            double salario = scanner.nextDouble();
            scanner.nextLine(); 
            administrativos[i] = new Admin(nome, rg, (float) salario);
        }

        for (int i = 0; i < vendedores.length; i++) {
            System.out.print("Digite o total de vendas para o vendedor " + (i + 1) + ": ");
            double vendas = scanner.nextDouble();
            vendedores[i].adicionarVendas(vendas);
        }

        // Adicionando horas extras para os funcionários administrativos
        for (int i = 0; i < administrativos.length; i++) {
            System.out.print("Digite o total de horas extras para o funcionário administrativo " + (i + 1) + ": ");
            int horasExtras = scanner.nextInt();
            administrativos[i].adicionarHoras(horasExtras);
        }

        double totalSalarios = 0;
        System.out.println("\nFolha de Pagamento Mensal:");
        System.out.println("--------------------------------------------");
        System.out.println("Vendedores:");
        for (Vendedor vendedor : vendedores) {
            double salario = vendedor.calculaSalario();
            System.out.println("Nome: " + vendedor.nome + ", Salário: " + salario);
            totalSalarios += salario;
        }
        System.out.println("--------------------------------------------");
        System.out.println("Funcionários Administrativos:");
        for (Admin administrativo : administrativos) {
            double salario = administrativo.calculaSalario();
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
            double salario = vendedor.calculaSalario();
            if (salario > maiorSalario) {
                maiorSalario = salario;
                funcionarioMaiorSalario = vendedor.nome;
            }
            if (salario < menorSalario) {
                menorSalario = salario;
                funcionarioMenorSalario = vendedor.nome;
            }
        }
        for (Admin administrativo : administrativos) {
            double salario = administrativo.calculaSalario();
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