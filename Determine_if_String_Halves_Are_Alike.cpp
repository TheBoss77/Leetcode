#include<iostream>
using namespace std;
bool halvesAreAlike(string s) {
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int countone = 0, counttwo = 0;
    for(int i = 0; i < s.size()/2; i++){
        for(int j = 0; j < 10; j++){
            if(vowels[j] == s[i]){
                countone++;
            }
        }
    }
    for(int i = s.size()/2; i < s.size(); i++){
        for(int j = 0; j < 10; j++){
            if(vowels[j] == s[i]){
                counttwo++;
            }
        }
    }
    // cout<<countone<<" "<<counttwo<<"\n";
    if(countone == counttwo)return true;
    return false;
}
int main()
{
    cout<<halvesAreAlike("textbook")<<"\n";
    return 0;
}