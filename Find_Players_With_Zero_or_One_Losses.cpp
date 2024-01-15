#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int> loss;
    for(int i = 0; i < matches.size(); i++){
        if(loss[matches[i][0]] == 0){
            loss[matches[i][0]] = 0;
        }
        if(loss[matches[i][1]] == 0){
            loss[matches[i][1]] = 0;
        }
        loss[matches[i][1]]++;
    }
    vector<int> zero, one;
    for(auto it : loss){
        if(it.second == 0)zero.push_back(it.first);
        if(it.second == 1)one.push_back(it.first);
    }
    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());
    return {zero, one};
}
int main()
{

    return 0;
}