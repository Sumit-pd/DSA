#include <bits/stdc++.h> 
int findMinDiff(int n, int m, vector<int> arr) {
    int mini = INT_MAX ;
    sort(arr.begin() , arr.end() ) ;
    for (int i = 0; i <= n-m; i++)
    {
        mini =  min(mini,arr[i+m-1] - arr[i]);
    }
    return mini ;
}