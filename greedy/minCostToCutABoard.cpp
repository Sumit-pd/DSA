#include <bits/stdc++.h> 
int boardCutting(vector<int>& horizontal, vector<int>& vertical, int m, int n)
{
    sort(horizontal.begin() , horizontal.end() , greater<int>() ) ;
    sort(vertical.begin() , vertical.end() , greater<int>() ) ;

    int i = 0 ; 
    int j = 0 ;
    int cost = 0 ;
    int h = 1 ;
    int v = 1 ;
    
    while(i < m && j < n ){
        if(horizontal[i] > vertical[j] ){
            cost += horizontal[i] * v ;
            h++;
            i++;
        }
        else{
            cost += vertical[j] * h ;
            v++;
            j++;
        }
    }

    while(i<m){
        cost += horizontal[i] * v ;
        h++;
        i++;
    }
    while(j<n){
        cost += vertical[j] * h ;
        v++;
        j++;
    }

    return cost ;
}
