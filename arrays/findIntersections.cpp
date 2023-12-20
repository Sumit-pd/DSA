#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Brute
	unordered_map<int,int> mp ;
	vector<int> ans ;
	for(int i = 0 ; i < n ; i++ ){
		mp[arr1[i]]++ ;
	}
	for(int i = 0 ; i < m ; i++ ){
		if(mp[arr2[i]] != 0 ){
			ans.push_back(arr2[i]) ;
			mp[arr2[i]]-- ;
		}
		
	}
	return ans ;
}


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)

{
	//optimal

    int i = 0, j = 0;

    vector<int> ans;

    while(i < n && j < m){

        if(arr1[i] == arr2[j]){

            ans.push_back(arr1[i]);

            i++;

            j++;

        } else if(arr1[i] < arr2[j]){

            i++;

        }else{

            j++;

        }

    }

    return ans;

}