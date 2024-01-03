#include<bits/stdc++.h>
//brute
bool isAnagram(string str1 , string str2)
{
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	return str1 == str2
}
//better
bool isAnagram(string str1, string str2)
{
    int n = 27;
    vector<int> freq(n,0);
    for(char it : str1){
        freq[it - 'a']++;
    }
    for(char it : str2){
        freq[it - 'a']--;
    }
    for(int it : freq){
        if(it != 0){
            return false;
        }
    }
    return true ;
}
