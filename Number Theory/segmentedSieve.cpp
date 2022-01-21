// https://www.spoj.com/problems/PRIME1/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

vector<int>primes;
void sieveFun(){
    vector<bool>sieve(100001,false);
    int size=100000;
    sieve[0]=sieve[1]=true;
    for(int i=2;i*i<=size;i++){
        if(!sieve[i]){
            for(int j=i*i;j<=size;j+=i){
                sieve[j]=true;
            }
        }
    }

    for(int i=1;i<=size;i++){
        if(!sieve[i]){
            primes.push_back(i);
        }
    }
}

void segmentedPart(int l,int r){
    if(l==1){
        l++;
    }
    int size=r-l+1;
    vector<bool>arr(size,false);
    
    for(auto &it:primes){
        if(it*it<=r){
            int i=(l/it)*it;  // First muliple of prime
            if(i<l){  // If the multiple is less than lower limit than increment the multiple
                i+=it;
            }

            for(;i<=r;i+=it){
                if(i!=it){
                    arr[i-l]=true;
                }
            }
        }
    }

    for(int i=0;i<size;i++){
        if(!arr[i]){
            cout<<l+i<<endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieveFun();
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        segmentedPart(l,r);
    }
    return 0;
}