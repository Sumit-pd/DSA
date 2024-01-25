int minSwaps(vector<int> &arr)
{
	vector< pair<int,int> > temp ;
	int n = arr.size() ;
	//storing all the elements with the index in the temp arr
	for(int i = 0 ; i < n; i++ ){
		temp.push_back({arr[i],i}) ;
	}
	int cnt = 0 ;
	//sorting the array temp 
	sort(temp.begin(),temp.end());
	for(int i = 0 ; i < n ; i++ ){
		if(temp[i].second != i ){
			//coming into this condition indicates that the 
			//element is not in its correct position
			cnt++;
			swap(temp[i],temp[temp[i].second]) ;
			//swaping it with the index 
			i--;
			// rechecking
		}
	}
	return cnt ;

}