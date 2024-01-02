// brute

int majorityElement(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt >= n / 2)
            return arr[i];
    }
}

// better
int majorityElement(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second >= n / 2)
            return it.first;
    }
    return -1;
}


int findMajorityElement(int arr[], int n) {
	int element = arr[0] ;
    int count = 1 ;
    for(int i = 1 ; i < n ;i++ ){
        if(count == 0){
            element = arr[i];
            count = 1 ;
        }
        else if(element == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    count = 0 ;
    for(int i = 0 ; i < n ;i++ ){
        if(element == arr[i]){
            count++;
        }
    }
    if(count > n/2){ // more than n/2 not equal to 
        return element;
    }
    else{
        return -1;
    }
}