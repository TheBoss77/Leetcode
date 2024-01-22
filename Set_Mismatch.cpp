#include<iostream>
#include<vector>
using namespace std;
vector<int> findErrorNums(vector<int> nums) {
    int freq[nums.size() + 1] = {};
    for(int i = 0; i < nums.size(); i++){
        freq[nums[i]]++;
    }
    int replace = 0, repeat = 0;
    for(int i = 1; i <= nums.size(); i++){
        // cout<<i<<" "<<freq[i]<<"\n";
        if(freq[i] == 0)replace = i;
        if(freq[i] == 2)repeat = i;
    }
    return {repeat, replace};
}
int main()
{
    vector<int> test = findErrorNums({1,2,2,4});
    return 0;
}