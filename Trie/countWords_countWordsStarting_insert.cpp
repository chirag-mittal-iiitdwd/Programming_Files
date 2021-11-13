#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node*links[26];
    int cntEndWith=0;
    int cntPrefix=0;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    node*get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,node*n){
        links[ch-'a']=n;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};

class trie{
    node*root;
    public:
    trie(){
        root=new node();
    }
    void insert(string&word){
        node*n=root;
        for(int i=0;i<word.size();i++){
            if(!n->containsKey(word[i])){
                n->put(word[i],new node());
            }
            n=n->get(word[i]);
            n->increasePrefix();
        }
        n->increaseEnd();
    }
    int countWordsEqualTo(string&word){
        node*n=root;
        for(int i=0;i<word.size();i++){
            if(n->containsKey(word[i])){
                n=n->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return n->getEnd();
    }
    int countWordsStartingWith(string&word){
        node*n=root;
        for(int i=0;i<word.size();i++){
            if(n->containsKey(word[i])){
                n=n->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return n->getPrefix();
    }
    void erase(string&word){
        node*n=root;
        for(int i=0;i<word.size();i++){
            if(n->containsKey(word[i])){
                n->get(word[i]);
                n->reducePrefix();
            }
            else{
                return;
            }
        }
        n->deleteEnd();
    }
};