#include <bits/stdc++.h> 
//brute 
#include <bits/stdc++.h> 
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) {
    if(arr2.size() > arr1.size()){
        return false ;
    }
    for(int j = 0 ; j < m ; j++ ){
        bool check = false ;
        for(int i = 0 ; i < n ; i++ ){
            if(arr1[i] == arr2[j]){
                arr1[i] = -1 ;
                check = true ;
                break ;
            }
        }
        if(check == false){
            return false ;
        }

    }
    return true ;
}
//optimal
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) {
    if(arr2.size() > arr1.size()){
        return false ;
    }
    vector<int> mp(n,0) ;
    for(int i = 0 ; i < n ; i++ ){
        mp[arr1[i]]++ ;
    }
    for(int i = 0 ; i < m ; i++ ){
        if(mp[arr2[i]] == 0){
            return false ;
        }
        mp[arr2[i]]-- ;
    }
    return true ;
}
