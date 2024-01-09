#include <bits/stdc++.h> 
void helper(string str,string output,int ind , vector<string> &ans){
	if(ind >= str.length()){
		if(output ==""){
			return ;
		}
		ans.push_back(output);
		return ;
	}
	output += str[ind] ;
	helper(str,output,ind+1,ans);
	output.pop_back() ;
	helper(str,output,ind+1,ans);
}

vector<string> subsequences(string str){
	vector<string> ans ;
	helper(str,"",0,ans);
	return ans ;
	
}
