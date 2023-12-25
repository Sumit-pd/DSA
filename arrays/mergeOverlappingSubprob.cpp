#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
bool cmp(const vector<int> &a , const vector<int> &b){
    return a[0] < b[0] ;
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size() ;
    vector<vector<int>> ans ;
    sort(intervals.begin() , intervals.end() , cmp ) ;
    ans.push_back(intervals[0]) ; // this is the first element of the intervals array
    for(int i = 1 ; i < n ;i++ ){
        if(ans.back()[1] >= intervals[i][0]){
            ans.back()[1] = max(intervals[i][1] , ans.back()[1]) ;
        }
        else{
            ans.push_back(intervals[i]) ;
        }
    }
    return ans ;
}
