#include<bits/stdc++.h>
using namespace std;
int subsetSumWithGivenSum(int arr[],int n,int s){
    int tab[n + 1][s + 1];
    tab[0][0] = 1;

    for (int i = 1; i <= s; i++){
        tab[0][i] = 0;
    }
    for (int i = 1; i <= n; i++){
        tab[i][0] = 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= s; j++){
          // if the value is greater than the sum
            if (arr[i - 1] > j){
                tab[i][j] = tab[i - 1][j];
            }
            else{
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - arr[i - 1]];
            }
        }
    }
 
 
    return tab[n][s];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int  s;
    cin>>s;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=subsetSumWithGivenSum(arr,n,s);
    cout<<ans;
    return 0;
}