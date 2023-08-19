vector<int> majorityElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {

        if (ans.empty() || ans[0] != arr[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                }
            }
            if (cnt >= floor(n / 3))
            {
                ans.push_back(arr[i]);
            }

            if (ans.size() == 2)
                break;
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}


#include <bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {
	int n = v.size() ;
	unordered_map<int,int> mp ;
	vector<int> ans ;
	int mini = (n/3) + 1 ; // mininmum number of time this should appear
	for(int i = 0 ; i < n ; i++ ){
		mp[v[i]]++ ;
		if(mp[v[i]] == mini ){
			ans.push_back(v[i]) ;
		}
		if(ans.size() == 2 ){
			break ;
		}
	}
	sort(ans.begin() , ans.end() ) ;
	return ans ;

    // time complexity O(nlogn) 
    //space complexity O(n) for the map
	
}