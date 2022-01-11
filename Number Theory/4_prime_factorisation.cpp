#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(N)
void primeFact(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
}

// We can use the fact that the number will have one divisor below sqrt(N)
// Time Complexity : O(sqrt(n))
void primeFact1(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }

    if(n>1){
        // Trigerred when the number is prime
        cout<<n<<"^"<<endl;
    }
}


// Time Complexity : O(logN), Using sieve
int arr[100001];
void primeFactUsingSieve(){
    int maxN=100000;
    for(int i=1;i<=maxN;i++){
        arr[i]=i;
    }

    for(int i=4;i<=maxN;i+=2){
        arr[i]=2;
    }

    for(int i=3;i*i<=maxN;i++){
        if(arr[i]==i){
            for(int j=i*i;j<=maxN;j+=i){
                if(arr[j]=j){
                    arr[j]=i;
                }
            }
        }
    }
}

int main(){
    primeFactUsingSieve();
    int n;
    cin>>n;
    while(n>1){
        int cnt=0;
        int cur=arr[n];
        cout<<arr[n]<<"^";
        while(cur==arr[n]){
            cnt++;
            n=n/arr[n];
        }
        cout<<cnt<<endl;
    }
}