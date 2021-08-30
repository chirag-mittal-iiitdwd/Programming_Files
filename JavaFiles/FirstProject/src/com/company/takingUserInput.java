package com.company;
import java.util.Scanner;
public class takingUserInput {
    public static void main(String[] args) {
        System.out.println("Taking input from the user");
        Scanner sc=new Scanner(System.in);
//        System.out.println("Enter Number 1 : ");
//        int a=sc.nextInt();
//        For checking whether user has given a number or not
        boolean b1=sc.hasNextInt();
        System.out.println(b1);
//        System.out.println("Enter number 2 : ");
//        int b=sc.nextInt();
//        int sum=a;
//        System.out.print("The sum of these numbers is: ");
//        System.out.println(sum);
    }
}
