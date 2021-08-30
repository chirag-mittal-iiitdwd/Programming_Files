/*

These numbers are a sequence of natural numbers that occur 
in various counting problems, often involving recursively 
defines objects
their closed form is in terms of binomial coefficients

        C = 2n(C)n / n+1   =  Sum(C(i)C(n-i)), i=0 to n-1

*/
/*

----> Application of catalan numbers
1. Possible Bst's
2. Paranthesis / Bracket combinations
3. Possible forests
4. Ways of triangulations
5. Possible paths in matrix
6. Divide a circle using N chords

*/
#include<iostream>
using namespace std;

int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<=n-1;i++){
        res+=catalan(i)*catalan(n-i-1);
        // here we have used n-i-1 because n is not 0 based value
        // It is a 1 based value so it adds 1 if we dont subtract
    }

    return res;
}

int main(){
    for(int i=0;i<11;i++){
        cout<<catalan(i)<<" ";
    }
}