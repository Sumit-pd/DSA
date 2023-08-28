#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(n == 0 ){
        return 0 ;
    }
    int ans  = 1 ;
    int count = 1 ;
    sort(arr.begin() , arr.end() );
    for(int i = 1 ; i < n ; i++ ){
        if(arr[i] == arr[i - 1]) continue;
        if(arr[i] == arr[i - 1 ] + 1){
            count++ ;
        }
        else {
            count = 1 ;
        }
        ans = max(count ,ans ) ;
    }
    return ans ;
}


// #include <bits/stdc++.h>
//optimal 

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> mp ;
    for(int i = 0 ; i < n ; i++ ){
        mp.insert(arr[i]) ;
    }

    int ans = 0 ;
    for(auto it : mp){
        int cnt = 1 ;
        if(mp.find(it - 1 ) == mp.end() ){
            int i = it ;
            while(mp.find(i + 1) != mp.end() ){
                cnt++ ;
                i++ ;
            }
            ans = max(ans , cnt ) ;
        }
    }
    return ans ;
    
}

//time complexity : O(n) + O(2n)
//space complexity : O(n)