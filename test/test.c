#include<unistd.h>
#include<stdio.h>
#include<io.h>

int main(){
    int a,b,c;
    c=a+b;
    fork();
    printf("hi");
}