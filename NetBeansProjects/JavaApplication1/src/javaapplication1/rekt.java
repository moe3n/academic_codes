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
public class rekt extends shape1{
    
    int y;
    rekt(int x,int y)
    {
        super(x);
        this.y=y;
    }
    
    @Override
    int getVolumes()
    {
        return x*y;
    }
    @Override
    void print()
    {
        System.out.println(this.getVolumes());
    }
    }
    

