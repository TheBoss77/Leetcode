#include<iostream>
#include<algorithm>
using namespace std;
bool closeStrings(string word1, string word2) {
    int idxone[26] = {};
    int idxtwo[26] = {};
    if(word1.size() != word2.size())return false;
    for(int i = 0; i < word1.size(); i++){
        idxone[word1[i] - 'a']++;
        idxtwo[word2[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(idxone[i] == 0 && idxtwo[i] != 0 || idxone[i] != 0 && idxtwo[i] == 0){
            return false;
        }
    }
    sort(idxone, idxone + 26);
    sort(idxtwo, idxtwo + 26);
    for(int i = 0; i < 26; i++){
        if(idxone[i] != idxtwo[i])return false;
    }
    return true;
}
int main()
{
    cout<<closeStrings("cabbba", "abbccc")<<"\n";
    return 0;
}