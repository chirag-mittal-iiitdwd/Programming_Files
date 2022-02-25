#include<bits/stdc++.h>
using namespace std;

int maxSubarrySum(vector<int>&v,int&n){
    int maxSum=0,curSum=0;

    for(int i=0;i<n;i++){
        curSum+=v[i];
        if(maxSum<curSum){
            maxSum=curSum;
        }
        if(curSum<0){
            curSum=0;
        }
    }
    return maxSum;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        vector<int>ans(n+1,INT_MIN);
        ans[0]=maxSubarrySum(v,n);
        for(int i=1;i<=n;i++){
            int maxPairSum=INT_MIN;
            int curSum=0;
            
            for(int j=0;j<i;j++){
                curSum+=v[j];
            }
            maxPairSum=max(maxPairSum,curSum);

            for(int j=1;j<n-i+1;j++){
                curSum-=v[j-1];
                curSum+=v[i+j-1];
                maxPairSum=max(maxPairSum,curSum);
            }

            curSum=0;
            vector<int>dup=v;
            for(int j=0;j<i;j++){
                curSum+=v[j];
            }

            if(curSum==maxPairSum){
                for(int k=0;k<i;k++){
                    dup[k]+=x;
                }
                ans[i]=max(ans[i],maxSubarrySum(dup,n));
                for(int k=0;k<i;k++){
                    dup[k]-=x;
                }
            }

            for(int j=1;j<n-i+1;j++){
                curSum-=v[j-1];
                curSum+=v[i+j-1];
                if(curSum==maxPairSum){
                    for(int k=j;k<j+i;k++){
                        dup[k]+=x;
                    }
                    ans[i]=max(ans[i],maxSubarrySum(dup,n));
                    for(int k=j;k<j+i;k++){
                        dup[k]-=x;
                    }
                }
            }
        }

        for(int i=0;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}