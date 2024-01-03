#include<iostream>
#include<vector>
using namespace std;
int process(vector<string> bank){
    int ans = 0;
    int prev = 0;
    for(int i = 0; i < bank.size(); i++){
        int curr = 0;
        for(int j = 0; j < bank[i].length(); j++){
            if(bank[i][j] == '1'){
                curr++;
            }
        }
        ans += prev * curr;
        if(curr != 0){
            prev = curr;
        }
    }
    return ans;
}
int main()
{
    vector<string> test = {"000","111","000"};
    cout<<process(test)<<"\n";
    return 0;
}