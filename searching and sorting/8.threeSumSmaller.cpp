#include <bits/stdc++.h> 
int threeSumSmaller(int n, vector<int> arr, int target) {
    int cnt = 0 ;
    sort(arr.begin(),arr.end());
    for(int i = 0 ; i < n ; i++ ){
        int left = i + 1 ;
        int right = n - 1 ;
        while(left < right)
        {
            int sum = arr[i] + arr[left] + arr[right] ;
            if(sum < target){
                cnt+= right - left;
                /*since the value is smaller at right being at
                  larger index then the value will still smaller 
                  if the right is at the smaller index as the sum will 
                  smaller than before */
                left++;
            }
            else {
                right--;
            }
        }
    }
    return cnt ;
}
