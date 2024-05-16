/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node{

    public:
    Node *links[26] ;
    bool flag = false ;

    bool contains(char ch ){
        return links[ch-'a'] != NULL ;
    }
    void createNode(char ch , Node * node ){
        links[ch - 'a' ] = node ;
    }

    Node * getNode(char ch ){
        return links[ch - 'a' ] ;
    }

    void setEnd(){
        flag = true ;
    }

    bool isEnd(){
        return flag == true ;
    }
};
class Trie {

private:
    Node * root ;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node() ;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * node = root ;
        for(int i = 0 ; i < word.length() ; i++ ){
            if(!node ->contains(word[i])){
                node -> createNode(word[i],new Node() ) ;
            }
            node = node -> getNode(word[i] ) ;
        }
        node -> setEnd() ;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * node = root ;
        for(int i = 0 ; i < word.size() ; i++ ){
            if(!node -> contains(word[i] ) ){
                return false ;
            }
            node = node -> getNode(word[i]) ;
        }
        return node -> isEnd() ;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node * node = root ;
        for(int i = 0 ; i < word.size() ; i++ ){
            if(!node -> contains(word[i] ) ){
                return false ;
            }
            node = node -> getNode(word[i]) ;
        }
        return true  ;
    }
};