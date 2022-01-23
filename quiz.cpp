#include<iostream>
#include<vector>
using namespace std;
int main(){
    int toBePaid = 0 , workerAlreadyHas = 0;
    bool one = true , two = true ,  four = true;
    for(int i = 1 ; i <= 8 ; i++){
        cout << "Day " << i  << " ";
        toBePaid++;
        if(one){
            workerAlreadyHas += 1;
            one = false;
            cout << "Give Chain One " << endl;
        }else if(two){
            workerAlreadyHas += 1;
            cout << "Take One Chain Back and Give 2 " << endl;
            two = false;
            one = true;
        }else{
            workerAlreadyHas += 1;
            cout << "Take One and Two Chain Back and Give 4 Chain " << endl;
            one = true;
            two = true;
            four = false;
        }

    }
    
}