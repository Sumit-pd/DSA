void helper(BinaryTreeNode<int> * root , int k , int &cnt , int &ans ){
    if(root == NULL){
        return ;
    }
    helper(root -> left , k , cnt , ans ) ;
    cnt++ ;
    if(cnt == k ){
        ans = root -> data ;
        return ;
    }
    helper(root -> right , k , cnt , ans ) ;
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int ans = -1 ;
    int cnt = 0 ;
    helper(root,k,cnt,ans) ;
    return ans ;
}



/************************************************************/
void helper(TreeNode<int> * root , int k , int &cnt, int &ans){
    if(root == NULL){
        return ;
    }
    helper(root -> right , k , cnt , ans ) ;
    cnt++ ;
    if(k == cnt ){
        ans = root -> data ;
        return ;
    }
    helper(root -> left , k ,cnt , ans ) ;

}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1 ;
    int cnt = 0 ;
    helper(root,k,cnt,ans) ;
    return ans ;
}




//using quick select

#include <bits/stdc++.h> 
int partition(vector<int> &arr , int low , int high){
	int randNum = rand()%(high-low + 1) + low;
	swap(arr[low],arr[randNum]) ;
	int pivot = arr[low] ;
	int i = low +1;
	int j = high ;
	while(i <= j){
		while(arr[i] < pivot && i <= j){
			i++ ;
		}
		while(arr[j] >= pivot && i <= j){
			j-- ;
		}
		if(i < j ){
			swap(arr[i],arr[j]) ;
		}
	}
	swap(arr[j],arr[low]) ;
	return j;
}
int helper(vector<int> &arr ,int size, int K , int low , int high){
	if(low > high) return -1 ;

	int part = partition(arr,low,high) ;
	if(part == arr.size() - K){
		return arr[part] ;
	}
	else if(part < arr.size() - K){
		return helper(arr,size,K,part+1,high) ;
	}
	else{
		return helper(arr,size,K,low,part-1) ;
	}
}
int kthLargest(vector<int>& arr, int size, int K)
{
	return helper(arr,size,K,0,size-1) ;
}
