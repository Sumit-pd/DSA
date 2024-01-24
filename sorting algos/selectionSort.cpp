#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0 ; i < n-1; i++){
        //we will fix the minimum value of from i to n-1 to ith index
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
}