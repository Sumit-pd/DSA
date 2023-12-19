#include <iostream>
#include <vector>
using namespace std;

vector<int> separateNegativeAndPositive(vector<int> &nums){
    vector<int> negative;
    vector<int> positive;
    
    for(int it : nums){
        if(it < 0){
            negative.push_back(it);
        } else {
            positive.push_back(it);
        }
    }

    vector<int> result;
    result.insert(result.end(), negative.begin(), negative.end());
    result.insert(result.end(), positive.begin(), positive.end());

    return result;
}

int main(){
    vector<int> ans = {44, 53, 2, 3, -12, -13, -3};
    vector<int> check = separateNegativeAndPositive(ans);

    // Printing elements of 'ans'
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Printing elements of 'check'
    for (int i = 0; i < check.size(); ++i) {
        cout << check[i];
        if (i != check.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
