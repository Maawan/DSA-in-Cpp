#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(12);
    v.push_back(23);
    v.push_back(34);
    v.front();
    cout << v.pop() << endl;
    return 0;
}