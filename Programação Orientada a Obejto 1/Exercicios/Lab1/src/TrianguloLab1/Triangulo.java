package TrianguloLab1;

import java.util.Scanner;
import java.util.ArrayList;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author 12021BSI258
 */
public class Triangulo {

    int l1, l2, l3;
    private int retornaL1;
    private int retornaL2;
    private int retornaL3;
    
    void alteral1(int x) {
        l1 = x;
    }
    void alteral2(int y) {
        l2 = y;
    }
    void alteral3(int z) {
        l3 = z;
    }
    int retornaL1() {
        return l1;
    }

    int retornaL2() {
        return l2;
    }

    int retornaL3() {
        return l3;
    }

    int calculaPerimetro() {
        return l1 + l2 + l3;
    }

    String retornaTipo() {
        if ((l1 == l2)&& (l2 == l3))
           return "equilatero";
        else if ((l1 == l2) || (l2 == l3) || (l1 == l3)) {
           return "isoceles";
        }else{
           return "escaleno";
        }
    }
    public static void main(String a[]){
        Triangulo l1 = new Triangulo();
        Scanner sc = new Scanner(System.in);
        int armazena[] = new int [9];
        System.out.println("Entre com o lado1: ");
        int x = sc.nextInt();
        System.out.println("Entre com o lado2: ");
        int y = sc.nextInt();
        System.out.println("Entre com o lado3: ");
        int z = sc.nextInt();
        l1.alteral1(x);
        l1.alteral2(y);
        l1.alteral3(z);
        System.out.println("Lados de L1");
        System.out.println("L1:" +l1.retornaL1);
        System.out.println("L2:" +l1.retornaL2);
        System.out.println("L3:" +l1.retornaL3);
        System.out.println("perimetro:" + l1.calculaPerimetro());
        System.out.println();
    }
}
