/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author mahmudmoeen
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here now it fukin works
       shape1[] S = new shape1[2];
        S[0] = new rekt(4,3);
        S[0].print();
        S[1]= new triangle(4,4);
        S[1].print();
       
      
    }
    
}
