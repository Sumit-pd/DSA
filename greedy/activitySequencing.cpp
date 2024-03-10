class meetX{
    public:
    int id ; 
    int start ;
    int end ;
};

bool cmp(meetX a , meetX b){
    if(a.end != b.end){
        return a.end < b.end ;
    }
    return a.id < b.id ;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size() ;
    meetX meetings[n];
    for(int i = 0 ; i < n; i++ ){
        meetings[i].id = i+1 ;
        meetings[i].start = start[i] ;
        meetings[i].end = end[i] ;
    }

    sort(meetings , meetings + n ,cmp ) ;

    int cnt = 1 ;
    int curTime = meetings[0].end ;
    for(int i = 1 ; i < n ; i++ ){
        if(meetings[i].start > curTime ){
            cnt++;
            curTime = meetings[i].end ;
        }
    }
    return cnt ;
}


//time complexity : O(NlogN) as we are sorting the array 
//space complexity : O(n)