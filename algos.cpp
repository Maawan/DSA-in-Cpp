#include<iostream>
using namespace std;
void bubbleSort(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i+1  ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        int curIndex = i;
        int minIndex = i;
        for(int j = i+1 ; j < n ; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        int temp = arr[curIndex];
        arr[curIndex] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void insertionSort(int arr[] , int n){
    for(int i = 1  ; i < n ; i++){
        int curEle = arr[i];
        int j = i-1;
        while(j >= 0 && curEle < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curEle;
    }
}
// Merge Sort Consist of Two Functions 1 -> To Divide the Array named mergesort and second to merge name merge
void merge(int arr[] , int start , int mid , int end){
    int temp[end - start + 1];
    int ptr1 = start;
    int ptr2 = mid+1;
    int k = 0;
    while(ptr1 <= mid && ptr2 <= end){
        if(arr[ptr1] < arr[ptr2]){
            temp[k++] = arr[ptr1++];
        }else {
            temp[k++] = arr[ptr2++];
        }
    }
    while(ptr1 <= mid){
        temp[k++] = arr[ptr1++];
    }
    while (ptr2 <= end){
        temp[k++] = arr[ptr2++];
    }
    k = 0;
    for(int i = start ; i <= end ; i++){
        arr[i] = temp[k++];
    }
}
void mergeSort(int arr[] , int start , int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergeSort(arr , start , mid);
        mergeSort(arr , mid + 1 , end);
        merge(arr , start , mid , end);
    }
}
void swap(int arr[] , int s , int e){
    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;
}
int partition(int arr[] , int start ,  int end){
    int pivotEle = arr[start];
    int count = 0;
    for(int i = start ; i <= end ; i++){
        if(arr[i] < pivotEle) count++;
    }
    int index = start + count;
    swap(arr , index , start);
    int i = start;
    int j = end;
    while(i < index && j > index){
        while(arr[i] < pivotEle){
            i++;
        }
        while(arr[j] > pivotEle){
            j--;
        }
        if(arr[i] > pivotEle && arr[j] < pivotEle){
            swap(arr , i , j);
        }
    }
    return index;
}
void quickSort(int arr[] , int start ,  int end){
    if(start < end){
        int index = partition(arr ,start , end);
        quickSort(arr , start , index - 1);
        quickSort(arr , index + 1 , end);
    }
}
int main(){
    int arr[] = { 1,5,4,3,7,8,5,4,2};
    int n = 9;
    //bubbleSort(arr , n);
   // selectionSort(arr , n);
    //insertionSort(arr , n);
    //mergeSort(arr , 0 , 8);
    quickSort(arr , 0 , 9);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
}
