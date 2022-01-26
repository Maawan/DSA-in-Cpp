#include<iostream>
#include<vector>
#include<limits>
using namespace std;
void swap(vector<int>& v  , int i , int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void insertElement(vector<int>& v , int ele){
    if(v.size() == 0){
        v.push_back(INT8_MIN);
    }
    v.push_back(ele);
    int index = v.size() - 1;
    while(index > 1){
        if(v[index] > v[index / 2]){
            swap(v , index , index / 2);
            index = index / 2;
        }else break;
    }
}
int pop(vector<int>& v){
    if(v.size() == 0 || v.size() == 1){
        return -1;
    }
    int returingElement = v[1];
    v[1] = v[v.size() - 1];
    v.pop_back();
    int index = 1;
    while(index < v.size()){
        if(index * 2 < v.size()){
            int grIndex = index * 2;
            if((index * 2) + 1 < v.size()){
                if(v[grIndex] < v[(index * 2) + 1]){
                    grIndex = (index * 2) + 1;
                }
            }
            if(v[index] < v[grIndex]){
                swap(v , index , grIndex);
                index = grIndex;
            }else break;
        }else break;
    }
    return returingElement;
}
int main(){
    int ele[8] = {1 , 2 , 9 , 8 , 12 , 15 , 7 , 3};
    vector<int> maxHeap;
    for(int i = 0 ; i < 8 ; i++){
        insertElement(maxHeap , ele[i]);
    }
    for(int i = 0 ; i < 8 ; i++){
        cout << pop(maxHeap) << " ";
    }
    return 0;
}