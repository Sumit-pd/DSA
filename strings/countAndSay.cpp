#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n==1){
		return "1";
	}
	string smallAns = writeAsYouSpeak(n-1);
	string ans = "";
	int cnt = 0 ;
	for(int i = 0 ; i < smallAns.size() ; i++){
		cnt++;
		if(i == smallAns.size()-1 || smallAns[i] != smallAns[i+1]){
			ans = ans + to_string(cnt) + smallAns[i];
			cnt = 0 ;
		}
	}
	return ans;
}