#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int count = 0;
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
void makeHeap(vector<int>& v , int index){
    if(index == 0) return;
    int size = v.size();
    while(index < size){
        int left = index * 2;
        int right = (index * 2) + 1;
        if(left < size){
            int grIndex = left;
            if(right < size){
                if(v[grIndex] < v[right]){
                    grIndex = right;
                }
            }
            if(v[index] < v[grIndex]){
                swap(v , index ,  grIndex);
                index = grIndex;
            }else break;
        }else break;
    }
}
void Heapify(vector<int>& v){
    for(int i = v.size() / 2 ; i > 0 ; i--){
        makeHeap(v , i);
    }
}
bool getResultFromRecurSiveFuntion(vector<int>& v , int i , int ele){
    count++;
    if(i >= v.size()) return false;
    if(v[i] == ele) return true;
    if(v[i] < ele)  return false;
    int leftChild = i * 2;
    int rightChild = (i * 2) + 1;
    return getResultFromRecurSiveFuntion(v ,leftChild, ele) || getResultFromRecurSiveFuntion(v , rightChild , ele);


}
bool Search(vector<int>& v , int ele){
    if(v.size() == 1 || v.size() == 0) return false;
    return getResultFromRecurSiveFuntion(v , 1 , ele);
}
int main(){
    // int ele[8] = {1 , 2 , 9 , 8 , 12 , 15 , 7 , 3};
    // vector<int> maxHeap;
    // for(int i = 0 ; i < 8 ; i++){
    //     insertElement(maxHeap , ele[i]);
    // }
    // for(int i = 0 ; i < 8 ; i++){
    //     cout << pop(maxHeap) << " ";
    // }
    vector<int> newVector = {INT8_MIN , 1 , 2 , 3 , 9 , 8 , 7 , 6 , 7 , 4 , 3 ,9};
    Heapify(newVector);
    int size = newVector.size() - 1;
    for(int i = 0 ; i < size ; i++){
        cout << newVector[i] << " " ;
    }
    cout << endl;
    int val;
    cout << "Enter Value which you want to Search " << endl;
    cin >> val;
    if(Search(newVector , val)){
        cout << "Element Found " << endl;
    }else{
        cout << "Element not found " << endl;
    }
    cout << "Values Checked " << count << endl;
    return 0;
}