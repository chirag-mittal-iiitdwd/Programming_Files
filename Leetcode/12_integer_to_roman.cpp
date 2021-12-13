#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string>strArr={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int>intArr={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    public:
    string intToRoman(int num) {
        string ans{""};
        int n=strArr.size();
        for(int i=0;i<n;i++){
            int div=num/intArr[i];
            for(int j=0;j<div;j++){
                ans+=strArr[i];
            }
            num-=(div*intArr[i]);
        }
        return ans;
    }
};

// class Solution {
// public:
// string intToRoman(int num) {
//     string ans;
//     int k=num;
//         int l=k/1000;
//         for(int i=0;i<l;i++)
//             ans+='M';
//         k=k-l*1000;
    
//          l=k/900;
//         for(int i=0;i<l;i++)
//             ans+="CM";
//         k=k-l*900;
    
//          l=k/500;
//         for(int i=0;i<l;i++)
//             ans+='D';
//         k=k-l*500;
    
//      l=k/400;
//         for(int i=0;i<l;i++)
//             ans+="CD";
//         k=k-l*400;
    
//    l=k/100;
//         for(int i=0;i<l;i++)
//             ans+='C';
//         k=k-l*100;
    
//      l=k/90;
//         for(int i=0;i<l;i++)
//             ans+="XC";
//         k=k-l*90;
    
//      l=k/50;
//         for(int i=0;i<l;i++)
//             ans+='L';
//         k=k-l*50;
    
//      l=k/40;
//         for(int i=0;i<l;i++)
//             ans+="XL";
//         k=k-l*40;
    
//      l=k/10;
//         for(int i=0;i<l;i++)
//             ans+='X';
//         k=k-l*10;
    
//      l=k/9;
//         for(int i=0;i<l;i++)
//             ans+="IX";
//         k=k-l*9;
    
//      l=k/5;
//         for(int i=0;i<l;i++)
//             ans+='V';
//         k=k-l*5;
    
//      l=k/4;
//         for(int i=0;i<l;i++)
//             ans+="IV";
//         k=k-l*4;
    
//      l=k/1;
//         for(int i=0;i<l;i++)
//             ans+='I';
//         k=k-l*1;
//    return ans;     
// }
// };
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.intToRoman(n)<<endl;
    }
}