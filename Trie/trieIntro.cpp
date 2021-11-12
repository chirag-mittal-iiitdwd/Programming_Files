#include<bits/stdc++.h>
using namespace std;

// defining Trie structure
class node{
    public:
    node*links[26];
    bool flag=false;

    // For checking if the current character was alredy present in the array or not
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    // making the new node point to the character in node
    void put(char ch,node*n){
        links[ch-'a']=n;
    }

    // Where is the link of the current charcter pointed to
    node*get(char ch){
        return links[ch-'a'];
    }

    bool setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

// defining the trie class
class trie{
    // The parent of everthing
    node*root;
    public:
    trie(){
        root=new node();
    }

    // Inserting the node into trie
    // Time Complexity : O(len)
    void insert(string word){
        node*n=root;
        for(int i=0;i<word.length();i++){
            // if the current trie node does not contain the current character
            if(!n->containsKey(word[i])){
                n->put(word[i],new node());
            }

            // Moving onto the refrence of the current character
            n->get(word[i]);
        }
        // After entire word has been pushed we need to mark the end by turning the flag as true
        n->setEnd();
    }

    // Checks if the entered word is ending with flag as true
    // Time Complexity : O(len)
    bool search(string word){
        node*n=root;
        for(int i=0;i<word.length();i++){
            if(!n->containsKey(word[i])){
                return false;
            }
            n=n->get(word[i]);
        }
        return n->isEnd();
    }

    // Checks if the word is present at the start or not reguardless of flags value
    // Time Complexity : O(len)
    bool startsWith(string prefix){
        node*n=root;
        for(int i=0;i<prefix.length();i++){
            if(!n->containsKey(prefix[i])){
                return false;
            }
            n=n->get(prefix[i]);
        }
        return true;
    }
};