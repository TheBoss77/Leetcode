#include<iostream>
#include<vector>
using namespace std;
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = matrix[0][i];
    }
    for(int i = 1; i < n; i++){
        int next[n];
        for(int j = 0; j < n; j++){
            if(j == 0){
                next[j] = matrix[i][j] + min(dp[j], dp[j+1]);
            }
            else if(j == n - 1){
                next[j] = matrix[i][j] + min(dp[j], dp[j - 1]);
            }
            else{
                next[j] = matrix[i][j] + min(dp[j], min(dp[j-1], dp[j+1]));
            }
        }
        for(int j = 0; j < n; j++){
            dp[j] = next[j];
        }
    } 
    int ans = dp[0];
    for(int i = 0; i < n; i++){
        if(ans > dp[i])ans = dp[i];
    }       
    return ans;
}
int main()
{

    return 0;
}