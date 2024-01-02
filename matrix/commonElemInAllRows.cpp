#include<bits/stdc++.h>
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    unordered_map<int,int> mp ;
    int n = mat.size() ;
    int m = mat[0].size();
    for(int i = 0 ; i < m ; i++ ){
        mp[mat[0][i]] = 1 ;
    }
    for(int i = 1 ; i< n ; i++ ){
        for(int j = 0 ; j < m ; j++ ){
            if(mp[mat[i][j]] == i ){
                mp[mat[i][j]] = i+1;
            }
        }
    }
    vector<int> ans ;
    for(auto it : mp){
        if(it.second == n){
            ans.push_back(it.first);
        }
    }
    return ans ;
}
//time complexity : O(m*n)
