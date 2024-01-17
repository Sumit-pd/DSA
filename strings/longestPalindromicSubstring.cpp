string longestPalinSubstring(string str) {
    int maxi = INT_MIN ;
    string ans = "" ;
    int n = str.length() ;
    for(int i = 0 ; i < n ; i++ ){
// odd string

        int left = i ;
        int right = i ;
        while(left >= 0 && right < n & str[left] == str[right])
        {
            if(right-left+1 > maxi){
                ans = str.substr(left,right-left+1);
                maxi = right-left+1 ;
            }
            left--;
            right++;
        }
//even string
        left = i-1 ;
        right = i ;
        while(left >= 0 && right < n & str[left] == str[right])
        {
            if(right-left+1 > maxi){
                ans = str.substr(left,right-left+1);
                maxi = right-left+1 ;
            }
            left--;
            right++;
        }
    }
    return ans ;
}
