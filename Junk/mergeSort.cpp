#include<iostream>
#include<vector>
using namespace std;
vector<int> Merge(vector<int>& a , int s , int mid , int e){
    int temp[(e - s) + 1];
    int ptr = 0 , ptr2 = mid+1; int i = 0;
    while(ptr <= mid && ptr2 <= e){
        if(a[ptr] < a[ptr2]){
            temp[i] = a[ptr];ptr++;
        }else{
            temp[i] = a[ptr2];ptr2++;
        }
        i++;
    }
    while(ptr <= mid){
        temp[i++] = a[ptr];ptr++;
    }
    while(ptr2 <= e){
        temp[i++] = a[ptr2];ptr2++;
    }
    i = 0;
    for(int j = s ; j <= e ; j++){
        //cout << "Coping ELement in FInal Array " << temp[i] << endl;
        a[j] = temp[i++]; 
    }
    return a;

}
void MergeSort(vector<int>& arr , int s , int e){
    if(s < e){
        int mid = (s + e) / 2;
        MergeSort(arr , s , mid);
        MergeSort(arr , mid + 1 , e);
        arr = Merge(arr , s , mid , e);
    }
}
int main(){
    vector<int> arr = {2,3,4,1,6,7,5,4};
    MergeSort(arr , 0 , 7);
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
    return 0;
    
}