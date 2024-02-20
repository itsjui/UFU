
package lojacomercial;


class Administrativo extends Funcionario {
    private int horasExtras;

    // Construtor
    public Administrativo(String nome, String rg, double salarioBase) {
        super(nome, rg, salarioBase);
        this.horasExtras = 0;
    }

    // Método para adicionar horas extras
    public void adicionarHorasExtras(int horas) {
        this.horasExtras += horas;
    }

    // Método para calcular o valor das horas extras
    public double calcularValorHorasExtras() {
        return horasExtras * (salarioBase / 100);
    }

    // Método para calcular o salário a receber
    @Override
    public double calcularSalario() {
        return salarioBase + calcularValorHorasExtras();
    }
}

