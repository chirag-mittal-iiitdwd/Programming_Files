#include<bits/stdc++.h>
using namespace std;

class Node{
    Node*arr[26];
    vector<int>indexes;
    public:

    bool constains(char ch){
        return arr[ch-'a'];
    }

    void put(char ch,Node*newNode){
        arr[ch-'a']=newNode;
    }

    Node*getNext(char ch){
        return arr[ch-'a'];
    }

    void putIdx(int idx){
        indexes.push_back(idx);
    }

    vector<int>getIndex(){
        return indexes;
    }
};

class WordFilter{
    Node*prefixRoot;
    Node*suffixRoot;

    void insert(Node*root,string&s,int i){
        for(auto&it:s){
            if(root->constains(it)==NULL){
                root->put(it,new Node());
            }
            root=root->getNext(it);
            root->putIdx(i);
        }
    }

    vector<int>search(Node*root,string&word){
        for(auto&it:word){
            if(root->constains(it)==NULL){
                return {};
            }
            root=root->getNext(it);
        }
        return root->getIndex();
    }

    public:
    WordFilter(vector<string>&words){
        prefixRoot=new Node();
        suffixRoot=new Node();
        int i=0;
        for(auto&word:words){
            insert(prefixRoot,word,i);
            reverse(word.begin(),word.end());
            insert(suffixRoot,word,i);
            i++;
        }
    }

    int f(string prefix,string suffix){
        vector<int>prefixIndexes=search(prefixRoot,prefix);
        reverse(suffix.begin(),suffix.end());
        vector<int>suffixIndexes=search(suffixRoot,suffix);

        int i=prefixIndexes.size()-1,j=suffixIndexes.size()-1;
        while(i>=0 && j>=0){
            int pre=prefixIndexes[i],suff=suffixIndexes[j];
            if(pre==suff){
                return pre;
            }
            (pre<suff)?j--:i--;
        }
        return -1;
    }
};