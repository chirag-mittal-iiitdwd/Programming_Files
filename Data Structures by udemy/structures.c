#include<stdio.h>
struct rectangle{
    int length;
    int breadth;
};
int main(){
    // Now this structure is not consuming any memory now unless we declare a struct
    // Declaring the struct variable
    struct rectangle s;

    // Here 4 bytes are reserved for length and 4 for breadth in total 8 bytes
    printf("%d",sizeof(s));

    // Declare and initialise
    struct rectangle r={10,5};

    // All this memory is occupying the space in stack memory
    
}