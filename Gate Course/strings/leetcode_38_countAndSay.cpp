#include <bits/stdc++.h>
using namespace std;
string generator(string str){
    string ans = "";
    unordered_map<char, int>tempCount;
    for (int i = 0; i < str.length() + 1; i++){
        if (tempCount.find(str[i]) == tempCount.end() && i > 0){
            auto prev = tempCount.find(str[i - 1]);
            ans += to_string(prev->second) + prev->first;
            tempCount.clear();
        }
        tempCount[str[i]]++;
    }
    return ans;
}
string countnndSay(int n){
    string res = "1";
    for (int i = 1; i < n; i++){
        res = generator(res);
    }
    return res;
}
int main(){
    int N;
    cin>>N;
    cout << countnndSay(N) << endl;
    return 0;
}
