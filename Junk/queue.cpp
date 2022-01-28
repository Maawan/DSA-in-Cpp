#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> qu;
    qu.push(12);
    qu.push(43);
    qu.push(342);
    qu.push(785);
    for(int i = 0 ; i < qu.size() ; i++){
        cout << qu.pop() << endl;
    }
    return 0;
}