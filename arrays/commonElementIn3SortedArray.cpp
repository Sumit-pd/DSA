#include <bits/stdc++.h> 
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> ans ;
    unordered_map<int,int> mp ;
    for(int it : a){
        if(mp[it] < 1){
            mp[it]++ ;
        }
    }
    for(int it : b ){
        if(mp[it] == 1){
            mp[it]++ ;
        }
    }
    for(int it : c ){
        if(mp[it] == 2 ){
            mp[it]++ ;
            ans.push_back(it) ;
        }
    }

    return ans ;
}
