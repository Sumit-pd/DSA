#include <bits/stdc++.h> 
class Node{
    public :
    int prices ;
    int ind;
};
bool cmp(Node a , Node b){
    return a.prices < b.prices ;
}
int maxStock(vector<int> &prices, int n, int amount){
    Node arr[n] ;
    for(int i = 0 ; i < n; i++ ){
        arr[i].prices = prices[i] ;
        arr[i].ind = i + 1 ;
    }
    sort(arr,arr+n,cmp) ;
    int maxi = 0 ;


    for(int i = 0 ; i < n ;i++ ){
        int price = arr[i].prices ;
        int limit = arr[i].ind ;
        if(amount >= price * limit){
            maxi += limit ;
            amount -= price * limit ;
        }
        else{
            maxi += amount / price ;
            break ;
        }
    }
    return maxi ;


    return maxi ;
}
