void helper(vector<int> arr , vector<int> output , int ind , vector<vector<int>> &ans){
    if(ind >= arr.size()){
        ans.push_back(output);
        return ;
    }
    output.push_back(arr[ind]);
    helper(arr,output,ind+1,ans);
    output.pop_back();
    helper(arr,output,ind+1,ans);
}
vector<vector<int>> FindAllSubsets(vector<int> &arr){
    vector<vector<int>> ans ;
    helper(arr,{},0,ans);
    return ans ;
}