#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int getPriority(char x){
    if(x=='G'){
        return 1;
    }
    else if(x=='B'){
        return 2;
    }
    else{
        return 3;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char x,y;
    cin>>x>>y;
    int one=getPriority(x);
    int two=getPriority(y);
    if(one>=two){
        cout<<x<<endl;
    }
    else{
        cout<<y<<endl;
    }
    return 0;
}