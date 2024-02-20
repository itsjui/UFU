package construtores.e.destrutores;

import java.util.Scanner;


public class Reta {
    private double a;
    private double b;

    public Reta(double a, double b){
        this.a = a;
        this.b = b;
    }
    
    public double getA(){
        return a;
    }
    public double getB(){
        return b;
    }
    
    public String printaPonto(){
        return "y = " +a+"x"+b;
    }

    public boolean verificaReta(double x, double y){
        return y == a*x + b; 
    }

    public boolean verificaParalela(Reta outraReta) {
        return this.a == outraReta.getA();
    }

    public Ponto getIntersecao(Reta outraReta){
        if(this.verificaParalela(outraReta)){
            return null;
        }
        double interX = (outraReta.b - this.b)/(this.a - outraReta.a);
        double interY = this.a * interX + this.b; 
        return new Ponto(interX, interY);
    }
}   
public class Ponto {
    private double x;
    private double y;

    public Ponto(double x, double y){
        this.x = x;
        this.y = y;
    }
     public double getX(){
        return x;
    }

    public double getY(){
        return y;
    }
}   
    

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);

       double a = sc.nextDouble();
       double b = sc.nextDouble();

       Reta reta = new Reta(a, b);
       
       double x = sc.nextDouble();
       double y = sc.nextDouble();

       Ponto ponto = new Ponto (x, y);

       if(reta.verificaReta(ponto)){
        System.out.println("Pertence essa a Reta.");
      }else {
       System.out.println("Não pertence a reta.");
      }
      System.out.println("Represenção" +reta);
}
