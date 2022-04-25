/*
    Code Contributed by Mohd Mawan Ahmad 
*/
#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &heap , int i , int j){
    int temp = heap[i];        // Swap Function 
    heap[i] = heap[j];
    heap[j] = temp;
}
int popValueFromHeap(vector<int> &heap, int &n){
    // If Size of heap is 1 or 0 , then it means Heap is empty .As if size is one 
    // also then it will be the temp element not any element
    if(n == 0 || n == 1) return -1;
    // For Deletion we replace last Index value with element at 1 index and delete the last ele from Heap
    // then we perculate down from index 1 to gets its suitable position in heap
    int delEle = heap[1];
    swap(heap , 1 , n - 1);n--;
    int size = n;
    int curIndex = 1;
    while(curIndex < size){
        int leftChild = 2 * curIndex;
        int rightChild = (2 * curIndex) + 1;
        int grIndex = curIndex;
        if(leftChild < size){
            if(heap[leftChild] > heap[grIndex]){
                grIndex = leftChild;
            }
        }
        if(rightChild < size){
            if(heap[rightChild] > heap[grIndex]){
                grIndex = rightChild;
            }
        }
        swap(heap , grIndex , curIndex);
        if(grIndex == curIndex) break;
        curIndex = grIndex; 
    }
    return delEle;
}
int popValueFromHeap(vector<int> &heap ){
    // If Size of heap is 1 or 0 , then it means Heap is empty .As if size is one 
    // also then it will be the temp element not any element

    if(heap.size() == 0 || heap.size() == 1) return -1;
    // For Deletion we replace last Index value with element at 1 index and delete the last ele from Heap
    // then we perculate down from index 1 to gets its suitable position in heap
    int delEle = heap[1];
    swap(heap , 1 , heap.size() - 1);
    heap.pop_back(); // Deleting Last Element;
    int size = heap.size();
    int curIndex = 1;
    while(curIndex < size){
        int leftChild = 2 * curIndex;
        int rightChild = (2 * curIndex) + 1;
        int grIndex = curIndex;
        if(leftChild < size){
            if(heap[leftChild] > heap[grIndex]){
                grIndex = leftChild;
            }
        }
        if(rightChild < size){
            if(heap[rightChild] > heap[grIndex]){
                grIndex = rightChild;
            }
        }
        swap(heap , grIndex , curIndex);
        if(grIndex == curIndex) break;
        curIndex = grIndex; 
    }
    return delEle;
}
void insertValueInHeap(vector<int> &heap , int value){
    // Heap is Starting from Index 1 . 0th Index is just holding a temp Value
    // This Approach is Called Perculate Up 
    if(heap.size() == 0){
        // If We are Inserting first Element, then we need to insert first the temp Value, then
        // the actual value . So, that actual value sits on Index 1 and temp value is on Index 0
        heap.push_back(-1);
        heap.push_back(value);
    }else{
        heap.push_back(value);
        int curIndex = heap.size() - 1;
        while(curIndex > 1){
            if(heap[curIndex] > heap[curIndex / 2]){ // Check whether curNode has greater value from its Parent or not
                swap(heap , curIndex , curIndex / 2);// If it has then we interchnage it with its parent 
                curIndex = curIndex / 2; // Parent of 1 Indexed Heap is (index / 2) 
            }else break;
        }

    }
}
void heapify(vector<int> &arr , int index){
    if(arr.size() == 0 || arr.size() == 1) return ;
    int size = arr.size();
    int curIndex = index;
    while(curIndex < size){
        int leftChild = 2 * curIndex;
        int rightChild = (2 * curIndex) + 1;
        int grIndex = curIndex;
        if(leftChild < size){
            if(arr[leftChild] > arr[grIndex]){
                grIndex = leftChild;
            }
        }
        if(rightChild < size){
            if(arr[rightChild] > arr[grIndex]){
                grIndex = rightChild;
            }
        }
        swap(arr , grIndex , curIndex);
        if(grIndex == curIndex) break;
        curIndex = grIndex; 
    }
}
void makeArrayHeap(vector<int> &arr){
    // To Make Array a Heap, we start to check from Last Node and try to make heap from Bottom
    for(int i = arr.size() - 1 ; i > 0 ; i--){
        heapify(arr , i);
    }
    int sizeOfHeap = arr.size();
    while(sizeOfHeap > 1){
        int ele = popValueFromHeap(arr , sizeOfHeap);
        if(ele == -1) break;
        arr[sizeOfHeap] = ele;
    }
    cout << "Size is " << arr.size() << endl;
    for(int i = 1 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    // This Implementation is of Max-Heap
    int choice;
    vector<int> heapSortArray;
    vector<int> heap;
    while(true){
        cout << "1 -> Create Heap by Inserting Elements One by One" << endl;
        cout << "2 -> Display Heap Array " << endl;
        cout << "3 -> Pop Element from Heap" << endl;
        cout << "4 -> Sort by using HeapSort" << endl;
        cin >> choice;
        if(choice == 1){
            cout << "Enter No of Elements" << endl;
            int n;
            cin >> n;
            for(int i = 0 ; i < n ; i++){
                int value ;
                cout << "Enter Value "<< endl;
                cin >> value;
                insertValueInHeap(heap , value);
            }
        }else if(choice == 2){
            for(int i = 1 ; i < heap.size() ; i++){
                cout << heap[i] << " ";
            }
        }else if(choice == 3){
            cout << "Element deleted from Heap " << popValueFromHeap(heap) << endl;
        }else if(choice == 4){
            int n;
            cout << "Enter Number of Elements you want to Enter " << endl;
            cin >> n;
            heapSortArray.push_back(-1); // Temp value Inserted at Index 0
            for(int i = 0 ; i < n ; i++){
                int ele;
                cout << "Enter Element " << endl;
                cin >> ele;
                heapSortArray.push_back(ele);
            }
            // To Sort Array using Heap Sort there are 3 steps involved in it 
            // 1 -> Insert All values in Array 
            // 2 -> Make that Array a Heap using Heapify Function 
            // 3 -> One by One delele element from Heap and insert into last of Array
            //      it Turns out to be Sorted 
            // Functions Used for Heap Sort -> makeArrayHeap()
            //                                  Heapify()
            //                                    popValueFromHeap()
            makeArrayHeap(heapSortArray);
        }
    }
    

}
