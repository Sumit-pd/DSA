#include <bits/stdc++.h> 
//brute
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int> , greater<int> > pq ;
    for(auto it : kArrays ){
        for(int val : it ){
            pq.push(val) ;
        }
    }

    vector<int> ans ;
    while(pq.size()){
        int val = pq.top() ;
        pq.pop() ;
        ans.push_back(val) ;
    }

    return ans ;
}

//optimal
#include <bits/stdc++.h> 
class Node{
    public:
    int data ;
    int i ; 
    int j ; 
};
class cmp{
    public:
    bool operator()(Node * a , Node * b){
        return a->data > b->data ;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*,vector<Node*>,cmp> pq ;
    for(int i = 0 ; i < kArrays.size() ; i++ ){
        Node * newNode = new Node() ;
        newNode -> data = kArrays[i][0] ;
        newNode -> i = i ;
        newNode->j = 0 ;
        pq.push(newNode) ;
    }
    vector<int> ans ;
    while(pq.size()){
        Node * top = pq.top() ;
        pq.pop() ;
        int data =top-> data ;
        int i = top -> i ;
        int j = top -> j ;
        ans.push_back(data) ;
        j++;
        if( j < kArrays[i].size() ){
            Node * newNode = new Node() ;
            newNode -> data = kArrays[i][j] ;
            newNode -> i = i ;
            newNode->j = j ;
            pq.push(newNode) ;
        }
    }
    return ans ;
}

