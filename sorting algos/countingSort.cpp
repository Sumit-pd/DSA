#include <bits/stdc++.h> 
vector<int> sort(int n, vector<int> &arr)
{
    int maxi = *max_element(arr.begin(),arr.end()) ;
    int mini = *min_element(arr.begin(),arr.end()) ;
    vector<int> count(maxi - mini + 1 ) ;
    for(auto it : arr){
        count[it-mini]++ ;
    }

    for(int i = 1 ; i < count.size() ; i++ ){
        count[i] += count[i-1] ;
    }

    vector<int> ans(n) ;
    for(int i = n -1 ; i>= 0 ; i--){
        int ind = count[arr[i]- mini] - 1 ;
        ans[ind] = arr[i] ;
        count[arr[i]- mini]--;
    }

    return ans ;
}
