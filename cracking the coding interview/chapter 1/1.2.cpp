/// check Permutation
/// given two strings write a method to decide if one is a permutation of other.

#include<bits/stdc++.h>
using namespace std;

bool isPermutation(string s, string t){
    int mapper[26] = {0}, currMapper[26] = {0};
    if(s.size() > t.size()){
        swap(s, t);
    }
    for(int i = 0; i < s.size(); i++){
        mapper[s[i] - 97]++;
        currMapper[t[i] - 97]++;
    }
    for(int i = s.size(); i < t.size(); i++){
        bool same = true;
        for(int j = 0; j < 26; j++){
            if(mapper[j] != currMapper[j]){
                same = false;
                break;
            }
            cout<<i<<": "<<currMapper[i]<<" ";
        }
        if(same) return true;
        currMapper[t[i - s.size() + 1]]--;
        currMapper[t[i]]++;
        if(i == t.size() - 1){
            bool same = true;
            for(int j = 0; j < 26; j++){
                if(mapper[j] != currMapper[j]){
                    same = false;
                    break;
                }
                cout<<i+1<<": "<<currMapper[i]<<" ";
            }
            if(same) return true;
        }
        cout<<"\n";
    }
    return false;
}

int main(){
    string s, t;
    cin>>s>>t;
    cout<<isPermutation(s, t)<<"\n";
    return 0;
}
