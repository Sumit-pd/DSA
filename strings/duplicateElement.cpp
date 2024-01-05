#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    map<char,int> mp ;
    for(auto it : s ){
        mp[it]++;
    }
    vector<pair<char,int>> ans;
    for(auto it : mp){
        if(it.second > 1){
            ans.push_back(it) ;
        }
    }
    return ans;
}
#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    vector<int> alpha(128,0) ;
    vector<pair<char,int>> ans;
    for(auto it : s){
        alpha[it]++;
    }
    for(int i = 0 ; i < 128 ; i++ ){
        if(alpha[i] > 1){
            pair<char,int> smallAns ;
            smallAns.first = char(i) ;
            smallAns.second = alpha[i];
            ans.push_back(smallAns);
        }
    }
    return ans ;
}
