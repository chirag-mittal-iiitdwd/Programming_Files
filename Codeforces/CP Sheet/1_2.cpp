#include<bits/stdc++.h>
/*
    Soring
    Stack
    Queue
    Dynamic Programming
    Backtracking
    Linked List
    Sliding Window
    Tree
    Two Pointer
    Binary Search
    Maths
    Graph
    Greedy
    Heaps
    Hashing
*/
using namespace std;
#define int long long int
#define mod 1000000007
// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int n=82828;
//     // cin>>n;
//     string str="";

//     while(n){
//         int cur=n%10;
//         n/=10;
//         if(9-cur<cur){
//             str+=to_string(9-cur);
//         }
//         else{
//             str+=to_string(cur);
//         }
//     }
//     if(str[str.size()-1]=='0'){
//         str[str.size()-1]='9';
//     }

//     reverse(str.begin(),str.end());
//     int ans=stoi(str);
//     cout<<ans<<endl;
//     return 0;
// }

int32_t main()
{
    string s;
    cin >> s;
 
    for (int i = 0; i < s.size(); i++) {
        if (i != 0 || s[i] != '9') {
            int a = s[i] - '0',
                b = 9 - a;
 
            cout << min(a,b);
        } else {
            cout << s[i];
        }
    }
 
    cout << endl;
 
    return 0;
}