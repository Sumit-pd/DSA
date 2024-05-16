#include <bits/stdc++.h> 
class Node{
    Node * links[26] ;
    int cntPre = 0 ;
    int cntEnd = 0 ;
    public:
    void put(Node * node , char ch ){
        links[ch - 'a' ] = node ;
    }
    Node * get(char ch ){
        return links[ch - 'a' ] ;
    }
    bool contains(char ch ){
        return links[ch-'a'] != NULL ;
    }
    void increasePre(){
        cntPre++ ;
    }
    void increaseEnd(){
        cntEnd++ ;
    }
    int getEnd(){
        return cntEnd ;
    }
    int getCnt(){
        return cntPre ;
    }
    void decrementPre(){
        cntPre-- ;
    }
    void decrementEnd(){
        cntEnd-- ;
    }
};
class Trie{
    Node * root ;
    public:

    Trie(){
        root = new Node() ;
    }

    void insert(string &word){
        Node * node = root ;
        for(int i = 0 ; i < word.size() ; i++ ){
            if(!node -> contains(word[i]) ){
                node -> put(new Node,word[i] ) ;
            }
            node = node ->get(word[i] ) ;
            node -> increasePre() ;
        }
        node -> increaseEnd() ;
    }

    int countWordsEqualTo(string &word){
        Node * node = root ;
        for(int i = 0 ; i < word.size() ; i++ ){
            if(node -> contains(word[i] )){
                node = node -> get(word[i]) ;
            }
            else{
                return 0 ;
            }
        }

        return node -> getEnd() ;
        
    }

    int countWordsStartingWith(string &word){
        Node * node = root ;
        for(int i = 0 ; i < word.size() ; i++ ){
            if(node -> contains(word[i] )){
                node = node -> get(word[i]) ;
            }
            else{
                return 0 ; ;
            }
        }
        return node -> getCnt() ;
    }

    void erase(string &word){
        Node * node = root ;
        for(int i = 0 ; i < word.length() ; i++ ){
            if(node -> contains(word[i]) ){
                node = node -> get(word[i] ) ;
                node -> decrementPre() ;
            }
            else{
                return ;
            }
        }
        node -> decrementEnd() ;
    }
};
