#include <bits/stdc++.h> 
//brute force O(n3)
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	set<vector<int>> st ;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = i + 1 ; j < n ; j++ ){
			for(int k = j + 1 ; k < n ; k++ ){
				if(arr[i] + arr[j] + arr[k] == K ){
					vector<int> smallAns ;
					smallAns.push_back(arr[i]) ;
					smallAns.push_back(arr[j]) ;
					smallAns.push_back(arr[k]) ;
					sort(smallAns.begin() , smallAns.end() ) ;
					st.insert(smallAns) ;
				}
			}
		}
	}
	vector< vector<int> > ans(st.begin() , st.end()) ;
	return ans ;
}
//better 
//time complexity : O(n2 * logm)
// space complexity : o(n) + O(n) one for the set and the other for the storing the ans
vector<vector<int>> findTriplets2(vector<int>arr, int n, int K) {
	set<vector<int>> st ;
	for(int i = 0 ; i < n ; i++ ){
		set<int> hashset ; // everytime i changes this is reinitialized
		for(int j = i + 1 ; j < n ; j++ ){
			int third = K - arr[i] - arr[j] ;
			if(hashset.find(third)  != hashset.end() ){
				vector<int> temp = {arr[i] , arr[j] , third } ;
				sort(temp.begin() , temp.end()) ;
				st.insert(temp) ;
			}
			hashset.insert(arr[j]) ;
		}
	}
	vector< vector<int> > ans(st.begin() , st.end()) ;
	return ans ;
}
//optimal
// time complexity : O(n2) + O[nlogn]
// space complexity : O(number of triplets)
vector<vector<int>> findTriplets3(vector<int>arr, int n, int K) {
	vector< vector<int> > ans ;
	sort(arr.begin() , arr.end() ) ;
	for(int i = 0 ; i< n ; i++ ){
		if(i > 0 && arr[i] == arr[i-1]) continue ;
		int j = i + 1 , k = n - 1 ;
		while(j < k ){
			int sum = arr[i] + arr[j] + arr[k] ;
			if(sum < K ){
				j++ ;
			}
			else if(sum > K ) {
				k-- ;
			}
			else{
				vector<int> temp = {arr[i], arr[j] , arr[k] } ;
				ans.push_back(temp) ;
				j++ ;
				k-- ;
				while(j < k && arr[j] == arr[j-1]) j++ ;
				while(j < k && arr[k] == arr[k+1]) k-- ;
				//this is for avoiding the duplicate elements
			}
		
		}
	}
	return ans ;
}
// codestudio : https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028 
