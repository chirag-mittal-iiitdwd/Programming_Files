#include<bits/stdc++.h>
using namespace std;

class Node{
    Node* links[26];
    bool flag=false;
    public:
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void insertNode(char ch,Node*node){
        links[ch-'a']=node;
    }

    Node* nextNode(char ch){
        return links[ch-'a'];
    }

    void toggleEnd(){
        flag=true;
    }

    bool checkEnd(){
        return flag;
    }
};

class Trie{
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->insertNode(word[i],new Node());
            }
            node=node->nextNode(word[i]);
        }
        node->toggleEnd();
    }

    Node*returnPointerToSearch(string searchQuery){
        Node*node=root;
        for(int i=0;i<searchQuery.size();i++){
            if(!node->containsKey(searchQuery[i])){
                return NULL;
            }
            node=node->nextNode(searchQuery[i]);
        }
        return node;
    }

    vector<string>atmost3Results(string searchQuery){
        Node*res=returnPointerToSearch(searchQuery);
        if(res==NULL){
            return {};
        }
        vector<string>ans;
        findAllStrings(res,ans,searchQuery);
        return ans;
    }

    void findAllStrings(Node*node,vector<string>&ans,string cur){
        if(node->checkEnd()){
            if(cur.size()<3){
                ans.push_back(cur);
            }
            return;
        }

        for(char i='a';i<='z';i++){
            if(node->containsKey(i)){
                findAllStrings(node->nextNode(i),ans,cur+i);
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* t=new Trie();
        for(int i=0;i<products.size();i++){
            t->insert(products[i]);
        }

        vector<vector<string>>ans;
        for(int i=0;i<searchWord.size();i++){
            string currentSearch=searchWord.substr(0,i+1);
            ans.push_back(t->atmost3Results(currentSearch));
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;

        for(int i=0;i<searchWord.size();i++){
            string curSearch=searchWord.substr(0,i+1);

            vector<string>curAns;
            int sugCnt=0;

            for(string curProd:products){
                if(sugCnt<3 && curProd.find(curSearch)==0){
                    curAns.push_back(curProd);
                    sugCnt++;
                }
            }
            ans.push_back(curAns);
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<string>ans;
        string curSearch="";

        for(int i=0;i<searchWord.size();i++){
            curSearch+=searchWord[i];
            vector<string>suggested;
            auto it=lower_bound(products.begin(),products.end(),curSearch);
            for(int i=0;i<3 && it+i!=products.end();i++){
                string res=*(it+i);
                if(res.find())
            }
        }
    }
};