
package loja;

public class Vendedor extends Funcionario{
    
    private double totalVendas;
    
    public Vendedor(String nome, String RG, double salario) {
        super(nome, RG, salario);
        this.totalVendas = 0;
    }
    
    
    public void adicionarVendas(double valor){
        this.totalVendas += valor;
    }
    public double getTotalVendas(){
        return totalVendas;
    }
    
    public double calculaSalario(){
        return 0;
    }
}
