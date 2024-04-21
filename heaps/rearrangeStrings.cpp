#include <bits/stdc++.h> 
typedef pair<int,char> p ;
string reArrangeString(string &s)
{
	int n = s.length() ;

	unordered_map<char,int> mp ;

	for(auto it : s ){
		mp[it]++ ;
		if(mp[it] > (n+1) /2 ) return "not possible" ;
	}

	priority_queue<p> pq ;

	for(auto it : mp ){
		int freq = it.second ;
		int elem = it.first ;
		if(freq > (n+1)/2 ) return "not possible" ;
		pq.push({freq,elem}) ;
	}

	string ans = "" ;
	while(pq.size() > 1 ){
		auto A = pq.top() ;
		pq.pop() ;
		auto B = pq.top() ;
		pq.pop() ;

		ans.push_back(A.second) ; A.first-- ;
		ans.push_back(B.second) ; B.first-- ;

		if(A.first > 0 ){
			pq.push(A) ;
		}
		if(B.first > 0 ){
			pq.push(B) ;
		}
	}

	if(pq.size()) {
		auto it = pq.top() ;
		ans.push_back(it.second) ;
		pq.pop() ;
	}

	return ans ;


}
