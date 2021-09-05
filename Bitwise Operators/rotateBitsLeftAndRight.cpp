#include<bits/stdc++.h>
using namespace std;

int leftRotate(int n,int d){
    return (n<<d)|(n>>(32-d));
}

int rightRotate(int n,int d){
    return (n>>d)|(n<<(32-d));
}

vector<int>rotate(int n,int d){
    vector<int>ans;
    d%=16;
    unsigned short int x=(n<<d)|(n>>(16-d));
    unsigned short int y=(n>>d)|(n<<(16-d));
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}

int main(){
    int n,d;
    cin>>n>>d;
    cout<<leftRotate(n,d)<<" "<<rightRotate(n,d)<<endl;
}