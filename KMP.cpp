#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> prefixArray(string s){
    int n = s.size();
    vector<int> pi(n , 0);
    for(int i = 1 ; i < n ; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
int main() {
    string pattern = "sun";
    vector<int> p = prefixArray(pattern);
    string t = "sunosuhnaoapnedilkibaatsuno";
    int pos = -1;
    int i(0) , j(0);
    while(i < t.size()){
        if(t[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j = p[j-1];
            }else{
                i++;
            }
        }
        if(j == pattern.size()){
            j = 0;
            cout << "Found at " << i - pattern.size();
            //break;
        }
    }
    cout << endl;
    return 0;
}
