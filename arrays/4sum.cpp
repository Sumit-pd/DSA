#include <bits/stdc++.h>
// brute force
// time complexity : O(n4)
// space complexity : O(no of triplets)
vector<vector<int>> fourSum1(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// better
// time complexity : O(N3 * logM)
// space complexity : O(N)+ O(quads) * 2
vector<vector<int>> fourSum2(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long forth = target - nums[i] - nums[j] - nums[k];
                if (hashset.find(forth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)forth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// optimal
//time complexity : O(N3) + O(NlogN)
//space complexity : O(number of quads)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        // this is to avoid duplicates or use of same elements
        for (int j = i + 1; j < n; j++)
        {
            if (j != i+1 && nums[j] == nums[j - 1])
                continue;
            // this is to avoid duplicates or use of same elements
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                    // this is to avoid duplicates or use of same elements
                }
            }
        }
        
    }
    return ans;
}