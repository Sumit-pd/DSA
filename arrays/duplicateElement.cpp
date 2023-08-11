#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]]; // this will be moving two time at a time
    } while (slow != fast) ;

    fast = arr[0] ; 
    while (slow!= fast ){
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow ;
}
