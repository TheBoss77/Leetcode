#include<iostream>
#include<vector>
using namespace std;
int process(vector<int> nums){
    vector<int> prev;
    int ans = 1;
    prev.push_back(1);
    for(int i = 1; i < nums.size(); i++){
        int curr = 1;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                curr = max(prev[j] + 1, curr);
            }
        }
        prev.push_back(curr);
        ans = max(ans, curr);
    }
    return ans;
}
int main()
{
    vector<int> test = {7,7,7,7,7,7,7};
    cout<<process(test)<<"\n";
    return 0;
}