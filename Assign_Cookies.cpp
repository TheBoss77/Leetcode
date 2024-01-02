#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {};
    sort(g.begin(), g.begin() + g.size());
    sort(s.begin(), s.begin() + s.size());
    // bool condition = true;
    // while(condition){
    //     condition = false;
    //     for(int i = 0; i < int(g.size()) - 1; i++){
    //         if(g[i] > g[i + 1]){
    //             int temp = g[i];
    //             g[i] = g[i+1];
    //             g[i+1] = temp;
    //             condition = true;
    //         }
    //     }
    // }
    // cout<<s.size()<<" "<<int(s.size()) - 1<<"\n";
    // cout<<(0 < s.size() - 1)<<"\n";
    // condition = true;
    // while(condition){
    //     condition = false;
    //     for(int i = 0; i < int(s.size()) - 1; i++){
    //         if(s[i] > s[i + 1]){
    //             int temp = s[i];
    //             s[i] = s[i+1];
    //             s[i+1] = temp;
    //             condition = true;
    //         }
    //         cout<<"test\n";
    //     }
    // }
    // for(int i = 0; i < g.size(); i++){
    //     cout<<g[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i = 0; i < s.size(); i++){
    //     cout<<s[i]<<" ";
    // }
    cout<<"\n";
    int j = 0, counter = 0;
    for(int i = 0; i < g.size(); i++){
        while(j < s.size()){
            if(g[i] <= s[j]){
                j++;
                counter++;
                break;
            }
            j++;
        }
    }
    cout<<counter<<"\n";
    return 0;
}