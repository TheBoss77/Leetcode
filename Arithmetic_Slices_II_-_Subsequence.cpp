#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// int dp(vector<int>& nums, int idx, int difference){
//     int ans = 0;
//     for(int i = idx + 1; i < nums.size(); i++){
//         long long diff = static_cast<long long>(nums[idx]) - nums[i];
//         if (diff > INT_MAX || diff < INT_MIN) continue;
//         if(nums[idx] - nums[i] == difference){
//             ans ++;
//             ans += dp(nums, i, difference);
//         }
//     }
//     return ans;
// }
int process(vector<int>& nums){
    // int ans = 0;
    // if(nums.size() < 3)return 0;
    // for(int i = 0; i < nums.size() - 2; i++){
    //     for(int j = i + 1; j < nums.size() - 1; j++){
    //         long long diff = static_cast<long long>(nums[i]) - nums[j];
    //         if (diff > INT_MAX || diff < INT_MIN) continue;
    //         ans += dp(nums, j, nums[i] - nums[j]);
    //     }
    // }
    // return ans;
    int n = nums.size();
    int total_count = 0;

    vector<unordered_map<int, int>> dp(n);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long diff = static_cast<long long>(nums[i]) - nums[j]; 

            if (diff > INT_MAX || diff < INT_MIN)
                continue; 

            int diff_int = static_cast<int>(diff);

            dp[i][diff_int] += 1; 

            if (dp[j].count(diff_int)) {
                dp[i][diff_int] += dp[j][diff_int];
                total_count += dp[j][diff_int];
            }
        }
    }

    return total_count;
}
int main()
{
    vector<int> test = {2,4,6,8,10};
    cout<<process(test)<<"\n";
    return 0;
}