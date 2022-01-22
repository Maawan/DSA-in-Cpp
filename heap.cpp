#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int>& v , int i , int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void insert(vector<int>& list , int& n , int key){
    if(list.size() == 0){
        list.push_back(123321);
    }
    list.push_back(key);
    int index = list.size() - 1;
    n++;
    
    while(index > 1){
        if(list[index] > list[index / 2]){
            swap(list , index , index / 2);
            index = index / 2;
        }else{break;}
    }
}
int pop(vector<int>& list){
    if(list.size() == 0 || list.size() == 1) return -1;
    int rootElement = list[1];
    swap(list , 1 , list.size() - 1); 
    list.pop_back();
    int index = 1;
    while(index < list.size() - 1){
        if(index * 2 < list.size() && (index * 2) + 1 < list.size()){
            int grIndex = index * 2;
            if(list[index * 2] < list[(index * 2)+ 1]){
                grIndex = (index * 2) + 1;
            }
            if(list[index] < list[grIndex]){
                swap(list , index , grIndex);
                index = grIndex;
            }else{
                break;
            }
        }else if(index * 2 < list.size()){
            if(list[index] < list[index * 2]){
                swap(list, index , 2 * index);
                index = 2 * index;
            }else break;
        }else{
            return rootElement;
        }
    }
}
int main(){
    int arr[] = {84 , 32 , 12 ,83 ,65};
    vector<int> list;
    int heapSize = 0;
    for(int i = 0 ; i < 5 ; i++){
        insert(list , heapSize , arr[i]);
    }
    for(int i = 0 ; i < list.size() ; i++){
        cout << list[i] << " ";
    }
    cout << endl;
    int i = 3;
    while(i != -1){
        i = pop(list);
        cout << i << " ";
    }
    return 0;
}