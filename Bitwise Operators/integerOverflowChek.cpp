#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int addOvf(int *res,int a,int b){
    *res=a+b;
    if(a>0 && b>0 && *res<0){
        return -1;
    }
    if(a<0 && b<0 && *res>0){
        return -1;
    }
    return 0;
}
int main(){
    int *res=new int[(sizeof(int))];
    int x=2147483640;
    int y=10;
    cout<<addOvf(res,x,y)<<endl;
    cout<<"\n"<<*res;
    return 0;
}