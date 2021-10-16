#include <bits/stdc++.h>
using namespace std;
bool isShuffledSubstring(string x, string y){
    int l1 = x.length();
    int l2 = y.length();
    if (l1>l2){
        return false;
    }
    else{
        sort(x.begin(), x.end());
        cout<<"X after sort : "<<x<<endl;
        for (int i = 0; i < l2; i++){
            if (i + l1 - 1 >= l2){
                cout<<"exeif"<<endl;
                return false;
            }
            string str = "";
            for (int j = 0; j < l1; j++){
                str.push_back(y[i + j]);
            }

            cout<<"str after pushing : "<<str<<endl;
            sort(str.begin(), str.end());
            cout<<"str after sort : "<<str<<endl;
            if (str == x){
                cout<<"exe second if"<<endl;
                return true;
            }
        }
    }
}

int main(){
    string str2,str1;
    cin>>str1>>str2;
    bool a = isShuffledSubstring(str1, str2);
    if (a)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}