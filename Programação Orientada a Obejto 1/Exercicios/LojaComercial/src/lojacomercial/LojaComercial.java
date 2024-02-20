package lojacomercial;

// Classe ancestral para os funcionários
class Funcionario {
    protected String nome;
    protected String rg;
    protected double salarioBase;

    // Construtor
    public Funcionario(String nome, String rg, double salarioBase) {
        this.nome = nome;
        this.rg = rg;
        this.salarioBase = salarioBase;
    }

    // Método para calcular o salário a receber
    public double calcularSalario() {
        return 0; // Implementado nas classes filhas
    }
}
