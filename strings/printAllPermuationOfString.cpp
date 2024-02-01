#include<bits/stdc++.h>
void helper(int index , string str, vector<string> &ans){
    if(index == str.length()){
        ans.push_back(str);
        return ;
        //we have added one permuation
    }
    for(int i = index ; i < str.length() ; i++ )
    {
        swap(str[i],str[index]);
        helper(index+1,str,ans);
        swap(str[i],str[index]);
    }
}
vector<string> generatePermutations(string &str)
{
    vector<string> ans ;
    helper(0,str,ans);
    //sorting since we need in lexicographical order
    sort(ans.begin(),ans.end());
    return ans ;

}