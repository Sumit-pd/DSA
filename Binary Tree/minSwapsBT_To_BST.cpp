#include <bits/stdc++.h> 
void inorderFinder(vector<int> arr , vector<int> &inorder , int n , int ind ){
    if(ind >= n ){
        return ;
    }
    inorderFinder(arr, inorder,n , 2 *  ind + 1 ) ;
    inorder.push_back(arr[ind]) ;
    inorderFinder(arr,inorder,n, 2 * ind + 2 ) ;
}
int minSwaps(vector<int> &arr)
{
	int n = arr.size() ;
	vector<pair<int,int>> newArr ;
	for(int i = 0 ; i < n ; i++ ){
		newArr.push_back({arr[i], i}) ;
	}

	sort(newArr.begin() , newArr.end() ) ;

	int ans = 0 ;
	for(int i = 0 ; i < n ; i++ ){
		if(i != newArr[i].second ){
			ans++ ;
			swap(newArr[i] , newArr[newArr[i].second]) ;
			i--;
		}
	}

	return ans ;
}
int minimumSwaps(vector<int>&arr, int n) {
	vector<int> inorder ;
    inorderFinder(arr,inorder,n,0) ;
    return minSwaps(inorder) ;
}