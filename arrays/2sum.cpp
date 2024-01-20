#include<bits/stdc++.h>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	vector<pair<int,int>> ans ;
    unordered_map<int,int> mp ;
    for(int i = 0 ; i < n ; i++ ){
        int val = target - arr[i] ;
        if(mp[val] != 0 ){
            ans.push_back({arr[i],val});
            mp[val]--;
        }
        else{
            mp[arr[i]]++;
        }
    }
    if(ans.size() == 0 ){
        ans.push_back({-1,-1});
    }
    return ans ;
}


