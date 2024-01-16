//memoization
class Solution
{
public:
    int helper(int ind , unordered_set<string> st, int n , string target ,vector<int> &dp ){
        if(ind == n){
            return 1 ;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        string temp = "";
        for(int i = ind ; i < n ; i++ ){
            temp += target[i];
            if(st.find(temp) != st.end()){
                if(helper(i+1, st,n,target,dp)){
                    return dp[ind]=1;
                }
            }
        }
        return dp[ind]=0;
        
    }
    int wordBreak(string A, vector<string> &B) {
        int x = 1100 ;
        vector<int> dp(A.size(),-1);
        unordered_set<string> st ;
        for(auto it:B){
            st.insert(it);
        }
        int n = A.size();
        return helper(0,st,n,A,dp);
    }
};