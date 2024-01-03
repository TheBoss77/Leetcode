#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> answer(vector<int> nums){
    int arr[250];
    for(int i = 0; i < 250; i++)arr[i] = 0;
    for(int i = 0; i < nums.size(); i++){
        arr[nums[i]]++;
    }
    vector<vector<int>> ans;
    while(true){
        vector<int> curr;
        for(int i = 0; i < 250; i++){
            if(arr[i] > 0){
                arr[i]--;
                curr.push_back(i);
            }
        }
        if(curr.empty()){
            return ans;
        }
        ans.push_back(curr);
    }
}
int main()
{
    vector<int> test = {1,3,4,1,2,3,1};
    vector<vector<int>> ans = answer(test);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}