#include<iostream>
#include<vector>
using namespace std;
void update(vector<int>& arr , int i , int value , int n){
    for( ; i <= n ; i + (i & -i)){
        arr[i] += value;
    }
}
int getSum(vector<int>& arr , int i){
    int ans = 0;
    for( ; i > 0 ; i - (i & (-i))){
        ans += arr[i];
    }
    return ans;
}
int main(){
    
}
