#include <bits/stdc++.h>
/*
#brute
-sort the elements of the vector
-check arr[i].second and arr[i+1].first
- we will be having two loops so for checking
time complexity : O(NlogN) + O(N)
space complexity : O(N)
*/
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            // the end the is smaller

            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
                //we are breaking the loop because the array is sorted and we do not need to check futher
            }
        }

        ans.push_back({start, end});
    }
    return ans;
}
/*
-better
*/
vector<vector<int>> mergeOverlappingIntervals(vector< vector<int> > arr){
    int n = arr.size() ;
    vector< vector<int> > ans ;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]) ;
        }
        else{
            ans.back()[1] = max(ans.back()[1] , arr[i][1]) ;
        }
    }
    return ans;
    
}