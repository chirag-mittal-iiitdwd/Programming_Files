#include <bits/stdc++.h>
using namespace std;
string decimalToBinary(int n)
{
    string ans;
    for (int i = 1 << 30; i > 0; i = i / 2)
    {
        if (n & i)
        {
            ans += "1";
        }
        else
        {
            ans += "0";
        }
    }
    return ans;
}
int swapNibbles(int n)
{
    string ans;
    for (int i = 1 << 30; i > 0; i = i / 2)
    {
        if (n & i)
        {
            ans += "1";
        }
        else
        {
            ans += "0";
        }
    }
    string subSting = ans.substr(31 - 8, 31);
    string part1 = subSting.substr(0, 4);
    string part2 = subSting.substr(4, 8);
    string concatString = part2 + part1;
    int x = 0;
    int multiplyWith = 1;
    for (int i = 0; i <= 7; i++)
    {
        if (concatString[i] == '1')
        {
            x += pow(2, i);
        }
    }
    return x;
}
int binaryToDec(string str)
{
    int x = 0;
    int multiplyWith = 1;
    for (int i = 0; i <= 7; i++)
    {
        if (str[i] == '1')
        {
            x += pow(2, i);
        }
    }
    return x;
}

int main()
{
    int n;
    cin >> n;
    string ans = decimalToBinary(n);
    cout << ans << endl;
    string subSting = ans.substr(31 - 8, 31);
    string part1 = subSting.substr(0, 4);
    string part2 = subSting.substr(4, 8);
    string concatString = part2 + part1;
    cout << concatString << endl;
    cout << binaryToDec(concatString) << endl;
    cout << swapNibbles(n) << endl;
}