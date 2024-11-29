string FirstNonRepeating(string &s) {
        unordered_map<char,int> mp ;
        queue<char> q ;
        int n = s.size() ;
        string ans = "" ;
        for(int i = 0 ; i < n ; i++ ){
            char ch = s[i] ;
            mp[ch]++ ;
            q.push(ch) ;
            while(q.size()){
                if(mp[q.front()] > 1){
                    q.pop() ;
                }
                else{
                    ans += q.front() ;
                    break ;
                }
            }
            if(q.empty()){
                ans += '#' ;
            }
        }
        return ans ;
    }   