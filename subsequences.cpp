#include<iostream>
#include<vector>
using namespace std;
void generate(vector<int> ans , vector<int> nums , int ptr , vector<vector<int>>& finalOutput){
    if(ptr >= nums.size()){
        finalOutput.push_back(ans);
        return;
    }
    generate(ans , nums , ptr + 1 , finalOutput);
    ans.push_back(nums[ptr]);
    generate(ans , nums , ptr + 1 , finalOutput);
}
int main(){
    vector<int> arr = {1,2};
    vector<vector<int>> finalOutput;
    vector<int> temp;
    generate(temp , arr , 0 , finalOutput);
    for(int i = 0 ; i < finalOutput.size() ; i++){
        for(int j = 0 ; j < finalOutput[i].size() ; j++){
            cout << finalOutput[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    
}