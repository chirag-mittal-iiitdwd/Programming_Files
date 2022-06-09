#include<bits/stdc++.h>
using namespace std;

class Node{
    Node*links[26];
    bool flag=false;
    public:
    // checking if we have the character in the trie
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    // Adding the char ch to new trie node
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    // where is the current char pointing to?
    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool getEnd(){
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
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }

        return node->getEnd();
    }

    bool startsWith(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        
        return true;
    }
};