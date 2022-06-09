#include<bits/stdc++.h>
using namespace std;

class Node{
    Node*links[26];
    int cntEndWith=0;
    int cntPrefix=0;
    public:

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void push(char ch,Node*node){
        links[ch-'a']=node;
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
                node->push(word[i],new Node);
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }

        node->deleteEnd();
    }
};