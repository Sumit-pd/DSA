vector<char> minimize(vector<char> arr){
    int cnt = 0 ;
    vector<char> ch ;
    for(int i = 0 ; i < arr.size() ; i++){
        cnt++ ;
        if(i == arr.size() || arr[i] != arr[i+1]){
            if(cnt == 1){
                ch.push_back(arr[i]) ;
            }
            else{
                ch.push_back(to_string(cnt)) ;
            }
            cnt = 0 ;
        }
    }
    return ch ;
}
void helper(int ind ,vector<char> &arr , int n , vector<vector<char>> &ans){
    if(ind == n){

        ans.push_back(minimize(arr)) ;
        return ;
    }
    char temp = arr[ind] ;
    arr[ind] = '1' ;
    helper(ind+1,arr,n,ans) ;
    arr[ind] = temp ;
    helper(ind+1,arr,n,ans) ;
}
