/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package javaapplication1;

import java.util.Scanner;

/**
 *
 * @author juice
 */
public class triangulo {

    public int getLado1() {
        return lado1;
    }

    public void setLado1(int lado1) {
        this.lado1 = lado1;
    }

    public int getLado2() {
        return lado2;
    }

    public void setLado2(int lado2) {
        this.lado2 = lado2;
    }

    public int getLado3() {
        return lado3;
    }

    public void setLado3(int lado3) {
        this.lado3 = lado3;
    }
    private int lado1;
    private int lado2;
    private int lado3;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Entre com o lado1: ");
        int lado1 = sc.nextInt();
        System.out.println("Entre com o lado2: ");
        int lado2 = sc.nextInt();
        System.out.println("Entre com o lado3: ");
        int lado3 = sc.nextInt();
    }
    
}
