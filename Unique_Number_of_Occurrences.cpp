#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;
bool uniqueOccurrences(vector<int> arr) {
    unordered_map<int, int> freq;
    for(int i = 0; i < arr.size(); i++){
        freq[arr[i]]++;
    }
    unordered_map<int, bool> vist;
    for(auto it : freq){
        if(vist[it.second] == true)return false;
        vist[it.second] = true;
    }
    return true;
}
int main()
{
    cout<<uniqueOccurrences({1,2,2,1,1,3})<<"\n";
    return 0;
}