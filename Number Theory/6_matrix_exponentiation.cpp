#include<bits/stdc++.h>
#define ll long long int
using namespace std;

#define N 101
int arr[N][N],I[N][N];

void mult(int A[][N],int B[][N],int dim){
    int res[dim+1][dim+1];
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            res[i][j]=0;
            for(int k=0;k<dim;k++){
                res[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            A[i][j]=res[i][j];
        }
    }
}

void power(int A[][N],int dim,int n){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                I[i][j]=1;
            }
            else{
                I[i][j]=0;
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     mult(I,A,dim);
    // }

    while(n){
        if(n%2){
            mult(I,A,dim),n--;
        }
        else{
            mult(A,A,dim),n/=2;
        }
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j]=I[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}