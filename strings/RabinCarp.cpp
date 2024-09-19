vector<int> stringMatch(string text, string pattern) {
	int n = text.length() ;
	int m = pattern.length();
	vector<int> ans ;
	for(int i = 0 ; i < n-m+1 ; i++ ){
		string str = text.substr(i,m);
		if(str == pattern){
			ans.push_back(i+1);
		}
	}
	return ans ;
}

// other appraoch of solving the same problem
int stringMatch(string text , string pattern){
	int n = text.length() ;
	int m = pattern.length();
	for(int i = 0 ; i < n - m +1 ; i++ ){
		int t = i ;
		int j = 0 ;
		for(j = 0 ; j < m ; j++ ){
			if(text[t] != pattern[j]){
				break ;
			}
			t++ ;
		}
		if(j == m){
			return i ;
		}
	}
	return -1 ;
}




#include<bits/stdc++.h>
// create the hash function 
int PRIME = 101;
long long computeHash(string str){
	// this is rolling hash function
	long long hash = 0 ;
	for(int i = 0 ; i < str.length(); i++ ){
		hash = hash + str[i] * pow(PRIME,i);
	}
	return hash ;
}
// to update the hash 
long long updateHash(long long hash , char oldChar , char newChar , int patternLength){
	//first remove the old character from the hash 
	long long newHash = (hash - oldChar)/PRIME ;
	// add the new char in the hash
	newHash = newHash + newChar*pow(PRIME,patternLength-1); // multiplying with the last index of the pattern string
	return newHash;
}
vector<int> stringMatch(string text, string pattern) {
	int n = text.length();
	int m = pattern.length();
	vector<int> ans ;
	long long textHash = computeHash(text.substr(0,m));
	long long patternHash = computeHash(pattern);
	for(int i = 0 ; i < n-m+1 ; i++ ){
		if(textHash == patternHash){
			if(text.substr(i,m) == pattern){
				ans.push_back(i+1);
			}
		}
		if(i < n-m+1){
			textHash = updateHash(textHash,text[i],text[i+m],m);
		}
	}
	return ans ;
}
