#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> backtrack(string &digits, int idx, unordered_map<int, string> &imap){
        if (idx == digits.size()){
            return {""};
        }
        vector<string> ans;
        vector<string> curString = backtrack(digits, idx + 1, imap);
        for (auto left : imap[digits[idx] - '0']){
            for (auto right : curString){
                ans.push_back(left + right);
            }
        }
        return ans;
    }

    vector<string> letterCombinations(string digits){
        if (digits.size() == 0)
            return {};
        unordered_map<int, string> imap;
        imap[2] = "abc";
        imap[3] = "def";
        imap[4] = "ghi";
        imap[5] = "jkl";
        imap[6] = "mno";
        imap[7] = "pqrs";
        imap[8] = "tuv";
        imap[9] = "wxyz";

        return backtrack(digits, 0, imap);
    }
};