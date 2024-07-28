class Solution {
    int partition(vector<int> &nums , int low , int high){
        int randNum = rand()%(high-low + 1) + low;
	    swap(nums[low],nums[randNum]) ;
        int pivot = nums[low] ;
        int i = low+1 ;
        int j = high ;
        while(i<=j){
            while(i <= high && nums[i] <= pivot  ){
                i++ ;
            }
            while(j >= low && nums[j] > pivot ){
                j-- ;
            }
            if(i<j){
                swap(nums[i],nums[j]) ;
            }
        }

        swap(nums[low],nums[j]) ;
        return j ;
    }
    void helper(vector<int> &nums , int low , int high){
        if(low < high) {
            int part = partition(nums,low,high) ;
            helper(nums,low,part-1) ;
            helper(nums,part+1,high) ;
        }
        
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        helper(nums,0,nums.size()-1) ;
        return nums;
    }
};

