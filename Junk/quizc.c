#include<stdio.h>
int main(){
    int toBePaid = 0 , workerAlreadyHas = 0;
    int one = 1 , two = 1 ,  four = 1;
    for(int i = 1 ; i < 8 ; i++){
       // cout << "Day " << i  << " ";
        printf("Day %d  " ,i);
        toBePaid++;
        if(one == 1){
            workerAlreadyHas += 1;
            one = 0;
           // cout << "Give Chain One " << endl;
            printf("Give One Chain One \n");
        }else if(two == 1){
            workerAlreadyHas += 1;
            printf("Take One Chain Back and Give 2 \n");
           // cout << "Take One Chain Back and Give 2 " << endl;
            two = 0;
            one = 1;
        }else{
            workerAlreadyHas += 1;
          //  cout << "Take One and Two Chain Back and Give 4 Chain " << endl;
            printf("Take 1 and 2 Chain and give 4 chain \n");
            one = 1;
            two = 1;
            four = 0;
        }

    }
    return 0;
}