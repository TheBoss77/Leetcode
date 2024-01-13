#include<iostream>
using namespace std;
int minSteps(string s, string t) {
    int letterone[26] = {};
    int lettertwo[26] = {}; 
    for(int i = 0; i < s.size(); i++){
        letterone[s[i] - 'a']++;
        lettertwo[t[i] - 'a']++;
    }
    int ans = 0;    
    for(int i = 0; i < 26; i++){
        if(letterone[i] > lettertwo[i]){
            ans += letterone[i] - lettertwo[i];
        }
        // cout<<letterone[i]<<" "<<lettertwo[i]<<"\n";
    }
    return ans;
}
int main()
{
    cout<<minSteps("bab", "aba")<<"\n";
    return 0;
}