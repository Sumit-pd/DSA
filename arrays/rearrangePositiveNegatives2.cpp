#include <bits/stdc++.h> 

void rearrange(vector<int> &arr)
{
	vector<int> positive ;
	vector<int> negative ;
	for(int i = 0 ; i < arr.size() ; i++ ){
		if(arr[i] >= 0 ){
			positive.push_back(arr[i]) ;
		}
		else{
			negative.push_back(arr[i]);
		}
	}
	
	if(positive.size() > negative.size() ){
		for(int i = 0 ; i < negative.size() ; i++){
			//adding the first negative.size() elements 
			arr[2*i] = positive[i] ;
			arr[2*i+1] = negative[i] ;
		}
		int index = negative.size() * 2 ;
		for(int i = negative.size() ; i < positive.size() ; i++ ){
			arr[index] = positive[i] ;
			index++ ;
		}
	}
	else{
		for(int i = 0 ; i < positive.size() ; i++){
			//adding the first negative.size() elements 
			arr[2*i] = positive[i] ;
			arr[2*i+1] = negative[i] ;
		}
		int index = positive.size() * 2 ;
		for(int i = positive.size() ; i < negative.size() ; i++ ){
			arr[index] = negative[i] ;
			index++ ;
		}
	}
}

