#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;
int find(int i, vector<vector<int>>&job, vector<int>&startTime, int n,vector<int>&dp){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    
    int index = lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
    int pick = job[i][2] + find(index,job,startTime,n,dp);
    int notpick = find(i+1,job,startTime,n,dp);
    return dp[i] = max(pick,notpick);

}
int jobScheduling(vector<int> startTime, vector<int> endTime, vector<int> profit){
    // set<int> ordered_times;
    // unordered_map<int, int> conversion;
    // for(int i = 0; i < startTime.size(); i++)ordered_times.insert(startTime[i]);
    // for(int i = 0; i < endTime.size(); i++)ordered_times.insert(endTime[i]);
    // int counter = 0;
    // for(auto i : ordered_times){
    //     conversion[i] = counter;
    //     // cout<<i<<" "<<counter<<"\n";
    //     counter++;
    // }
    // // vector<int> bystarttime[200000];
    // // for(int i = 0; i < startTime.size(); i++){
    // //     bystarttime[conversion[startTime[i]]].push_back({conversion[endTime[i]], profit[i]});
    // // }
    // // for(int i = 0; i < counter; i++){
    // //     cout<<i<<": ";
    // //     for(int j = 0; j < bystarttime[i].size(); j++){
    // //         cout<<"{"<<bystarttime[i][j].first<<" , "<<bystarttime[i][j].second<<"}, ";
    // //     }
    // //     cout<<"\n";
    // // }
    // vector<vector<int>> jobs;
    // for(int i = 0; i < startTime.size(); i++){
    //     jobs.push_back({conversion[startTime[i]], conversion[endTime[i]], profit[i]});
    // }
    // // for(auto it : jobs){
    // //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
    // // }
    // sort(jobs.begin(), jobs.end());
    // for(int i = 0; i < jobs.size(); i++){
    //     for(int j = 0; j < jobs[i].size(); j++){
    //         cout<<jobs[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // // cout<<jobs.size()<<"\n";
    // int jobscounter = 0;
    // int dp[200000] = {};
    // for(int i = 0; i < counter; i++){
    //     if(i != 0){
    //         dp[i] = max(dp[i], dp[i-1]);
    //     }
    //     if(jobscounter == jobs.size()){
    //         return dp[i];
    //     }
    //     while(jobs[jobscounter][0] <= i && jobscounter != jobs.size()){
    //         // dp[jobs[jobscounter][1]] = max(dp[jobs[jobscounter][1]], dp[i] + jobs[jobscounter][2]);
    //         jobscounter++;
    //         cout<<jobscounter<<"\n";
    //     }
    //     // for(int j = 0; j < bystarttime[i].size(); i++){
    //     //     dp[bystarttime[i][j].first] = max(dp[endTime[bystarttime[i][j].first]], dp[i] + bystarttime[i][j].second);
    //     // }
    //     // for(int j = 0; j < startTime.size(); j++){
    //     //     if(conversion[startTime[j]] == i){
    //     //         dp[conversion[endTime[j]]] = max(dp[conversion[endTime[j]]], dp[i] + profit[j]);
    //     //     }
    //     // }
    // }
    // for(int i = 0; i < counter; i++)cout<<dp[i]<<" ";
    // cout<<"\n";
    // return dp[counter-1];
    int n = startTime.size();
    vector<vector<int>>job;
    vector<int>dp(n,-1);
    for(int i =0;i<n;i++){
        job.push_back({startTime[i],endTime[i],profit[i]});
    }
    sort(job.begin(),job.end());
    sort(startTime.begin(),startTime.end());
    return find(0,job,startTime,n,dp);
}
int main()
{
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    cout<<jobScheduling(startTime, endTime, profit)<<"\n";
    return 0;
}