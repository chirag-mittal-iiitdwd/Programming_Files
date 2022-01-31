#include <bits/stdc++.h>
using namespace std;

// Giving errors
class Node{
    public:
    Node*links[26];
    bool flag=true;
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
        flag=false;
    }

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void push(char ch,Node*node){
        links[ch-'a']=node;
    }

    Node*next(char ch){
        return links[ch-'a'];
    }

};

class WordDictionary {
    Node*root;
    bool helper(string word,Node*ptr){
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch!='.'){
                if(!ptr->containsKey(ch)){
                    return false;
                }
                ptr=ptr->next(ch);
            }
            else{
                bool found=false;
                int j=0;
                for(;j<26;j++){
                    if(ptr->containsKey(j+'a')){
                        found=found|helper(word.substr(i+1),ptr->next(j+'a'));
                    }
                    if(found){
                        return true;
                    }
                }
                if(j==26){
                    return false;
                }
            }
        }
        return ptr->flag;
    }

public:
    WordDictionary() {
        Node*root=new Node();
    }

    void addWord(string word) {
        Node*ptr=root;
        int n=word.length();

        for(int i=0;i<n;i++){
            if(!ptr->containsKey(word[i])){
                ptr->push(word[i],new Node());
            }
            ptr=ptr->next(word[i]);
        }
        ptr->flag=true;
    }

    bool search(string word) {
        return helper(word,root);
    }
};


// Accepted Solution
// class TrieNode
// {
// public:
//     bool isWord;
//     unordered_map<char, TrieNode *> children;

//     TrieNode()
//     {
//         isWord = false;
//     }
// };

// class WordDictionary
// {
//     TrieNode *root;

//     void addWordToTrie(string word)
//     {
//         auto cur = root;

//         for (auto ch : word)
//         {
//             if (!cur->children.count(ch))
//                 cur->children[ch] = new TrieNode();

//             cur = cur->children[ch];
//         }

//         cur->isWord = true;
//     }

//     bool searchTrie(TrieNode *cur, int i, string word)
//     {
//         if (i == word.length())
//             return cur->isWord;

//         if (word[i] != '.')
//         {
//             if (!cur->children.count(word[i]))
//             {
//                 return false;
//             }

//             return searchTrie(cur->children[word[i]], i + 1, word);
//         }

//         for (auto it : cur->children)
//         {
//             if (searchTrie(it.second, i + 1, word))
//             {
//                 return true;
//             }
//         }

//         return false;
//     }

// public:
//     WordDictionary()
//     {
//         root = new TrieNode();
//     }

//     void addWord(string word)
//     {
//         addWordToTrie(word);
//     }

//     bool search(string word)
//     {
//         return searchTrie(root, 0, word);
//     }
// };

// // Most optimal
// class TrieNode{
//     public:
//     char c;
//     unordered_map<char, TrieNode *> mp;
//     bool isWord;

//     TrieNode(char c){
//         this->c = c;
//         isWord = false;
//     }
// };

// class WordDictionary{
// public:
//     TrieNode *root;
//     WordDictionary(){
//         root = new TrieNode(' ');
//     }

//     unordered_map<int, vector<string>> mp1;
//     void addWord(string word){
//         mp1[word.length()].push_back(word);
//     }

//     bool search(string word){
//         int n = word.length();
//         for (auto &s : mp1[n]){
//             int i = 0;
//             while ((i < n) && (s[i] == word[i] || word[i] == '.')){
//                 i++;
//             }
//             if (i == n){
//                 return true;
//             }
//         }
//         return false;
//     }
// };