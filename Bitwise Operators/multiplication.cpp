#include<bits/stdc++.h>
using namespace std;
int russianPeasantMultiRec(int x,int y){
    if(x==1){
        return y;
    }
    if(x&1){
        return y+russianPeasantMultiRec(x/2,2*y);
    }
    else{
        return russianPeasantMultiRec(x/2,2*y);
    }
}

int russianPeasantMutiIter(int x,int y){
    int res=0;
    while(x>0){
        if(x&1){
            res+=y;
        }
        x=x>>1;
        y=y<<1;
    }
    return res;
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<russianPeasantMultiRec(x,y)<<endl;
    cout<<russianPeasantMutiIter(x,y)<<endl;
}