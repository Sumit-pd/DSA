#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0 ; i < n-1; i++){
        int mini = i ;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[mini] > arr[j] ){
                mini = j ;
            }
        }
        swap(arr[mini],arr[i]) ;
    }
}
