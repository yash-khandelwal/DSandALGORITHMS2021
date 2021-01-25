// is Unique
// implement an algorithm to determine if a string has all the unique characters.
// What if you cannot use additional datastructure


#include<bits/stdc++.h>
using namespace std;

bool isUnique(string s){
    int n = s.size();
    if (n > 26){
        return false;
    } else {
        int count[26] = {0};
        for (char c : s) {
            count[c - 97]++;
            if (count[c - 97] > 1) {
                return false;
            }
        }
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    cout<<(isUnique(s) ? "YES" : "NO")<<"\n";
    return 0;
}
