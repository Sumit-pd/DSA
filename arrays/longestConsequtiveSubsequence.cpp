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

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    //we store all the elements in the set
    unordered_set<int> st ;
    for(int i = 0 ; i < n ; i++ ){
        st.insert(arr[i]) ;
    }
    // now the set will take care of duplicates
    int maxi = 1;
    for(int it : st){
        //checking if it is the starting element of the sequence in the arr
        if(st.find(it-1) == st.end()){
            /*if the above is false which means there is an element that is could
             be the starting element but this is not the starting element */
             int count = 1 ;
             while(st.find(it+1) != st.end() ){
                 count++ ;
                 maxi = max(maxi,count) ;
                 it = it + 1;
             }
        }
    }
    return maxi ;
}
//time complexity : O(n) + O(2n)
//space complexity : O(n)
