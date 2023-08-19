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

vector<int> majorityElement(vector<int> v) {
    int element1 = INT_MIN;
    int element2 = INT_MIN;
    int cnt1 = 0;
    int cnt2 = 0;
    vector<int> ans;
    int n = v.size();

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && element2 != v[i]) {
            cnt1 = 1;
            element1 = v[i];
        } else if (cnt2 == 0 && element1 != v[i]) {
            cnt2 = 1;
            element2 = v[i];
        } else if (element1 == v[i]) {
            cnt1++;
        } else if (element2 == v[i]) {
            cnt2++;
        } else {
            cnt1--;  // Corrected: cnt1--
            cnt2--;  // Corrected: cnt2--
        }
    }  

    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == element1) {
            cnt1++;
        } else if (v[i] == element2) {
            cnt2++;
        }
    }

    int mini = (int)n / 3 + 1;
    if (cnt1 >= mini) {
        ans.push_back(element1);
    }
    if (cnt2 >= mini) {
        ans.push_back(element2);
    }

    sort(ans.begin(), ans.end()); 
    return ans;

    //time complexity : O(N)
    //space complexity : O(1)
}