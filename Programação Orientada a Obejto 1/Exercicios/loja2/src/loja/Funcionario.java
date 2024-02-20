package loja;

public class Funcionario {
    protected String nome;
    protected String RG;
    protected final double salario;

    public Funcionario(String nome, String RG, double salario){
        this.nome = nome;
        this.RG = RG;
        this.salario = salario;
    }
    
    public String getNome(){
        return nome;
    }
    public String setNome(String nome){
        return nome;
    }
    
    public String getRG(){
        return RG;
    }
    
    public String setRG(String RG){
        return RG;
    }
    
    public double getSalario(){
        return salario;
    }
    
}