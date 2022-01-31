#include<bits/stdc++.h>
using namespace std;

/*
    Trie is used whenever we want to,
    1.  Insert word or string
    2.  Search if a word is present or not
    3.  Check if there exits a word with the given prefix
*/

class Node{
    public:
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    // Attaching the current character's link with a newly created node
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }

    // This will be used for moving the pointer to the next reference
    Node*next(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    Node*root;
    Trie(){
        root=new Node();
    }

    // O(Length of the word to be inserted)
    void insert(string word){
        Node*node=root;
        int n=word.length();

        for(int i=0;i<n;i++){

            // If the current character is not present then we insert it into our trie
            if(node->containsKey(word[i])==false){
                node->put(word[i],new Node());
            }

            // Move to the next trie
            node=node->next(word[i]);
        }
        node->flag=true;
    }

    bool search(string word){
        Node*node=root;
        int n=word.length();

        for(int i=0;i<n;i++){
            if(node->containsKey(word[i])){
                node=node->next(word[i]);
            }
            else{
                return false;
            }
        }
        return node->flag;
    }

    bool startsWith(string word){
        Node*node=root;
        int n=word.length();

        for(int i=0;i<n;i++){
            if(node->containsKey(word[i])){
                node=node->next(word[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};