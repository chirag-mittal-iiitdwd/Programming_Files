#include<bits/stdc++.h>
using namespace std;

vector<int>stockSpanBruteForce(vector<int>stock){
    int n=stock.size();
    vector<int>ans;
    stack<int>st;
    int currentStockSpan=1;
    int mini=INT_MIN;
    for(int i=0;i<n;i++){
        int span=0;
        for(int j=i;j>=0;j--){
            if(stock[j]>=stock[i]){
                span++;
            }
            else{
                ans.push_back(span);
                break;
            }
        }
    }
    return ans;
}

// Stack Approach
// creating a stck of pairs {price,days}
vector<int>stockSpan(vector<int>prices){
    vector<int>ans;
    stack<pair<int,int>>s;
    for(auto price:prices){
        int days=1;
        while(!s.empty() && s.top().first<=price){
            days+=s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(auto it:stockSpan(price)){
        cout<<it<<" ";
    }
    cout<<endl;
}