/*problem 1 find the element at a particular row and column */
#include <iosteam>
using namespace std ;

int element(int i , int j)
{
    return ncr(i,j);
}


/*problem 2 print and nth row of pascal triangle*/
int row(int n)
{
    // the n should be given in zero based indexing
    int ans = 1 ;
    for (int i = 1 ; i < n; i++)
    {
        ans = ans * (n-i) ;
        ans = ans / i ;
    }
    return ans ;
}

/*print the entire pascal triangle*/

using namespace std ;
vector<int> findRow(int n){
    int ans = 1 ;
    vector<int> output ;
    output.push_back(ans) ;

    for(int i = 1 ; i < n ; i++ ){
        ans = ans * (n - i ) ;
        ans = ans / i ;
        output.push_back(ans) ;
    }
    // output.push_back(1) ;
    return output ;
}
vector<vector<int>> pascalTriangle(int N) {
    vector< vector<int> > ans ;
    for(int i = 1 ; i <= N ; i++ ){
        vector<int> smallAns = findRow(i) ;
        ans.push_back(smallAns) ;
    }
    return ans ;
}
