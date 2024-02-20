
package loja;

public class Admin extends Funcionario{
    
    private int horaExtra;
    
    public Admin(String nome, String RG, float salario){
    super(nome, RG, salario);
    this.horaExtra = 0;
    }
    
    public void adicionarHoras(int horas){
        this.horaExtra += horas;
    }
    public double calculaValorHH(){
        return horaExtra * (salario/100);
    }
    
    public double calculaSalario(){
        return salario + calculaValorHH();
    }
}
