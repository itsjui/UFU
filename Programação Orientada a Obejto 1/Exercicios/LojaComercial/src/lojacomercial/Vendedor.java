
package lojacomercial;


class Vendedor extends Funcionario {
    private double totalVendas;

    // Construtor
    public Vendedor(String nome, String rg, double salarioBase) {
        super(nome, rg, salarioBase);
        this.totalVendas = 0;
    }

    // Método para adicionar vendas
    public void adicionarVendas(double valor) {
        this.totalVendas += valor;
    }

    // Método para calcular o total de vendas durante o mês
    public double getTotalVendas() {
        return totalVendas;
    }

    // Método para calcular o salário a receber
    @Override
    public double calcularSalario() {
        return salarioBase + (totalVendas * 0.05);
    }
}
