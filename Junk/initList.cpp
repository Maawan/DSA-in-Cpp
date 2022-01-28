#include<iostream>
#include<vector>
using namespace std;
class A{
    public:
    int health;
    // A(){
    //     health = 0;
    // }
    A(int x){
        this->health = x;
    }

};
class B : public A{
    int x;
    public:
    B():x(500){
        cout << this->health << " " <<  x << " " << endl;
    }
};
int main(){
    B a;
    return 0;
}