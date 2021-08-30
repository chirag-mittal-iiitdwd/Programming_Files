#include<bits/stdc++.h>
using namespace std;
void decToBinary(long long int n){
    long long int binaryNum[32];
    long long int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (long long int j = i - 1; j >= 0; j--){
        cout << binaryNum[j];
    }
}
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        long long int o=pow(2,n);
        long long int arr[o];
        vector<string>a(n);
        for(long long int i=0;i<n;i++){
            cin>>a[i];
        }
        for(long long int i=0;i<n;i++){
            long long int number=0;
            for(long long int j=0;j<n;j++){
                number+=(a[i][j]-'0')*pow(2,j);
            }
            arr[number-1]=1;
        }
        for(long long int i=0;i<o;i++){
            if(arr[i]!=1){
                decToBinary(i);
                break;
            }
        }
    }
}