#include<bits/stdc++.h>
using namespace std;

void swapThreeNumbers(int &a,int &b,int &c){
    a=a^b^c;
    b=a^b^c;
    c=a^b^c;
    a=a^b^c;
}

int main(){

}