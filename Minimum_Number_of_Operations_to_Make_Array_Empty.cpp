#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int process(vector<int> nums){
    // vector<int> indexed;
    // vector<int> smallest;
    // for(int i = 0; i < 1000000; i++){
    //     indexed.push_back(0);
        // smallest.push_back(-1);
    // }
    unordered_map<int, int> indexed;
    for(int i = 0; i < nums.size(); i++){
        indexed[nums[i]]++;
    }
    // smallest[0] = 0;
    // smallest[1] = 100;
    // smallest[2] = 1;
    // for(int i = 3; i < 1000000; i++){
    //     smallest[i] = min(smallest[i-2], smallest[i-3]) + 1;
    // }
    // // for(int i = 0; i < 10; i++)cout<<smallest[i]<<" ";
    // // cout<<"\n";
    int ans = 0;
    for(int i= 0; i < indexed.size(); i++){
        if(indexed[i] == 1)return -1;
    //     ans += smallest[indexed[i]];
        ans += indexed[i]/3;
        if(indexed[i]%3 != 0)ans ++;
    }
    return ans;
}
int main()
{
    vector<int> test = {7,15,15,7};
    cout<<process(test)<<"\n";
    return 0;
}