//pick a pivot arr[i]
//place it at the correct position
/*put all the smaller elements at the left part and the larger elements at the right */
//now do the rest in recursion
#include <bits/stdc++.h> 

int findPartition(vector<int> &arr , int low , int high)
{
    int i = low ;
    int j = high ;
    int pivot = arr[low] ; // we will fix the first element as the pivot 
    while(i < j ){
        // we are keeping all the element smaller than pivot to its left and elements larger to its right
        while(arr[i] <= pivot && i <= high ){
            i++;
        }
        while(arr[j] > pivot && j>=0 ){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    //now place the pivot at its correct index
    swap(arr[low],arr[j]) ;
    return j ;
}
void helper(vector<int> &arr , int low , int high){
    if(low >= high){
        return ;
    }
    //find the pivot and put the pivot in the correct index and return its index as well
    //the following index will also keep all the elements smaller than the pivot to its left a
    //and all the element larger to its right
    int partition = findPartition(arr,low,high);
    helper(arr,low,partition-1);
    helper(arr,partition+1,high);


}
vector<int> quickSort(vector<int> arr)
{
    helper(arr,0,arr.size()-1);
    return arr ;
}
