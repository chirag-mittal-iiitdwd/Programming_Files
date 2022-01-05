#include<bits/stdc++.h>
using namespace std;

class Solution {
    void merge(vector<int>&time,int l,int r,int mid,int&cnt){
        int b[l+r+1];
        int i=l,j=mid+1,k=l;
        while(i<=mid && j<=r){
            int sum=time[i]+time[j];
            cout<<"sum : "<<sum<<endl;
            if((sum%60)==0){
                cnt++;
                cout<<sum<<" "<<time[i]<<" "<<time[j]<<endl;
            }
            if(time[i]>=time[j]){
                b[k]=time[j];
                j++;
            }
            else{
                b[k]=time[i];
                i++;
            }
            k++;
        }
        while(i<=mid){
            b[k]=time[i];
            i++;
            k++;
        }
        while(j<=r){
            b[k]=time[j];
            j++;
            k++;
        }
        for(int x=l;x<=r;x++){
            time[x]=b[x];
        }
    }
    void mergeSort(vector<int>&time,int l,int r,int&cnt){
        if(l<r){
            int mid=(l-((l-r)/2));
            mergeSort(time,l,mid,cnt);
            mergeSort(time,mid+1,r,cnt);
            merge(time,l,r,mid,cnt);
        }
    }
    public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt=0;
        int l=0,r=time.size()-1;
        sort(time.begin(),time.end());
        mergeSort(time,l,r,cnt);
        return cnt;
    }
};

class Solution2{
    public:
    int numPairsDivisibleBy609(vector<int>&time){
        int cnt=0;
        int n=time.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(((time[i]+time[j])%60)==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

class Solution3 {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size(),count=0;
        map<int,int>mp; 
        for(int i=0;i<n;i++){
            mp[time[i]%60]++;
        }
        
        for(int i=0;i<n;i++){
           int val=time[i]%60;
           mp[val]--; 
           if(mp[(60-val)%60]>0)count+=mp[(60-val)%60]; 
        }
        return count;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution obj;
    cout<<obj.numPairsDivisibleBy60(nums)<<endl;
}
